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
