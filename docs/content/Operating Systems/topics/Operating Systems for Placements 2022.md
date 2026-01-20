# Operating Systems for Placements 2022 — Companion Notes

*Structured from the CodeHelp by Love Babbar playlist. This file mirrors the content that lives inside `README.md` so you can study each topic without digging through the long chat transcript.*

## Table of Contents
1. [Introduction to Operating Systems](#1-introduction-to-operating-systems)
2. [System Calls & OS Structure](#2-system-calls--os-structure)
3. [Processes](#3-processes)
4. [Threads & Multithreading](#4-threads--multithreading)
5. [CPU Scheduling](#5-cpu-scheduling)
6. [Inter-Process Communication](#6-inter-process-communication)
7. [Process Synchronization](#7-process-synchronization)
8. [Semaphores & Classical Problems](#8-semaphores--classical-problems)
9. [Deadlocks](#9-deadlocks)
10. [Memory Management](#10-memory-management)
11. [Paging, Segmentation & TLB](#11-paging-segmentation--tlb)
12. [Virtual Memory & Page Replacement](#12-virtual-memory--page-replacement)
13. [File Systems](#13-file-systems)
14. [Disk Scheduling Algorithms](#14-disk-scheduling-algorithms)
15. [I/O Systems](#15-io-systems)
16. [Linux & System Programming Basics](#16-linux--system-programming-basics)
17. [Practice Questions & Interview Cheat Sheet](#17-practice-questions--interview-cheat-sheet)

---

## 1. Introduction to Operating Systems
- **Definition:** intermediary between user programs and hardware, delivering resource abstraction and protection.
- **Major functions:** process, memory, file, I/O, device, security, accounting, error detection.
- **Types:** batch, time-sharing, distributed, network, mobile, real-time (hard vs soft deadlines).
- **Kernel styles:** monolithic (Linux), microkernel (Minix), hybrid (Windows/macOS).
- **Key takeaways:** sketch user vs kernel mode boundary; know kernel responsibilities.

## 2. System Calls & OS Structure
- **System calls:** process control (`fork`, `exec`, `wait`, `exit`), file management (`open`, `read`, `write`, `close`), device management, info maintenance, communication (`pipe`, `socket`).
- **Call flow:** user code → library wrapper → trap/syscall instruction → kernel handler → return.
- **OS organizations:** simple, layered, microkernel, modules, virtual machines.
- **Sample pseudo code:**
```c
if (fork() == 0) {
    execl("/bin/ls", "ls", NULL);
}
```

## 3. Processes
- **Process =** program in execution with its own code, data, heap, stack.
- **PCB (process control block):** PID, program counter, CPU registers, scheduling data, memory limits, I/O status.
- **States:** New → Ready → Running → Waiting → Ready → Terminated; context switch saves current PCB, loads next.
- **Know:** parent/child relationships, copy-on-write after `fork`, how `wait` collects exit status.

## 4. Threads & Multithreading
- **Thread:** lightweight unit sharing process address space.
- **Advantages:** faster context switches, better CPU utilization, responsiveness.
- **Models:** many-to-one, one-to-one, many-to-many (two-level). Understand blocking behaviors per model.

## 5. CPU Scheduling
- **Criteria:** throughput, turnaround, waiting, response, CPU utilization.
- **Algorithms:** FCFS, SJF, SRTF, Round Robin (time quantum design), Priority (need aging), Multilevel Queue, Multilevel Feedback Queue.
- **Tips:** draw Gantt charts to compute waiting/turnaround; understand dispatcher latency.

## 6. Inter-Process Communication
- **Mechanisms:** shared memory, message passing, anonymous/named pipes, sockets, FIFOs.
- **Producer–consumer:** combine shared memory with semaphores to synchronize buffer usage.

## 7. Process Synchronization
- **Purpose:** avoid race conditions.
- **Critical section requirements:** mutual exclusion, progress, bounded waiting.
- **Solutions:** Peterson’s algorithm, mutex locks, semaphores, monitors.

## 8. Semaphores & Classical Problems
- **Semaphores:** binary vs counting; `wait(S); ...; signal(S);`.
- **Classics:** bounded buffer, readers–writers, dining philosophers, sleeping barber. Practice writing semaphore-based solutions.

## 9. Deadlocks
- **Necessary conditions (Coffman):** mutual exclusion, hold & wait, no preemption, circular wait.
- **Handling:** prevention (break conditions), avoidance (Banker’s), detection & recovery.
- **Banker’s algorithm:** ensure requests leave system in safe state by simulating allocation.

## 10. Memory Management
- **Techniques:** contiguous allocation, paging, segmentation, swapping.
- **Fragmentation:** internal vs external and how paging eliminates external fragmentation.

## 11. Paging, Segmentation & TLB
- **Paging:** logical address translated via page table to frames; no external fragmentation.
- **TLB:** caches recent translations to reduce access time.
- **Segmentation:** memory divided into variable-sized segments; better logical grouping.

## 12. Virtual Memory & Page Replacement
- **Virtual memory:** enables programs larger than physical RAM.
- **Page replacement:** FIFO, Optimal, LRU, LFU, Clock/Second Chance.

## 13. File Systems
- **Attributes:** name, type, size, location, protection.
- **Directories:** single, two-level, trees, DAGs, general graphs.
- **Allocation:** contiguous, linked, indexed (e.g., inodes).

## 14. Disk Scheduling Algorithms
- **Algorithms:** FCFS, SSTF, SCAN, CSCAN, LOOK, CLOOK.
- **Goal:** minimize seek time and improve throughput.

## 15. I/O Systems
- **Components:** device drivers, interrupts, DMA, caching, buffering, spooling.

## 16. Linux & System Programming Basics
- **Commands:** `ps`, `top`, `htop`, `nice`, `renice`, `kill`, `ls`, `chmod`, `chown`, `cat`.
- **Syscalls:** `fork`, `exec`, `wait`, `pipe`, `dup2` for pipelines; `ps`/`top` monitoring.

## 17. Practice Questions & Interview Cheat Sheet
- **Common questions:** difference between process/thread, deadlock/starvation, paging vs segmentation, LRU handling, semaphores vs mutexes.
- **Mini projects:** implement LRU cache, thread-safe queue, producer-consumer, round-robin simulator.
- **DSA + OS combos:** combine concurrency primitives with data structure implementations.

> Continue adding lecture-specific sections here. You can expand each heading with diagrams, proofs, formula derivations, and sample problems as you progress through the playlist.
