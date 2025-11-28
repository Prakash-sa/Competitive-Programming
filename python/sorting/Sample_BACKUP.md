0. Python CP Speed Tips (Important)

Use these in almost every CF Python solution:

import sys
input = sys.stdin.readline


When sorting heavily:

Prefer list.sort() or sorted() with key= (Python’s Timsort is O(n log n)).

Avoid custom comparators (functools.cmp_to_key) unless absolutely needed (slower).

Use bisect for binary search when you search in already sorted arrays.

from bisect import bisect_left, bisect_right

1. Basic Sorting Patterns
1.1 Sort list of numbers
a = [5, 2, 9, 1]

# Increasing
a.sort()          # [1, 2, 5, 9]

# Decreasing
a.sort(reverse=True)  # [9, 5, 2, 1]


When used?

After sorting, you can use two pointers, binary search, etc.

1.2 Sort with key (absolute value, custom metric, etc.)
a = [-5, 2, -3, 1]

# Sort by absolute value, tie-break by actual value
a.sort(key=lambda x: (abs(x), x))


Use when:

You need special ordering (e.g., sort by frequency, then by value).

Always try to express your order as key=.

1.3 Sort list of pairs / tuples

Python sorts tuples lexicographically.

points = [(2, 3), (1, 5), (2, 1)]

# Sort by x then y
points.sort()  # [(1, 5), (2, 1), (2, 3)]

# Sort by y then x
points.sort(key=lambda p: (p[1], p[0]))


Use when:

Classic CF tasks: sorting intervals (l, r), items (value, index) etc.

1.4 Sort while keeping original indices

Often used with coordinate compression, ranking, etc.

a = [50, 10, 20]

# pair = (value, original_index)
pairs = [(val, i) for i, val in enumerate(a)]
pairs.sort()  # sorted by value

# Example: get ranks
rank = [0] * len(a)
for r, (_, idx) in enumerate(pairs):
    rank[idx] = r

1.5 Stable sort to merge / reduce intervals

Python’s sort is stable: equal keys keep original order.

Example: sort intervals by l, then process to merge:

intervals = [(1, 3), (2, 4), (5, 6)]
intervals.sort()  # by left endpoint

merged = []
cur_l, cur_r = intervals[0]
for l, r in intervals[1:]:
    if l <= cur_r:
        cur_r = max(cur_r, r)
    else:
        merged.append((cur_l, cur_r))
        cur_l, cur_r = l, r
merged.append((cur_l, cur_r))


Pattern: sort, then linear scan.

2. Sorting + Classic Patterns
2.1 Two-pointers on sorted array
Pattern: find if there exists pair with sum = target

Template:

def has_pair_with_sum(a, target):
    a.sort()
    i, j = 0, len(a) - 1
    while i < j:
        s = a[i] + a[j]
        if s == target:
            return True
        if s < target:
            i += 1
        else:
            j -= 1
    return False


Use for:

Count pairs with some property.

Minimize / maximize something over pairs.

2.2 Two-pointers for counting pairs with condition

Example: count pairs (i, j) with a[j] - a[i] <= k.

def count_pairs_leq(a, k):
    a.sort()
    n = len(a)
    ans = 0
    j = 0
    for i in range(n):
        while j < n and a[j] - a[i] <= k:
            j += 1
        # indices [i+1 .. j-1] are valid partners for i
        ans += max(0, j - i - 1)
    return ans

2.3 Sorting + prefix sums

Typical: “max sum of k elements after some constraints”.

Pattern:

# Sort by something, then build prefix sums
a.sort()
pref = [0] * (len(a) + 1)
for i in range(len(a)):
    pref[i+1] = pref[i] + a[i]

# sum of a[l:r] = pref[r] - pref[l]


You combine this with binary search or two-pointers.

2.4 Coordinate compression (uses sorting)

Very common on CF when values up to 1e9 but only N=2e5 used.

Template:

def compress(arr):
    """Return compressed array and mapping: value -> compressed index [0..m-1]."""
    uniq = sorted(set(arr))
    idx = {v: i for i, v in enumerate(uniq)}
    compressed = [idx[v] for v in arr]
    return compressed, idx, uniq

# Example:
# a = [100, 1000, 100, 500000000]
# comp, mapping, uniq = compress(a)


Usage:

Fenwick tree / segment tree index.

DP over compressed coordinates.

2.5 Sweep-line with events

Sort events by coordinate/time, then process in order.

Example: maximum number of overlapping intervals.

def max_overlap(intervals):
    events = []
    for l, r in intervals:
        events.append((l, +1))   # start
        events.append((r + 1, -1))  # end after r (for [l, r])

    events.sort()
    cur = 0
    best = 0
    for x, delta in events:
        cur += delta
        best = max(best, cur)
    return best


Pattern:

Convert to (position, +1/-1) events.

Sort events.

Scan and keep running total.

3. Searching Basics
3.1 Linear scan (baseline)

Usually too slow alone for large constraints, but useful when N small.

def find_first(a, x):
    for i, v in enumerate(a):
        if v == x:
            return i
    return -1

4. Binary Search Patterns
Style 1: Search on index in array (classic “find target”)

Array must be sorted.

def binary_search(a, x):
    """Return index of x in sorted a, or -1."""
    lo, hi = 0, len(a) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if a[mid] == x:
            return mid
        elif a[mid] < x:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


Use when you need exact match.

Style 2: “First True” on integer domain [lo, hi]

This is the most important CF pattern: binary search on answer or index.

Monotonic predicate check(mid):

False False ... False True True ... True

Template:

def binary_search_first_true(lo, hi, check):
    """
    Find smallest x in [lo, hi] such that check(x) is True.
    Assumes there exists some True, and check is monotonic.
    """
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo


Example: find minimum t such that you can do something in t time.

def can(t):
    # implement logic
    return True or False

ans = binary_search_first_true(0, 10**18, can)

Style 3: “Last True” on integer domain

Pattern: True True ... True False False ... False.

def binary_search_last_true(lo, hi, check):
    """
    Find largest x in [lo, hi] such that check(x) is True.
    """
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if check(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo

4.1 Binary Search on Answer (Very Common)

You don’t search in array; you search in solution space (time, capacity, etc.)

Steps:

Define search space [L, R].

Define check(mid) → can we achieve at mid?

Use binary_search_first_true to minimize mid (or maximize with last_true).

Example skeleton:

def check(x):
    # Use greedy, simulation, DP etc. with parameter x
    # Return True if solution is possible with x, else False
    return True

def solve():
    L, R = 0, 10**18  # choose correct bounds
    ans = binary_search_first_true(L, R, check)
    print(ans)


Problems:

Minimum capacity, minimum time, minimal maximum distance, etc.

4.2 Binary Search with bisect (standard library)

bisect_left and bisect_right on sorted list a.

from bisect import bisect_left, bisect_right

a = [1, 2, 4, 4, 5]

# lower_bound(x): first index with a[i] >= x
i = bisect_left(a, 4)   # 2

# upper_bound(x): first index with a[i] > x
j = bisect_right(a, 4)  # 4

# count of x: j - i
cnt = j - i


Common patterns:

Count elements in [L, R]:

cnt = bisect_right(a, R) - bisect_left(a, L)


Inserting while maintaining sorted order:

x = 3
i = bisect_left(a, x)
a.insert(i, x)

4.3 Binary Search on Real Numbers (double answers)

Used when you need something like minimal radius, minimal average, etc.

Use fixed iterations.

def check(x: float) -> bool:
    # some monotonic condition on real x
    return True

def binary_search_real(lo, hi, iterations=60):
    for _ in range(iterations):
        mid = (lo + hi) / 2.0
        if check(mid):
            hi = mid
        else:
            lo = mid
    return (lo + hi) / 2.0

4.4 Ternary Search (unimodal function)

If f(x) is strictly decreasing then strictly increasing (or vice versa) on a range, you can use ternary search to find minimum/maximum.

Discrete domain:

def ternary_search_integer(lo, hi, f):
    while hi - lo > 3:
        m1 = lo + (hi - lo) // 3
        m2 = hi - (hi - lo) // 3
        if f(m1) < f(m2):   # for minimum
            hi = m2 - 1
        else:
            lo = m1 + 1
    best_x = lo
    best_val = f(lo)
    for x in range(lo+1, hi+1):
        val = f(x)
        if val < best_val:
            best_val, best_x = val, x
    return best_x, best_val


Continuous domain:

def ternary_search_real(lo, hi, f, iterations=100):
    for _ in range(iterations):
        m1 = (2*lo + hi) / 3
        m2 = (lo + 2*hi) / 3
        if f(m1) < f(m2):  # for minimum
            hi = m2
        else:
            lo = m1
    x = (lo + hi) / 2
    return x, f(x)


Used for:

“Find point minimizing sum of distances” in convex/unimodal contexts.

5. Searching in 2D / Grids with Sorted Properties
5.1 Matrix sorted row-wise and column-wise

Classic: search in O(n + m):

def search_matrix(a, x):
    n, m = len(a), len(a[0])
    i, j = 0, m - 1  # start from top-right
    while i < n and j >= 0:
        if a[i][j] == x:
            return True
        elif a[i][j] > x:
            j -= 1
        else:
            i += 1
    return False

5.2 Binary search per row / flattened matrix

If matrix is like sorted 1D when flattened:

def search_matrix_flat(a, x):
    n, m = len(a), len(a[0])
    lo, hi = 0, n*m - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        r, c = divmod(mid, m)
        if a[r][c] == x:
            return True
        elif a[r][c] < x:
            lo = mid + 1
        else:
            hi = mid - 1
    return False

6. “Other” Core Patterns Tied to Sorting/Searching

These are not strictly sorting/searching but almost always appear together.

6.1 Sliding Window (Two Pointers on unsorted but monotonic condition)

Used for subarray problems (sum, unique elements, etc.).

def longest_subarray_with_sum_leq_k(a, k):
    n = len(a)
    best = 0
    s = 0
    j = 0
    for i in range(n):
        while j < n and s + a[j] <= k:
            s += a[j]
            j += 1
        best = max(best, j - i)
        s -= a[i]
    return best


Connection:

On sorted arrays: becomes typical two-pointer.

On unsorted with monotone condition: sliding window.

6.2 Meet-in-the-middle (searching in 2^N with N up to ~40)

Split set into two halves, enumerate subsets in each half, sort one side, then binary search.

Skeleton for subset sum:

from bisect import bisect_left

def subset_sums(arr):
    res = [0]
    for x in arr:
        res += [s + x for s in res]
    return res

def can_sum_to(arr, target):
    n = len(arr)
    left = arr[:n//2]
    right = arr[n//2:]

    L = subset_sums(left)
    R = subset_sums(right)
    R.sort()

    for s in L:
        need = target - s
        i = bisect_left(R, need)
        if i < len(R) and R[i] == need:
            return True
    return False


Uses:

brute force 2^(n/2) with sorting + binary search.

6.3 Using sets/dicts as O(1) search

Even though not “binary search”, this is a search pattern you use constantly.

s = set(a)       # membership in O(1) average
if x in s:
    ...


Count frequencies:

from collections import Counter
cnt = Counter(a)
# top k most frequent: use sorting
freq_pairs = sorted(cnt.items(), key=lambda kv: (-kv[1], kv[0]))

6.4 Priority Queue / Heap (searching / picking min or max)
import heapq

# min-heap
pq = []
heapq.heappush(pq, (cost, node))

while pq:
    cost, node = heapq.heappop(pq)
    # always get smallest cost available


Heap is often combined with sorting/binary search:

Dijkstra’s algorithm

Greedy scheduling (pick smallest/largest available)

7. Putting It Together: Example “Pattern Library” Snippets

Below is a compact “library” you could put at top of your CF template and copy as needed.

import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

# ---------- Sorting helpers ----------

def sort_pairs_by_second_first(pairs):
    # pairs: list of (x, y)
    pairs.sort(key=lambda p: (p[1], p[0]))


def coordinate_compress(arr):
    uniq = sorted(set(arr))
    idx = {v: i for i, v in enumerate(uniq)}
    return [idx[v] for v in arr], idx, uniq


# ---------- Binary search helpers ----------

def binary_search_index(a, x):
    """Return index of x in sorted a, or -1."""
    lo, hi = 0, len(a) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if a[mid] == x:
            return mid
        elif a[mid] < x:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


def binary_search_first_true(lo, hi, check):
    """Smallest x in [lo, hi] with check(x) == True."""
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo


def binary_search_last_true(lo, hi, check):
    """Largest x in [lo, hi] with check(x) == True."""
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if check(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo


def binary_search_real(lo, hi, check, iterations=60):
    for _ in range(iterations):
        mid = (lo + hi) / 2.0
        if check(mid):
            hi = mid
        else:
            lo = mid
    return (lo + hi) / 2.0


# ---------- Two pointers / sliding window ----------

def has_pair_with_sum(a, target):
    a.sort()
    i, j = 0, len(a) - 1
    while i < j:
        s = a[i] + a[j]
        if s == target:
            return True
        if s < target:
            i += 1
        else:
            j -= 1
    return False


def longest_subarray_sum_leq_k(a, k):
    n = len(a)
    best = 0
    s = 0
    j = 0
    for i in range(n):
        while j < n and s + a[j] <= k:
            s += a[j]
            j += 1
        best = max(best, j - i)
        s -= a[i]
    return best


# ---------- Sweep line example ----------

def max_overlap(intervals):
    events = []
    for l, r in intervals:
        events.append((l, +1))
        events.append((r + 1, -1))
    events.sort()
    cur = best = 0
    for _, d in events:
        cur += d
        if cur > best:
            best = cur
    return best