# 🔍 Sorting & Searching Fundamentals

## ⚡ Quick Setup

```python
import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline
```

**Key Optimizations:**
- ✅ Use `list.sort()` or `sorted()` with `key=` (Python's Timsort is O(n log n))
- ❌ Avoid custom comparators — slower  
- ✅ Use `bisect` for binary search on sorted arrays

---

## 1️⃣ Basic Sorting Patterns

### 1.1 Sort List of Numbers
```python
a = [5, 2, 9, 1]
a.sort()              # [1, 2, 5, 9]
a.sort(reverse=True)  # [9, 5, 2, 1]
```
**When:** After sorting, use two-pointers, binary search, sliding window.

### 1.2 Sort with Key Function
```python
a = [-5, 2, -3, 1]
a.sort(key=lambda x: (abs(x), x))
```

### 1.3 Sort Pairs & Tuples
```python
points = [(2, 3), (1, 5), (2, 1)]
points.sort()  # lexicographic [(1, 5), (2, 1), (2, 3)]
points.sort(key=lambda p: (p[1], p[0]))  # by y, then x
```

### 1.4 Coordinate Compression
```python
def compress(arr):
    uniq = sorted(set(arr))
    idx = {v: i for i, v in enumerate(uniq)}
    return [idx[v] for v in arr]
```

### 1.5 Merge Intervals
```python
intervals.sort()  # by left
merged = []
cur_l, cur_r = intervals[0]
for l, r in intervals[1:]:
    if l <= cur_r:
        cur_r = max(cur_r, r)
    else:
        merged.append((cur_l, cur_r))
        cur_l, cur_r = l, r
merged.append((cur_l, cur_r))
```

---

## 2️⃣ Sorting + Two Pointers

### 2.1 Find Pair with Sum = Target
```python
def has_pair_with_sum(a, target):
    a.sort()
    i, j = 0, len(a) - 1
    while i < j:
        s = a[i] + a[j]
        if s == target:
            return True
        elif s < target:
            i += 1
        else:
            j -= 1
    return False
```

### 2.2 Count Pairs with Condition
```python
def count_pairs_leq(a, k):
    a.sort()
    ans, j = 0, 0
    for i in range(len(a)):
        while j < len(a) and a[j] - a[i] <= k:
            j += 1
        ans += max(0, j - i - 1)
    return ans
```

### 2.3 Sweep-Line Events
```python
def max_overlap(intervals):
    events = [(l, 1) for l, r in intervals] + \
             [(r + 1, -1) for l, r in intervals]
    events.sort()
    cur = best = 0
    for _, d in events:
        cur += d
        best = max(best, cur)
    return best
```

---

## 3️⃣ Binary Search Patterns

### 3.1 Classic Binary Search
```python
def binary_search(a, x):
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
```

### 3.2 "First True" — Binary Search on Answer
```python
def binary_search_first_true(lo, hi, check):
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

# Find min time t to complete task
ans = binary_search_first_true(0, 10**18, can_finish)
```

### 3.3 "Last True" 
```python
def binary_search_last_true(lo, hi, check):
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if check(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo
```

### 3.4 Using bisect Module
```python
a = [1, 2, 4, 4, 5]
i = bisect_left(a, 4)   # 2 (first ≥ 4)
j = bisect_right(a, 4)  # 4 (first > 4)
cnt = j - i  # 2

# Count in range [L, R]
bisect_right(a, R) - bisect_left(a, L)
```

### 3.5 Ternary Search (Unimodal)
```python
def ternary_search(lo, hi, f, iterations=100):
    for _ in range(iterations):
        m1 = lo + (hi - lo) / 3
        m2 = hi - (hi - lo) / 3
        if f(m1) < f(m2):
            hi = m2
        else:
            lo = m1
    return (lo + hi) / 2
```

---

## 4️⃣ Matrix Searching

### 4.1 Sorted Matrix (Rows & Columns)
```python
def search_matrix(a, x):
    i, j = 0, len(a[0]) - 1  # top-right
    while i < len(a) and j >= 0:
        if a[i][j] == x:
            return True
        elif a[i][j] > x:
            j -= 1
        else:
            i += 1
    return False
```

### 4.2 Flattened Matrix
```python
def search_matrix_flat(a, x):
    n, m = len(a), len(a[0])
    lo, hi = 0, n * m - 1
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
```

---

## 5️⃣ Sliding Window

```python
def longest_window_sum_leq(a, k):
    best = s = j = 0
    for i in range(len(a)):
        while j < len(a) and s + a[j] <= k:
            s += a[j]
            j += 1
        best = max(best, j - i)
        s -= a[i]
    return best
```

---

## 6️⃣ Meet-in-the-Middle
```python
def subset_sums(arr):
    res = [0]
    for x in arr:
        res += [s + x for s in res]
    return res

def can_sum_to(arr, target):
    L = subset_sums(arr[:len(arr)//2])
    R = sorted(subset_sums(arr[len(arr)//2:]))
    for s in L:
        if bisect_left(R, target - s) < len(R) and \
           R[bisect_left(R, target - s)] == target - s:
            return True
    return False
```

---

## 📚 Quick Reference

| Problem | Technique | Complexity |
|---------|-----------|-----------|
| Sort numbers | `list.sort()` | O(n log n) |
| Find pair sum | Two pointers | O(n) after sort |
| Binary search | `bisect` | O(log n) |
| Range queries | Prefix sums | O(1) after O(n) |
| Large values | Coordinate compress | O(n log n) |
| Unimodal function | Ternary search | O(log n) iterations |

