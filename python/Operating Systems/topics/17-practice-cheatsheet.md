# Practice Questions & Interview Cheat Sheet

## Core Questions
1. Distinguish between a process and a thread, including data each owns.
2. Define deadlock and strategies to prevent or detect it.
3. Compare paging vs segmentation and explain page fault handling.
4. Describe context switch internals and cost.
5. Walk through LRU page replacement on a reference string.
6. Explain semaphores vs mutexes with examples.
7. Discuss starvation vs deadlock vs livelock with scenarios.
8. Compare Multilevel Queue vs Multilevel Feedback Queue schedulers.

## Combined DSA + OS Mini Projects
- **LRU Cache:** Implement using ordered dict/linked list + hashmap.
- **Thread-safe queue:** Use mutex + condition variables to implement blocking enqueue/dequeue.
- **Producer–Consumer simulation:** Show correctness with logging and bounded buffer.
- **Round-robin scheduler simulator:** Manage PCB objects and time quantum, gather stats.

## Revision Routine
| Day | Focus | Activities |
| --- | --- | --- |
| 1 | Processes, Threads, Scheduling | Solve 3 Gantt chart problems, explain `fork` trees |
| 2 | Synchronization & Semaphores | Implement reader-writer & dining philosopher variants |
| 3 | Memory Management | Compute EMAT, run replacement algorithms |
| 4 | Filesystems & I/O | Trace `read()` path, compare FS allocation methods |

## Interview Tips
- Always mention trade-offs (e.g., LRU accuracy vs overhead).
- Tie theory back to practical debugging stories (e.g., how you diagnosed thrashing using `vmstat`).
- For coding rounds, favor clean synchronization primitives over ad-hoc busy waiting.

## Additional Resources
- Silberschatz, Galvin, Gagne — *Operating System Concepts*.
- Tanenbaum — *Modern Operating Systems*.
- MIT 6.S081 / xv6 labs for kernel practice.
- Linux `man` pages (`man 2 intro`, `man 2 syscalls`, `man 7 signal`).
