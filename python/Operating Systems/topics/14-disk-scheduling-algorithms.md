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
