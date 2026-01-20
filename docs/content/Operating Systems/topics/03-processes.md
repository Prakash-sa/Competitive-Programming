# Processes

## Definition & Components
A process is a program in execution with its own logical address space consisting of text, data, heap, and stack segments plus registers and kernel bookkeeping.

## Process Control Block (PCB)
- PID / PPID
- Program counter & CPU registers
- Scheduling state and priority
- Memory limits (base/limit, page table pointer)
- Open file descriptors, signal masks
- Accounting and runtime statistics

## State Model
```
New → Ready → Running → Waiting/Blocked → Ready → Terminated
```
Some OSes extend this with Suspended states when swapped to disk.

## Context Switching
Triggered by interrupts, traps, or scheduler decisions. Requires saving current PCB, loading next, invalidating/refreshing caches/TLB. Minimizing switch overhead improves throughput.

## Creation & Termination
- `fork` creates child process via copy-on-write duplication of parent address space.
- `exec` overlays the process memory with a new program image.
- `wait` allows parent to collect child exit status.
- Processes terminate on completion, error, or signal.

## CPU vs I/O Burst
Schedulers rely on burst profiles to select algorithms (I/O-bound vs CPU-bound). Understanding bursts helps reason about context switches and fairness.

## Checklist
- Trace a `fork` tree and predict output ordering.
- Identify what resources are inherited vs duplicated.
- Explain zombie vs orphan process scenarios.

## Placement Essentials
- Be ready to whiteboard the full process state diagram and explain each transition trigger (interrupt, I/O completion, scheduler preemption).
- Discuss PCB fields that matter for context switching (register set, stack pointer, page table base) and how Linux stores them (`task_struct`).
- Mention common metrics: context-switch time, process creation cost, zombie/orphan cleanup.

## Python Demo — Multiprocessing Basics
```python
"""Use multiprocessing to mimic process creation and IPC via queues."""
import multiprocessing as mp

def worker(queue: mp.Queue):
    queue.put((mp.current_process().name, os.getpid()))

if __name__ == "__main__":
    import os
    message_queue = mp.Queue()
    processes = [mp.Process(target=worker, args=(message_queue,), name=f"worker-{i}") for i in range(3)]
    for proc in processes:
        proc.start()
    for proc in processes:
        proc.join()
    while not message_queue.empty():
        name, pid = message_queue.get()
        print(f"{name} ran as PID {pid}")
```

Explain how the `multiprocessing` module spawns OS processes, each with its own PID and address space, and how queues rely on pipes + serialization.
