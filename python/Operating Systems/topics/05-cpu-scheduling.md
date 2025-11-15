# CPU Scheduling

## Evaluation Criteria
- CPU utilization
- Throughput
- Turnaround time
- Waiting time
- Response time
- Fairness/predictability for interactive workloads

## Dispatcher
Responsible for context switch, switching to user mode, jumping to correct PC. Keep dispatcher latency minimal.

## Scheduling Algorithms
| Algorithm | Preemptive? | Notes |
| --- | --- | --- |
| FCFS | No | Simple but suffers convoy effect |
| SJF | No | Optimal avg waiting; requires burst prediction |
| SRTF | Yes | Preemptive SJF; can starve long jobs |
| Round Robin | Yes | Time quantum critical; small quantum → overhead, large → FCFS |
| Priority | Either | Needs aging to prevent starvation |
| Multilevel Queue | Either | Separate queues for system/interactive/batch |
| Multilevel Feedback Queue | Yes | Processes move between queues based on behavior |
| HRRN | No | Highest response ratio next = (Waiting + Burst)/Burst |

## Burst Prediction
Use exponential averaging: `τ_(n+1) = α*t_n + (1-α)*τ_n` to estimate next CPU burst for SJF/SRTF.

## Practice Exercise
Given bursts [5, 2, 8] compute waiting/turnaround for FCFS, SJF, RR (q=2). Draw Gantt charts.

## Interview Prompts
- Explain how to select round-robin quantum for a web server.
- Contrast MLFQ vs fixed priority scheduling.

## Placement Essentials
- Prepare to compare algorithms using real metrics and discuss starvation prevention (aging, feedback levels).
- Mention Linux's Completely Fair Scheduler (CFS) as a modern example (red-black tree ordered by vruntime).
- Explain how time slices are chosen (based on interactive vs batch workloads).

## Python Demo — Mini Scheduler Simulator
```python
"""Simulate FCFS vs Round Robin to compute waiting and turnaround times."""
from collections import deque

processes = [
    {"pid": "P1", "burst": 5},
    {"pid": "P2", "burst": 2},
    {"pid": "P3", "burst": 8},
]

def fcfs(processes):
    time = 0
    waiting = {}
    for proc in processes:
        waiting[proc["pid"]] = time
        time += proc["burst"]
    return waiting


def round_robin(processes, quantum=2):
    queue = deque((proc["pid"], proc["burst"]) for proc in processes)
    time = 0
    waiting = {proc["pid"]: 0 for proc in processes}
    last_run = {proc["pid"]: 0 for proc in processes}
    remaining = {proc["pid"]: proc["burst"] for proc in processes}
    while queue:
        pid, _ = queue.popleft()
        waited = time - last_run[pid]
        waiting[pid] += waited
        slice_time = min(quantum, remaining[pid])
        remaining[pid] -= slice_time
        time += slice_time
        last_run[pid] = time
        if remaining[pid] > 0:
            queue.append((pid, remaining[pid]))
    return waiting

print("FCFS waiting times", fcfs(processes))
print("RR waiting times", round_robin(processes, quantum=2))
```

Explain how to compute turnaround = waiting + burst and discuss fairness differences between FCFS and Round Robin.
