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
