# Concurrency Patterns (Python)

This folder collects classic LeetCode concurrency problems and the synchronization ideas behind them. The goal in most of these questions is not parallel speedup, but deterministic coordination between threads.

## Core Terms

- Race condition: program correctness depends on thread scheduling, so different interleavings can produce different results.
- Deadlock: two or more threads wait forever because each is blocked on something another thread must release.
- Starvation: a thread is repeatedly denied a chance to run even though the program as a whole keeps making progress.
- Mutual exclusion: only one thread can access a critical section at a time.
- Blocking: a thread sleeps until some condition becomes true instead of busy-waiting.

## Problems in This Folder

### `1114. Print in Order`

**Challenge:** Three threads call `first()`, `second()`, `third()` in arbitrary order. Output must always be `"firstsecondthird"`.

**Approach (Lock):** Two locks start acquired. `first()` runs freely and releases lock 1. `second()` blocks on lock 1, then releases lock 2. `third()` blocks on lock 2.

**Key insight:** A pre-acquired `Lock` acts like a `Semaphore(0)` — the thread that calls `acquire()` blocks until another thread calls `release()`. This creates a one-shot gate.

**Pattern:** Ordered execution (chained gates)

---

### `1115. Print FooBar Alternately`

**Challenge:** Two threads must alternate printing `"foo"` and `"bar"` for `n` rounds.

**Approaches (5 solutions):**
1. **Barrier** — `foo` prints before the barrier, `bar` prints after. Both meet at the barrier each round.
2. **Condition** — Count `foo_counter` and `bar_counter`. `foo` waits until counts are equal; `bar` waits until `foo` is ahead by one.
3. **Event** — Two events (`foo_printed`, `bar_printed`). Each thread waits on the other's event, then clears it for the next round.
4. **Lock** — Two locks ping-pong control: `foo` acquires `foo_lock`, releases `bar_lock`; `bar` does the reverse.
5. **Semaphore** — Same idea as Lock but with `Semaphore(1)` and `Semaphore(0)`.

**Key insight:** Alternation = two-phase handoff. Any primitive that can express "wait for the other side" works. `Semaphore` and `Lock` are the cleanest; `Barrier` is the most symmetric.

**Pattern:** Ordered execution (ping-pong)

---

### `1116. Print Zero Even Odd`

**Challenge:** Three threads must produce `"0102030405..."`. Thread A prints all zeros, thread B prints even numbers, thread C prints odd numbers.

**Approach (Lock):** Three locks. `zero_lock` starts unlocked; `even_lock` and `odd_lock` start acquired. After printing `0`, the zero thread checks `last_count % 2` to decide which lock to release next. Even/odd threads release `zero_lock` after printing.

**Key insight:** The zero thread is the dispatcher — it decides who goes next based on shared state (`last_count`). The pattern is `zero -> odd/even -> zero -> odd/even`, strictly serialized.

**Complexity:** O(n) time, O(1) space.

**Pattern:** Ordered execution (dispatcher)

---

### `1117. Building H2O`

**Challenge:** Hydrogen and oxygen threads arrive in arbitrary order. They must bond in groups of exactly 2H + 1O before any thread from the next molecule can proceed.

**Approaches (2 solutions):**
1. **Lock + counting** — `h_lock` gates hydrogen arrivals. A counter tracks how many H have arrived. After 2 hydrogens, `o_lock` is released. Oxygen resets the counter and re-opens `h_lock`.
2. **Semaphore + Barrier** — `Semaphore(2)` admits at most 2 hydrogens, `Semaphore(1)` admits 1 oxygen. A `Barrier(3)` ensures all three arrive before any proceeds. Semaphores are released via context manager after the barrier.

**Key insight:** The problem has two sub-problems: *admission control* (right ratio) and *group synchronization* (leave together). Semaphore solves the first, Barrier solves the second.

**Pattern:** Group formation / batching

---

### `1188. Design Bounded Blocking Queue`

**Challenge:** Implement a thread-safe queue with fixed capacity. `enqueue` blocks when full, `dequeue` blocks when empty. Multiple producers and consumers run concurrently.

**Approaches (3 solutions):**
1. **Two Locks** — `en` lock gates producers, `de` lock gates consumers. Each side conditionally releases its own lock (if space/items remain) and unblocks the other side.
2. **Single Condition** — `wait_for` with lambda predicates. Simple but uses `notify_all()`, causing unnecessary wakeups.
3. **Two Conditions (recommended)** — One lock shared by `not_full` and `not_empty` conditions. Producers wait on `not_full` and signal `not_empty`; consumers do the reverse. This avoids waking the wrong side.

**Key insight:** One condition variable for two different predicates (not-full vs not-empty) causes *thundering herd* — all waiters wake up but only one side can proceed. Two conditions targeting the right waiter pool fix this.

**Pitfall in Lock approach:** `if val and self.en.locked()` would silently skip releasing the enqueue lock when `val=0`, since `0` is falsy. Always use `if self.en.locked()`.

**Pattern:** Producer-consumer with bounded capacity

---

### `1195. Fizz Buzz Multithreaded`

**Challenge:** Four threads handle `fizz`, `buzz`, `fizzbuzz`, and plain numbers respectively. They must cooperate to produce the correct FizzBuzz sequence for `1..n`.

**Approaches (5 solutions):**
1. **Lock** — Four locks, one per thread. A shared `release_lock()` dispatcher inspects `cur % 3/5/15` and releases the right lock. Each thread pre-computes its iteration count.
2. **Condition** — Single condition variable. Each thread's `wait_for` lambda encodes its divisibility rule. Simple and readable.
3. **Event** — Four events. After each print, a `set_flag()` dispatcher sets the correct event for the next number.
4. **Barrier** — All 4 threads iterate `1..n` together. Each checks its own condition and only the matching thread prints. Barrier keeps them in sync. Runs more iterations but is the simplest.

**Key insight:** This is `1116` generalized to 4 threads. The core pattern is the same: one dispatcher decides who prints next based on divisibility. The `Barrier` approach is unique — it trades efficiency for simplicity by having every thread iterate every number.

**Pattern:** Ordered execution (dispatcher, 4-way)

---

### `1226. The Dining Philosophers`

**Challenge:** Five philosophers share five forks arranged in a circle. Each needs both adjacent forks to eat. Naive solutions deadlock when all grab their left fork simultaneously.

**Approach (Semaphore + Lock):** Model each fork as a `Lock`. Use a `Semaphore(4)` to limit concurrency — at most 4 philosophers can attempt to eat at once. This guarantees at least one philosopher finds both forks free, breaking circular wait.

**Why Semaphore(4):** If all 5 try simultaneously, each grabs one fork and waits for the other — classic circular deadlock. Allowing only 4 means at least one seat is empty, so its neighbor can always grab both forks.

**Alternative strategies:**
- Lock ordering: philosopher `i` always picks up `min(left, right)` first
- Arbitrator: a global lock that serializes fork pickup (correct but low concurrency)

**Complexity:** O(1) per eat attempt. O(1) space (5 locks + 1 semaphore).

**Pattern:** Resource allocation without deadlock

---

### `1242. Web Crawler Multithreaded`

**Challenge:** Crawl all URLs under the same hostname as `startUrl`, using multiple threads. `getUrls()` is a blocking HTTP call — single-threaded solutions TLE.

**Approaches (2 solutions):**
1. **Thread per batch** — BFS loop: drain the queue into a batch, spawn one `Thread` per URL, join all, repeat. A shared `Lock` protects the visited set and queue.
2. **ThreadPoolExecutor** — Same BFS structure but uses a pool of 10 workers via `executor.submit()`. Avoids creating/destroying threads each round.

**Key insight:** The parallelism is in the I/O (`getUrls` calls), not computation. BFS levels naturally batch independent work. The lock only protects the shared queue and visited set — the actual HTTP calls run without holding the lock.

**Follow-up (distributed):** Partition URLs by hostname hash across nodes. Use consistent hashing for rebalancing. Heartbeats detect node failure. A coordinator tracks crawl completion via pending-work counters.

**Pattern:** Parallel work queue

## Mental Model

For each problem, answer these four questions first:

1. What is the shared state?
2. Which thread is allowed to run now?
3. Which threads must block?
4. Which action wakes the next thread?

Most solutions reduce to:

`shared state + synchronization primitive + wait condition + signal`

## Python Primitives Cheat Sheet

### `Lock`

Use when you only need mutual exclusion.

```python
from threading import Lock

self.lock = Lock()

with self.lock:
    # critical section
```

Good for protecting shared data, but by itself it does not express rich wait conditions.

### `Condition`

Use when threads must wait until some predicate becomes true.

```python
from threading import Condition

self.cv = Condition()

with self.cv:
    while not condition:
        self.cv.wait()
    # do work
    update_state()
    self.cv.notify_all()
```

Rules:

- Always guard `wait()` with `while`, not `if`.
- Keep the predicate tied to shared state.
- Prefer `notify()` over `notify_all()` when exactly one waiting side should proceed.

### `Semaphore`

Use when permits represent turns or available resources.

```python
from threading import Semaphore

self.s1 = Semaphore(1)
self.s2 = Semaphore(0)

self.s1.acquire()
# do work
self.s2.release()
```

This is often the cleanest primitive for strict ordering problems.

### `Barrier`

Use when a fixed number of threads must arrive before any of them can continue.

```python
from threading import Barrier

self.barrier = Barrier(3)
self.barrier.wait()
```

Useful for grouped release problems such as `Building H2O`.

### `Event`

Use for one-bit signaling.

```python
from threading import Event

self.ready = Event()
self.ready.wait()
self.ready.set()
```

Simple, but less expressive than `Condition` when multiple states are involved.

## Pattern Summary

| # | Pattern | Problems | Go-to primitive |
|---|---------|----------|-----------------|
| 1 | Ordered execution | `1114`, `1115`, `1116`, `1195` | `Semaphore` chain or `Condition + turn` |
| 2 | Producer-consumer | `1188` | `Lock` + two `Condition`s (`not_full`, `not_empty`) |
| 3 | Group formation / batching | `1117` | `Semaphore` for admission + `Barrier` for sync |
| 4 | Resource allocation (deadlock-free) | `1226` | `Lock` per resource + `Semaphore` to limit concurrency |
| 5 | Parallel work queue | `1242` | `Lock`-protected shared set + `Thread`/`ThreadPoolExecutor` |

### 1. Ordered execution

**Template (Condition + turn):**

```python
from threading import Condition

class Solution:
    def __init__(self):
        self.cv = Condition()
        self.turn = 0

    def first(self, printFirst):
        with self.cv:
            while self.turn != 0:
                self.cv.wait()
            printFirst()
            self.turn = 1
            self.cv.notify_all()
```

**Template (Semaphore chain):**

```python
from threading import Semaphore

# gate starts closed (0) — thread blocks until the previous stage releases it
self.gate_second = Semaphore(0)
self.gate_third = Semaphore(0)
```

**Variants:**
- **Ping-pong** (`1115`): two gates alternate control each round.
- **Dispatcher** (`1116`, `1195`): a central thread inspects shared state and opens the right gate.

### 2. Producer-consumer with bounded capacity

**Template (two Conditions):**

```python
from collections import deque
from threading import Lock, Condition

class BoundedBlockingQueue:
    def __init__(self, capacity: int):
        self.q = deque()
        self.cap = capacity
        self.lock = Lock()
        self.not_full = Condition(self.lock)
        self.not_empty = Condition(self.lock)

    def enqueue(self, x: int) -> None:
        with self.not_full:
            while len(self.q) == self.cap:
                self.not_full.wait()
            self.q.append(x)
            self.not_empty.notify()

    def dequeue(self) -> int:
        with self.not_empty:
            while not self.q:
                self.not_empty.wait()
            x = self.q.popleft()
            self.not_full.notify()
            return x
```

**Why two conditions instead of one:**
- Fewer unnecessary wakeups (no thundering herd)
- Producers only wake consumers and vice versa
- Better behavior under contention

### 3. Group formation / batching

Think in terms of two sub-problems:
- **Admission:** how many of each thread type are needed? (`Semaphore`)
- **Synchronization:** when is the full batch ready? (`Barrier`)

### 4. Resource allocation without deadlock

Three classic strategies:
- **Resource ordering:** always acquire locks in the same global order (breaks circular wait)
- **Concurrency limiting:** `Semaphore(N-1)` ensures at least one thread can always proceed
- **Arbitrator:** a global lock serializes resource pickup (simple but low concurrency)

### 5. Parallel work queue

Key design points:
- Protect `visited` set and work queue with a `Lock`
- Hold the lock only for queue/set operations, not during I/O
- BFS levels naturally batch independent work
- `ThreadPoolExecutor` avoids per-round thread creation overhead

## Interview Heuristics

- Use `Semaphore` when the problem is mostly "who goes next?"
- Use `Condition` when the problem is mostly "wait until state changes."
- Use two conditions for bounded buffer problems.
- Keep shared state minimal and explicit.
- Signal immediately after changing the state another thread is waiting on.
- Prefer simple correctness over clever lock tricks.

## Common Mistakes

- Using `if` instead of `while` around `wait()`
- Reading shared state outside the lock protecting it
- Calling `notify()` before updating state
- Using one condition for unrelated waiting predicates
- Forgetting that fairness is not guaranteed unless the design enforces it

## Practical Rule of Thumb

If you are stuck, start with:

- `Semaphore` for strict ordering
- `Condition + turn/counter` for state-based coordination
- `Lock + two Condition`s for producer-consumer

That covers most interview-style concurrency problems in this folder.
