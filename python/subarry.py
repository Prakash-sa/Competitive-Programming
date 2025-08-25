from typing import List, Tuple, Iterator
from collections import defaultdict

# 1) Enumerate all subarrays (O(n^2), for teaching/debug)
def all_subarrays(a: List[int]) -> Iterator[List[int]]:
    n = len(a)
    for i in range(n):
        for j in range(i + 1, n + 1):   # [i, j)
            yield a[i:j]

# 2) Max subarray sum (Kadane) — O(n)
def max_subarray_sum(a: List[int]) -> Tuple[int, Tuple[int, int]]:
    best = float("-inf")
    cur = 0
    start = 0
    best_l = best_r = 0
    for i, x in enumerate(a):
        if cur <= 0:
            cur = x
            start = i
        else:
            cur += x
        if cur > best:
            best = cur
            best_l, best_r = start, i  # inclusive indices
    return best, (best_l, best_r)

# 3) Prefix sums for fast range-sum queries — build: O(n), query: O(1)
def prefix_sums(a: List[int]) -> List[int]:
    ps = [0]
    for x in a:
        ps.append(ps[-1] + x)
    return ps

def range_sum(ps: List[int], L: int, R: int) -> int:
    # inclusive L..R
    return ps[R + 1] - ps[L]

# 4) Count subarrays with sum exactly k — O(n) with hashmap
def count_subarrays_sum_k(a: List[int], k: int) -> int:
    count = 0
    freq = defaultdict(int)
    freq[0] = 1
    s = 0
    for x in a:
        s += x
        count += freq[s - k]
        freq[s] += 1
    return count

# 5) Max sum of subarray with fixed length k — O(n) sliding window
def max_sum_fixed_k(a: List[int], k: int) -> int:
    n = len(a)
    if k <= 0 or k > n:
        raise ValueError("k must be in 1..len(a)")
    window = sum(a[:k])
    best = window
    for i in range(k, n):
        window += a[i] - a[i - k]
        if window > best:
            best = window
    return best
