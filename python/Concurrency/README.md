# Concurrency Patterns (Python)

Two classic LeetCode threading problems live in this folder. Both emphasise deterministic prints by coordinating multiple threads.

## Definitions

- Race conditions: the program ends with an undesired output, resulting from the sequence of execution among the processes.
- Deadlocks: the concurrent processes wait for some necessary resources from each other. As a result, none of them can make progress.
- Resource starvation: a process is perpetually denied necessary resources to progress its works.

## Problems covered
- `1114. Print in Order`
  - Uses two `Lock` instances to gate `second` and `third`.
  - KPI: release `firstJob` after printing, then `with self.firstJob` ensures `second` blocks until the lock is freed. Final lock controls `third`.
- `1115. Print FooBar Alternately`
  - Showcases five idiomatic synchronisation strategies: `Barrier`, `Condition`, `Event`, `Lock`, `Semaphore`.
  - Interview tip: earn bonus points by comparing memory footprint and fairness characteristics of each primitive.

## Synchronisation cheat sheet
- **Lock / RLock**
  - O(1) acquire/release; minimal overhead.
  - Great when you can express sequencing via "thread A releases so thread B can proceed".
- **Condition**
  - Built on a lock; supports precise waiting on predicates with `wait_for`.
  - Use for "while state != desired: wait" loops (e.g. counters or buffer sizes).
- **Barrier**
  - All parties block until the barrier is full; perfect for alternating output like FooBar.
- **Event**
  - Lightweight flag with `set()` / `clear()`; avoids busy wait.
  - Helps when signalling without needing mutual exclusion (FooBar example).
- **Semaphore**
  - Counting lock; `Semaphore(1)` is a mutex, higher counts gate resource pools.
  - Alternating prints: initialise one semaphore with 1 and the other with 0 to enforce order.

## Interview talking points
- Always mention what prevents **race conditions**, how you avoid **deadlocks**, and why starvation cannot happen.
- Call out that Python threads contend with the GIL, but ordering tests still need proper synchronisation.
- Provide a mental timeline demonstrating the release/acquire flow - interviewers love traceable reasoning.
