# Disk Scheduling Algorithms

## Metrics
- Seek time: head movement cost.
- Rotational latency: wait for desired sector under head.
- Transfer time: actual data movement.
- Throughput & fairness.

## Algorithms
| Algorithm | Movement Pattern | Notes |
| --- | --- | --- |
| FCFS | Service requests in arrival order | Fair but high average seek |
| SSTF | Pick request closest to current head | Minimizes immediate seek but can starve distant requests |
| SCAN (Elevator) | Move in one direction servicing requests, then reverse | Good throughput, biased towards middle cylinders |
| LOOK | Like SCAN but turns around at last request instead of disk end | Reduces unnecessary travel |
| C-SCAN | Move one direction servicing, then jump back without servicing | Uniform wait time |
| C-LOOK | C-SCAN but only traverses from lowest to highest request | Avoids traversing unused regions |
| N-step SCAN / F-SCAN | Partition request queue to improve fairness | Used in high-load systems |

## Visualization Tip
Always draw head position vs time. Example: Head at 50, pending [82, 170, 43, 140, 24, 16, 190]. Compare total head movement for SCAN vs C-SCAN to articulate fairness trade-offs.

## RAID Snapshot
- RAID0 striping: performance, no redundancy.
- RAID1 mirroring: redundancy, cost doubles.
- RAID5/6 parity: balance between cost and redundancy.

## Interview Prompts
- Which algorithm suits real-time workloads needing bounded service times? (C-SCAN for uniform service.)
- How do SSDs change disk scheduling considerations? (Seek ~0, scheduling focuses on queue depth/NCQ.)

## Placement Essentials
- Draw head-movement diagrams quickly and compute total seek distances.
- Explain why SCAN variants approximate fairness and how SSDs change the conversation (focus on queue depth, parallelism).
- Mention NCQ (Native Command Queuing) for SATA/NVMe and how OS schedulers interface with it.

## Python Demo — Compare Algorithms
```python
"""Compute total head movement for FCFS vs SCAN vs C-SCAN."""
requests = [82, 170, 43, 140, 24, 16, 190]
start = 50


def fcfs(reqs, start):
    movement = 0
    current = start
    for r in reqs:
        movement += abs(current - r)
        current = r
    return movement


def scan(reqs, start, direction=1, disk_size=199):
    reqs = sorted(reqs)
    left = [r for r in reqs if r < start]
    right = [r for r in reqs if r >= start]
    order = right + left[::-1] if direction == 1 else left[::-1] + right
    movement = 0
    current = start
    for r in order:
        movement += abs(current - r)
        current = r
    return movement

print("FCFS movement", fcfs(requests, start))
print("SCAN movement", scan(requests, start))
print("C-SCAN movement", scan(requests, start) + (199 - min(requests)))
```

Use results to argue for fairness vs minimal seek, and discuss modifications needed for SSDs (often merge requests and rely on device-level scheduling).
