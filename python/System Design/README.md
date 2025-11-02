# System Design Patterns (Python)

Folder summary for the design-style data structure problems solved in Python. Each entry links the implementation to the key pattern, complexity, and interview-ready talking points.

## Problem Reference Map

- `146. LRU Cache.py`
  - Pattern: `OrderedDict` to keep usage order, evict from front.
  - Ops: `get`/`put` are both O(1) amortized thanks to hash + linked list under the hood.
  - Tip: Always move a key to the end after a hit to mark it as most recently used.
  - Watch: [LRU Cache Explained (NeetCode)](https://www.youtube.com/watch?v=7ABFKPK2hD4)

- `225. Implement Stack using Queues.py`
  - Pattern: Single `deque` rotated after every push.
  - Ops: `push` is O(n), `pop`/`top` are O(1).
  - Tip: Mention the trade-off - keeping push heavy lets pop stay instant, which is nice when pops dominate.
  - Watch: [Stack Using Queues (take U forward)](https://www.youtube.com/watch?v=jDZQKzEtbYQ)

- `232. Implement Queue using Stacks.py`
  - Pattern: Two stacks (`in_stack`, `out_stack`) with lazy transfer.
  - Ops: Amortized O(1) for all; worst-case pop triggers a full transfer.
  - Tip: Stress the amortized argument and the idea of decoupling read/write paths - common follow-up in interviews.
  - Watch: [Queue Using Stacks (NeetCode)](https://www.youtube.com/watch?v=Wg8IiY1LbII)

- `3508. Implement Router.py`
  - Pattern: Sliding FIFO buffer with `deque`, duplicate tracking via `set`, per-destination timestamps in `defaultdict(deque)`.
  - Ops: `addPacket`/`forwardPacket` O(1); `getCount` uses binary search on timestamps for O(log k).
  - Tip: Talk about keeping metadata (timestamp queues) sorted to unlock range queries without extra sweeps.
  - Watch: [Sliding Window & Queue Patterns (Tech Dummies)](https://www.youtube.com/watch?v=MK-NZ4hN7rs)

- `355. Design Twitter.py`
  - Pattern: Heap or deque of per-user tweets + follow graph; merge the latest 10 using a max heap.
  - Ops: `postTweet` O(1); `getNewsFeed` O((F + T) log F) depending on followers `F` and tweets `T`.
  - Tip: Highlight pruning: only push the most recent tweet from each followee, then expand lazily.
  - Watch: [Design Twitter (NeetCode)](https://www.youtube.com/watch?v=pNicIB1Q2cU)

- `705. Design HashSet.py`
  - Pattern: Fixed bucket array with separate chaining (lists).
  - Ops: Average O(1), worst-case O(n) per bucket; load factor controlled by prime bucket size (`2069`).
  - Tip: Remind that resizing is optional at interview scale but worth mentioning for production-readiness.
  - Watch: [Design HashSet (LeetCode official)](https://www.youtube.com/watch?v=Li0tagTiV0M)

- `706. Design HashMap.py`
  - Pattern: Same bucketing as the hash set, but store `(key, value)` pairs.
  - Ops: Average O(1) for `put`/`get`/`remove`.
  - Tip: Bring up collision handling strategies (chaining vs open addressing) and why chaining keeps deletions easy.
  - Watch: [Design HashMap (NeetCode)](https://www.youtube.com/watch?v=KEs5UyBJ39g)

- `981. Time Based Key-Value Store.py`
  - Pattern: Dictionary of sorted `[(timestamp, value)]` lists; binary search to resolve historical reads.
  - Ops: `set` O(1) append (timestamps strictly increasing); `get` O(log m) via `bisect`.
  - Tip: Interview trick - store timestamps alongside values to avoid parallel arrays and keep bisecting simple.
  - Watch: [Time Based Key-Value Store (NeetCode)](https://www.youtube.com/watch?v=fu2cD_6E8Hw)

## HashMap concepts

- Hash function design maps a key to an address inside the storage space (similar to postcodes). A good hash spreads keys evenly so no bucket is overloaded.
- Collision handling is essential: the hash squeezes a large key space into limited addresses, so distinct keys can collide. Always plan a collision strategy.

## HashSet internals

- Separate chaining: keep collided values inside a bucket (often a list); each bucket works independently.
- Open addressing: on collision, probe the main array with a deterministic strategy until a free slot appears.
- Two-choice hashing: compute two hashes and pick the bucket with fewer elements to balance the load.

In practice a HashSet sits on top of a contiguous array. Each entry points to a bucket that stores the actual values. Workflow: hash the value, locate the bucket, and then run the requested operation (`add`, `remove`, `contains`) on that bucket.
