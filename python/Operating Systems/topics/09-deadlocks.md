# Deadlocks

## Coffman Conditions
Deadlock occurs only if all four hold simultaneously:
1. **Mutual exclusion:** non-shareable resources.
2. **Hold and wait:** processes hold resources while waiting for others.
3. **No preemption:** resources cannot be forcibly removed.
4. **Circular wait:** closed chain of processes each waiting on resource held by next.

## Resource-Allocation Graph (RAG)
- Processes = circles, resources = squares.
- Assignment edges (resource → process) and request edges (process → resource).
- Cycle + single-instance resource implies deadlock; with multiple instances need wait-for graph reduction.

## Handling Strategies
- **Prevention:** disallow one Coffman condition (e.g., order resources, require processes to request all resources at once).
- **Avoidance:** Banker’s algorithm checks safety before granting request by simulating allocation.
- **Detection & Recovery:** allow deadlocks, periodically detect using wait-for graph or matrix algorithms, then preempt/rollback/kill processes.
- **Ignore:** ostrich approach for general-purpose OS when probability is low.

## Banker’s Algorithm Outline
1. Data structures: `Available`, `Max`, `Allocation`, `Need`.
2. On request, ensure `Request <= Need` and `Request <= Available`.
3. Pretend to allocate; run safety algorithm to see if sequence exists.
4. Grant only if safe.

## Interview Prompts
- Differentiate deadlock, livelock, and starvation.
- Given matrices, run Banker's algorithm quickly.
- Describe OS-level strategies used by databases (wait-die, wound-wait).

## Placement Essentials
- Memorize the Coffman conditions and be ready to provide real-world examples (database locks, thread join ordering).
- Demonstrate detection using wait-for graphs and how to recover (terminate, rollback, resource preemption).
- Discuss OS vs DB strategies (timeouts vs wound-wait/wait-die) and how priority inheritance can mitigate priority inversion.

## Python Demo — Deadlock Scenario
```python
"""Trigger a simple deadlock using two locks acquired in different orders."""
import threading
import time

lock_a = threading.Lock()
lock_b = threading.Lock()

def task_one():
    with lock_a:
        time.sleep(0.1)
        with lock_b:
            print("Task one acquired both locks")

def task_two():
    with lock_b:
        time.sleep(0.1)
        with lock_a:
            print("Task two acquired both locks")

threading.Thread(target=task_one, daemon=True).start()
threading.Thread(target=task_two, daemon=True).start()

time.sleep(1)
print("Deadlock likely occurred")
```

Walk through how both threads hold one resource and wait for the other, satisfying all Coffman conditions. Explain strategies such as enforcing lock ordering to prevent this.
