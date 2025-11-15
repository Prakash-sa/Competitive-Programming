# Process Synchronization

## Why Synchronize?
Concurrent access to shared variables leads to race conditions where outcome depends on interleaving. Synchronization enforces deterministic behavior.

## Critical Section Requirements
1. **Mutual exclusion:** only one process in critical section.
2. **Progress:** choice of the next process can't be postponed indefinitely.
3. **Bounded waiting:** limit on number of times other processes enter before a waiting process gets a turn.

## Hardware Support
- Disable interrupts (uniprocessor only).
- Atomic instructions: test-and-set, compare-and-swap, fetch-and-add.
- Memory barriers to order reads/writes on multiprocessors.

## Software Tools
- **Mutex locks:** spinlocks for short sections, blocking mutex with futex/condition variable for longer ones.
- **Semaphores:** binary for mutual exclusion, counting for resource tracking.
- **Monitors:** language-level construct combining mutex + condition variables.
- **Condition variables:** wait/signal semantics (Mesa vs Hoare).

## Classical Algorithms
- Peterson's algorithm (two processes).
- Bakery algorithm (N processes with ticket numbers).

## Checklist
- Determine if given pseudo-code meets all three critical section requirements.
- Explain difference between busy waiting and blocking synchronization.
