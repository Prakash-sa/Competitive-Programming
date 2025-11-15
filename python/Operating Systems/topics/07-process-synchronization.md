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

## Placement Essentials
- Always mention the three critical-section requirements and how chosen primitives satisfy them.
- Contrast busy-wait locks vs blocking locks; show when spinlocks are acceptable (short sections on SMP machines).
- Explain memory ordering rules (acquire/release semantics) and how they relate to hardware instructions.

## Python Demo — Race vs Lock
```python
"""Visualize race conditions by toggling locking."""
import threading

balance = 0
lock = threading.Lock()


def deposit(amount, iterations, use_lock=True):
    global balance
    for _ in range(iterations):
        if use_lock:
            with lock:
                _update(amount)
        else:
            _update(amount)

def _update(amount):
    global balance
    temp = balance
    temp += amount
    balance = temp

threads = [threading.Thread(target=deposit, args=(1, 1000, False)) for _ in range(5)]
for t in threads:
    t.start()
for t in threads:
    t.join()
print("Without lock", balance)

balance = 0
threads = [threading.Thread(target=deposit, args=(1, 1000, True)) for _ in range(5)]
for t in threads:
    t.start()
for t in threads:
    t.join()
print("With lock", balance)
```

Use the diverging totals to explain atomicity and why synchronization primitives are mandatory even for simple arithmetic.
