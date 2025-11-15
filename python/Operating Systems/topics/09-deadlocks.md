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
