# Threads & Multithreading

## What is a Thread?
The smallest sequence of programmed instructions that the scheduler can dispatch. Threads share code/data/heap but maintain their own stack and registers (TCB).

## Advantages
- Faster context switches than processes.
- Responsiveness (UI thread spawns workers).
- Resource sharing across tasks (cache locality, shared memory).
- Better utilization of multicore hardware.

## Thread Models
| Model | Mapping | Pros | Cons |
| --- | --- | --- | --- |
| Many-to-One | Many user threads multiplexed onto single kernel thread | Ultra-fast switching | One blocking syscall blocks entire process; no parallelism |
| One-to-One | Each user thread is a kernel thread | True parallelism, OS scheduling | Higher overhead, thread count limited |
| Many-to-Many / Two-Level | User threads mapped onto smaller pool of kernel threads | Balance of flexibility & efficiency | Complexity in runtime library |

## Issues to Remember
- Thread creation and destruction cost.
- Signal delivery semantics (which thread handles a signal?).
- Thread cancellation (asynchronous vs deferred).
- Thread-local storage for per-thread data.

## Pthreads Mini-Example
```c
void* worker(void* arg) {
    // work here
    return NULL;
}
int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, worker, NULL);
    pthread_join(tid, NULL);
}
```

## Interview Prompts
- Differentiate mutex vs semaphore in the context of multithreading.
- Explain how a blocking I/O syscall affects user-level threading libraries.

## Placement Essentials
- Expect to explain user vs kernel threads, blocking syscalls, and how thread pools amortize creation overhead.
- Discuss how OSes store per-thread metadata (TCB, TLS, stack) and how scheduling differs between threads and processes.
- Call out issues like false sharing, cache locality, and GIL (in CPython) when writing multi-threaded code.

## Python Demo — Thread Synchronization
```python
"""Show how Python threads share memory and coordinate with Locks."""
import threading
import time

counter = 0
lock = threading.Lock()


def increment_worker(iterations: int):
    global counter
    for _ in range(iterations):
        with lock:  # ensures mutual exclusion
            counter += 1
            # simulate work
            time.sleep(0.0001)

threads = [threading.Thread(target=increment_worker, args=(50,)) for _ in range(4)]
for t in threads:
    t.start()
for t in threads:
    t.join()

print(f"Final counter = {counter}")
```

Use this snippet to talk through race conditions, Python's GIL, and why you still need locks to guard non-atomic operations even in high-level languages.
