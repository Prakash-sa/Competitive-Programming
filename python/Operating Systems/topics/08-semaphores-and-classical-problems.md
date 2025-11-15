# Semaphores & Classical Synchronization Problems

## Semaphore Basics
A semaphore `S` maintains an integer counter with atomic operations:
```c
wait(S) {
    S--;
    if (S < 0) block current process;
}
signal(S) {
    S++;
    if (S <= 0) wake one blocked process;
}
```
- **Binary semaphore (mutex):** counter ∈ {0,1}, enforces mutual exclusion.
- **Counting semaphore:** tracks multiple instances of a resource (buffer slots, connections).

## Canonical Problems
1. **Bounded Buffer / Producer–Consumer**
   - Semaphores: `mutex`, `empty`, `full`.
   - Guarantee that producers don't overfill and consumers don't underflow.
2. **Readers–Writers**
   - Reader-preference: allow multiple readers, single writer; risk writer starvation.
   - Writer-preference or fair solutions use additional semaphores/turnstiles.
3. **Dining Philosophers**
   - Avoid deadlock by limiting concurrency (allow max 4 philosophers), imposing resource ordering, or using a waiter process.
4. **Sleeping Barber**
   - Semaphores for `customers`, `barber`, `mutex` to coordinate waiting room chairs, sleeping/waking behavior.

## Interview Practice
- Modify readers–writers for fairness.
- Argue how semaphore misuse can cause deadlock or starvation.
- Show how to convert semaphore solutions to monitor/condition-variable implementations.

## Placement Essentials
- Be fluent in converting semaphore solutions into monitor/condition-variable versions and vice versa.
- Show how to reason about ordering (who signals whom), fairness, and starvation.
- Mention pitfalls: forgetting to signal, using binary semaphore with wrong initial count, or holding locks while blocking.

## Python Demo — Bounded Buffer with Semaphore
```python
"""Implement producer-consumer using threading.Semaphore."""
import threading
from collections import deque

BUFFER_SIZE = 3
buffer = deque()
mutex = threading.Lock()
empty = threading.Semaphore(BUFFER_SIZE)
full = threading.Semaphore(0)


def producer(n):
    for item in range(n):
        empty.acquire()
        with mutex:
            buffer.append(item)
            print(f"Produced {item}")
        full.release()

def consumer(n):
    for _ in range(n):
        full.acquire()
        with mutex:
            item = buffer.popleft()
            print(f"Consumed {item}")
        empty.release()

threads = [threading.Thread(target=producer, args=(5,)), threading.Thread(target=consumer, args=(5,))]
for t in threads:
    t.start()
for t in threads:
    t.join()
```

Explain how semaphores guard counts (`empty`, `full`) and how the mutex protects the critical section around the shared deque.
