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
