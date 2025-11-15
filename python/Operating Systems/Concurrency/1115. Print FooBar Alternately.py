# https://leetcode.com/problems/print-foobar-alternately/description/

'''
Suppose you are given the following code:
class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:
thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

Example 1:
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.
Example 2:
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.

Constraints:
1 <= n <= 1000
'''


# 5 Python threading solutions (Barrier, Event, Condition, Lock, Semaphore) with explanation

'''
Raise a barrier which makes both threads wait for each other before they are allowed to continue. 
foo prints before reaching the barrier. bar prints after reaching the barrier.
'''

from threading import Barrier
from typing import Callable

class FooBar:
    def __init__(self, n):
        self.n = n
        self.barrier=Barrier(2)

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            printFoo()
            self.barrier.wait()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.barrier.wait()
            printBar()

'''
Count the number of times foo and bar was printed and only print foo if the number of times is equal. 
bar prints if foo was printed fewer times. Use Condition and wait_for to syncrhonize the threads.
'''

from threading import Condition

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_counter=0
        self.bar_counter=0
        self.condition=Condition()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.condition:
                self.condition.wait_for(lambda: self.foo_counter==self.bar_counter)
                printFoo()
                self.foo_counter+=1
                self.condition.notify(1)

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.condition:
                self.condition.wait_for(lambda: self.foo_counter>self.bar_counter)
                printBar()
                self.bar_counter+=1
                self.condition.notify(1)



'''
Each thread can wait on each other to set their corresponding foo_printed and bar_printed events. 
Each thread also resets the corresponding printed events with .clear() for the next loop iteration.
'''
from threading import Event

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_printed=Event()
        self.bar_printed=Event()
        self.bar_printed.set()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.bar_printed.wait()
            self.bar_printed.clear()
            printFoo()
            self.foo_printed.set()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.foo_printed.wait()
            self.foo_printed.clear()
            printBar()
            self.bar_printed.set()


'''
Use two locks for the threads to signal to each other when the other should run. 
bar_lock starts in a locked state because we always want foo to print first.
'''

from threading import Lock

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_lock=Lock()
        self.bar_lock=Lock()
        self.bar_lock.acquire()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.foo_lock.acquire()
            printFoo()
            self.bar_lock.release()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.bar_lock.acquire()
            printBar()
            self.foo_lock.release()



'''
Use two Semaphores just as we used two locks. 
The foo_gate semaphore starts with a value of 1 because we want foo to print first.
'''

from threading import Semaphore

class FooBar:
    def __init__(self, n):
        self.n = n
        self.foo_gate=Semaphore(1)
        self.bar_gate=Semaphore(0)

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.foo_gate.acquire()
            printFoo()
            self.bar_gate.release()

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.bar_gate.acquire()
            printBar()
            self.foo_gate.release()

