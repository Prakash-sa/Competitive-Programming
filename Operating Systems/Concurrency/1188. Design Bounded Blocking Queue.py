# https://leetcode.com/problems/design-bounded-blocking-queue/description/?envType=problem-list-v2&envId=concurrency


'''
Implement a thread-safe bounded blocking queue that has the following methods:

BoundedBlockingQueue(int capacity) The constructor initializes the queue with a maximum capacity.
void enqueue(int element) Adds an element to the front of the queue. If the queue is full, the calling thread is blocked until the queue is no longer full.
int dequeue() Returns the element at the rear of the queue and removes it. If the queue is empty, the calling thread is blocked until the queue is no longer empty.
int size() Returns the number of elements currently in the queue.
Your implementation will be tested using multiple threads at the same time. Each thread will either be a producer thread that only makes calls to the enqueue method or a consumer thread that only makes calls to the dequeue method. The size method will be called after every test case.

Please do not use built-in implementations of bounded blocking queue as this will not be accepted in an interview.

 

Example 1:

Input:
1
1
["BoundedBlockingQueue","enqueue","dequeue","dequeue","enqueue","enqueue","enqueue","enqueue","dequeue"]
[[2],[1],[],[],[0],[2],[3],[4],[]]

Output:
[1,0,2,2]

Explanation:
Number of producer threads = 1
Number of consumer threads = 1

BoundedBlockingQueue queue = new BoundedBlockingQueue(2);   // initialize the queue with capacity = 2.

queue.enqueue(1);   // The producer thread enqueues 1 to the queue.
queue.dequeue();    // The consumer thread calls dequeue and returns 1 from the queue.
queue.dequeue();    // Since the queue is empty, the consumer thread is blocked.
queue.enqueue(0);   // The producer thread enqueues 0 to the queue. The consumer thread is unblocked and returns 0 from the queue.
queue.enqueue(2);   // The producer thread enqueues 2 to the queue.
queue.enqueue(3);   // The producer thread enqueues 3 to the queue.
queue.enqueue(4);   // The producer thread is blocked because the queue's capacity (2) is reached.
queue.dequeue();    // The consumer thread returns 2 from the queue. The producer thread is unblocked and enqueues 4 to the queue.
queue.size();       // 2 elements remaining in the queue. size() is always called at the end of each test case.
Example 2:

Input:
3
4
["BoundedBlockingQueue","enqueue","enqueue","enqueue","dequeue","dequeue","dequeue","enqueue"]
[[3],[1],[0],[2],[],[],[],[3]]
Output:
[1,0,2,1]

Explanation:
Number of producer threads = 3
Number of consumer threads = 4

BoundedBlockingQueue queue = new BoundedBlockingQueue(3);   // initialize the queue with capacity = 3.

queue.enqueue(1);   // Producer thread P1 enqueues 1 to the queue.
queue.enqueue(0);   // Producer thread P2 enqueues 0 to the queue.
queue.enqueue(2);   // Producer thread P3 enqueues 2 to the queue.
queue.dequeue();    // Consumer thread C1 calls dequeue.
queue.dequeue();    // Consumer thread C2 calls dequeue.
queue.dequeue();    // Consumer thread C3 calls dequeue.
queue.enqueue(3);   // One of the producer threads enqueues 3 to the queue.
queue.size();       // 1 element remaining in the queue.

Since the number of threads for producer/consumer is greater than 1, we do not know how the threads will be scheduled in the operating system, even though the input seems to imply the ordering. Therefore, any of the output [1,0,2] or [1,2,0] or [0,1,2] or [0,2,1] or [2,0,1] or [2,1,0] will be accepted.
 

Constraints:

1 <= Number of Prdoucers <= 8
1 <= Number of Consumers <= 8
1 <= size <= 30
0 <= element <= 20
The number of calls to enqueue is greater than or equal to the number of calls to dequeue.
At most 40 calls will be made to enque, deque, and size.
'''

# Simple implementation with 2 locks

from collections import deque
from threading import Lock

class BoundedBlockingQueue(object):

    def __init__(self, capacity: int):
        self.en, self.de = Lock(), Lock()
        self.q = deque()
        self.capacity = capacity
        self.de.acquire()

    def enqueue(self, element: int) -> None:
        self.en.acquire()
        self.q.append(element)
        if len(self.q) < self.capacity:
            self.en.release()
        if self.de.locked():
            self.de.release()

    def dequeue(self) -> int:
        self.de.acquire()
        val = self.q.popleft()
        if len(self.q):
            self.de.release()
        if self.en.locked():
            self.en.release()
        return val
        
    def size(self) -> int:
        return len(self.q)
	
# Simple implementation with Condition

from collections import deque
from threading import Condition

class BoundedBlockingQueue(object):

    def __init__(self, capacity: int):
        self.c = Condition()
        self.q = deque()
        self.capacity = capacity

    def enqueue(self, element: int) -> None:
        with self.c:
            self.c.wait_for(lambda: len(self.q) < self.capacity)
            self.q.append(element)
            self.c.notify_all()

    def dequeue(self) -> int:
        with self.c:
            self.c.wait_for(lambda: len(self.q) > 0)
            val = self.q.popleft()
            self.c.notify_all()
            return val
        
    def size(self) -> int:
        return len(self.q)

'''
### Single Condition Variable, Fairness & Starvation

A naive solution to the producer–consumer problem uses **one lock and one condition variable** for both producers and consumers. 
After each operation, threads call `notify_all()`.
Although this can pass LeetCode, it has a major issue: **fairness and starvation**.
When `notify_all()` wakes every waiting thread, they all compete to acquire the lock again. The next thread that runs is determined by scheduling luck rather than the order in which threads started waiting.
For example, if producers `t1, t5` and consumers `t3, t4` are waiting, and a consumer frees space in the queue, ideally **`t1` (the earliest producer)** should run next. Instead, any thread may win the race, which can delay others and potentially cause starvation.

### Proper Approach
The problem occurs because **one condition variable is used for two different conditions**:
* Queue **not empty**
* Queue **not full**

A better design uses **two condition variables sharing the same lock**:
* **Producers** wait on `not_full`, enqueue, then `notify()` `not_empty`
* **Consumers** wait on `not_empty`, dequeue, then `notify()` `not_full`

This avoids unnecessary wakeups, reduces contention, and leads to a more fair and efficient synchronization design.
'''


from threading import Lock, Condition

class BoundedBlockingQueue(object):
    def __init__(self, capacity: int):
        self.cap = capacity
        self.q = deque()
        self.lock = Lock()
        # q_full blocks if the queue is full
        self.q_full = Condition(self.lock)
        # q_empty blocks if the queue is empty
        self.q_empty = Condition(self.lock)

    def enqueue(self, element: int) -> None:
        with self.q_full:
            self.q_full.wait_for(lambda: len(self.q) < self.cap)
            self.q.append(element)
            self.q_empty.notify()
        
    def dequeue(self) -> int:
        with self.q_empty:
            self.q_empty.wait_for(lambda: len(self.q) > 0)
            res = self.q.popleft()
            self.q_full.notify()
            return res

    def size(self) -> int:
        with self.lock:
            return len(self.q)