# Sorting & Searching - ENHANCED GUIDE

## 0. Python CP Speed Tips (CRITICAL)

```python
import sys
from bisect import bisect_left, bisect_right
sys.setrecursionlimit(10**6)
input = sys.stdin.readline  # ~2x faster than input()
```

### Performance Hierarchy
| Operation | Complexity | Notes |
|-----------|-----------|-------|
| list.sort() | O(n log n) | FASTEST - use this |
| sorted() + key | O(n log n) | Nearly same speed |
| heapq.heappush | O(log n) | For partial sorting |
| bisect_left/right | O(log n) | Binary search on sorted |
| custom comparator | O(n log n) × 1.5 | 50% SLOWER - avoid |

**Critical tips:**
- Use `key=lambda x: x` instead of `key` functions when possible (native C code)
- `list.sort()` modifies in-place (saves memory)
- `sorted()` creates new list (safer, not faster)
- Avoid `cmp_to_key` — it's 50% slower

---

## 1. Advanced Sorting Patterns

### 1.1 Radix Sort (for integers when range is small)
```python
def radix_sort(a, max_val):
    """O(n log max_val) for small ranges, O(n*k) space"""
    if not a or max_val == 0:
        return a
    
    # Sort by each bit position
    exp = 1
    while exp <= max_val:
        # Counting sort by digit at exp
        count = [0] * 10
        for num in a:
            digit = (num // exp) % 10
            count[digit] += 1
        for i in range(1, 10):
            count[i] += count[i-1]
        
        result = [0] * len(a)
        for num in reversed(a):
            digit = (num // exp) % 10
            idx = count[digit] - 1
            result[idx] = num
            count[digit] -= 1
        a = result
        exp *= 10
    return a

# Use when: constraints are a <= 10^6, optimize last 1-2% time
```

### 1.2 Merge Sort with Inversion Count
```python
def merge_sort_count_inversions(a):
    """Returns sorted array and count of inversions O(n log n)"""
    if len(a) <= 1:
        return a, 0
    
    mid = len(a) // 2
    left, l_inv = merge_sort_count_inversions(a[:mid])
    right, r_inv = merge_sort_count_inversions(a[mid:])
    
    merged, m_inv = [], 0
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            m_inv += len(left) - i  # inversions
            j += 1
    
    merged.extend(left[i:])
    merged.extend(right[j:])
    
    return merged, l_inv + r_inv + m_inv

# Use when: need to count inversions in array
```

### 1.3 Custom Sorting with Auxiliary Data (Efficient)
```python
# WRONG (creates tuples, slower):
items = [(val, idx, data) for idx, (val, data) in enumerate(...)]
items.sort()

# CORRECT (single sort, then retrieve):
indices = sorted(range(n), key=lambda i: a[i])
sorted_vals = [a[i] for i in indices]
sorted_data = [data[i] for i in indices]

# Even better (use indices only, keep originals):
idx_by_val = sorted(range(n), key=lambda i: a[i])
# Now idx_by_val[i] = original index of i-th smallest value
```

### 1.4 Hybrid Sorting (Tim Sort optimization)
```python
def hybrid_sort_with_cache(a, key_func=None):
    """
    For already partially sorted data:
    - Identify runs of length k
    - Sort runs using insertion sort (cache-friendly)
    - Merge runs
    """
    if len(a) < 64:
        # Insertion sort for small arrays (cache-friendly)
        for i in range(1, len(a)):
            key = a[i]
            j = i - 1
            while j >= 0 and (a[j] > key if key_func is None else key_func(a[j]) > key_func(key)):
                a[j+1] = a[j]
                j -= 1
            a[j+1] = key
        return a
    
    # For larger: use built-in (already optimized)
    return sorted(a, key=key_func) if key_func else sorted(a)
```

---

## 2. Sorting + Classic Patterns (ENHANCED)

### 2.1 Two-Pointers: Minimum Window Subarray
```python
def min_window_sum_geq_k(a, k):
    """Find minimum length subarray with sum >= k"""
    n = len(a)
    min_len = n + 1
    current_sum = 0
    left = 0
    
    for right in range(n):
        current_sum += a[right]
        
        while current_sum >= k and left <= right:
            min_len = min(min_len, right - left + 1)
            current_sum -= a[left]
            left += 1
    
    return min_len if min_len != n + 1 else -1

# Use when: k-sum problems, window queries, capacity problems
```

### 2.2 Sorting + Sweep Line Events (Advanced)
```python
def schedule_meetings_max_rooms(meetings):
    """
    Find minimum rooms needed for all meetings.
    meetings: list of (start, end) times
    """
    events = []
    for start, end in meetings:
        events.append((start, 1))      # meeting starts
        events.append((end, -1))       # meeting ends
    
    events.sort()  # sort by time, then starts before ends
    
    current_rooms = 0
    max_rooms = 0
    
    for time, event_type in events:
        current_rooms += event_type
        max_rooms = max(max_rooms, current_rooms)
    
    return max_rooms

# Variants: find min platforms for trains, min colors for graph scheduling
```

### 2.3 Coordinate Compression (with Duplicates)
```python
def compress_coordinates(coords):
    """
    coords: list of values (may have duplicates)
    Returns: compressed_coords, compress_map, unique_values
    Handles duplicates by assigning same compressed value
    """
    unique_sorted = sorted(set(coords))
    compress_map = {val: idx for idx, val in enumerate(unique_sorted)}
    
    compressed = [compress_map[val] for val in coords]
    return compressed, compress_map, unique_sorted

def compress_2d_efficient(points):
    """Compress 2D points"""
    xs = sorted(set(x for x, y in points))
    ys = sorted(set(y for x, y in points))
    
    x_map = {v: i for i, v in enumerate(xs)}
    y_map = {v: i for i, v in enumerate(ys)}
    
    return [(x_map[x], y_map[y]) for x, y in points]

# Use when: coordinate values up to 10^9, only 10^5 distinct points
```

### 2.4 Bucketing (Alternative to Sorting)
```python
def bucket_sort_positive_integers(a, max_val):
    """O(n + max_val) for integers in [0, max_val]"""
    if not a:
        return []
    
    buckets = [0] * (max_val + 1)
    for num in a:
        buckets[num] += 1
    
    result = []
    for num, count in enumerate(buckets):
        result.extend([num] * count)
    
    return result

# Use when: integers in small range, may have many duplicates
```

---

## 3. Advanced Binary Search Patterns

### 3.1 Binary Search with Monotonic Check Function
```python
def binary_search_monotonic(lo, hi, check):
    """
    Find smallest value in [lo, hi] satisfying check().
    
    check(x) must be monotonic:
    False False ... False True True ... True
    """
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid  # try smaller
        else:
            lo = mid + 1  # need larger
    return lo

# Example: find minimum capacity to complete all tasks in time t
def can_complete_in_time(capacity, tasks, time_limit):
    total_time = sum((task + capacity - 1) // capacity for task in tasks)
    return total_time <= time_limit

capacity = binary_search_monotonic(1, max(tasks), 
    lambda c: can_complete_in_time(c, tasks, time_limit))
```

### 3.2 Binary Search on Floating Point
```python
def binary_search_float(lo, hi, check, eps=1e-9):
    """Binary search for continuous answer"""
    for _ in range(100):  # ~100 iterations = 10^-30 precision
        mid = (lo + hi) / 2
        if check(mid):
            hi = mid
        else:
            lo = mid
    return (lo + hi) / 2

# Example: find minimum radius to place k centers
def can_place_k_centers(centers, k, radius):
    # Check if k centers can cover all points with given radius
    covered = 0
    for point in sorted_points:
        if not any((point - center)**2 <= radius**2 for center in centers):
            covered += 1
    return covered <= k

radius = binary_search_float(0, max_distance, check)
```

### 3.3 Exponential Search (for unbounded arrays)
```python
def exponential_search(a, target):
    """Efficient when target is near beginning"""
    if a[0] == target:
        return 0
    
    i = 1
    while i < len(a) and a[i] < target:
        i *= 2
    
    # Now binary search in [i//2, min(i, len(a))]
    left, right = i // 2, min(i, len(a) - 1)
    while left <= right:
        mid = (left + right) // 2
        if a[mid] == target:
            return mid
        elif a[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

# Use when: very large sorted array, target likely near start
```

### 3.4 Ternary Search on Bitonic Array
```python
def find_peak_bitonic(a):
    """
    Array that increases then decreases (bitonic).
    Find the peak efficiently.
    """
    lo, hi = 0, len(a) - 1
    
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] < a[mid + 1]:
            lo = mid + 1  # peak is to the right
        else:
            hi = mid  # peak is at mid or left
    
    return a[lo]

# Use when: array has one "mountain" peak
```

---

## 4. Practical Competitive Programming Patterns

### 4.1 Sorting with Multiple Sort Keys
```python
def multi_key_sort(items):
    """
    items: list of (id, weight, value, time)
    Sort by: weight DESC, then value DESC, then time ASC
    """
    return sorted(items, key=lambda x: (-x[1], -x[2], x[3]))

# Or: sort by weight DESC, break ties by id ASC
def sort_by_multiple_with_stability(items):
    # Python's sort is stable, so sort by least significant key last
    items.sort(key=lambda x: x[0])  # sort by id (stable)
    items.sort(key=lambda x: -x[1])  # sort by weight, keeps id order for ties
    return items
```

### 4.2 Counting Pairs/Triplets with Sorted Array
```python
def count_triplets_with_sum(a, target):
    """Count triplets (i,j,k) with a[i]+a[j]+a[k] = target"""
    a.sort()
    count = 0
    n = len(a)
    
    for i in range(n - 2):
        # Two pointer for rest
        left, right = i + 1, n - 1
        while left < right:
            s = a[i] + a[left] + a[right]
            if s == target:
                count += 1
                left += 1
                right -= 1
            elif s < target:
                left += 1
            else:
                right -= 1
    
    return count

# Optimize: if many duplicates, count combinations
def count_triplets_with_duplicates(a, target):
    from collections import Counter
    cnt = Counter(a)
    unique = sorted(cnt.keys())
    count = 0
    
    for i, x in enumerate(unique):
        for j in range(i, len(unique)):
            y = unique[j]
            z = target - x - y
            if z < y:
                break
            
            if z == x == y:
                count += cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) // 6
            elif z == x:
                count += cnt[x] * (cnt[x] - 1) // 2 * cnt[y]
            elif z == y:
                count += cnt[x] * cnt[y] * (cnt[y] - 1) // 2
            elif z in cnt:
                count += cnt[x] * cnt[y] * cnt[z]
    
    return count
```

### 4.3 Parallel Sorting with Index Preservation
```python
def sort_parallel_arrays(primary, *rest):
    """
    Sort primary array, keeping parallel arrays aligned.
    primary: main array to sort by
    rest: other arrays to reorder in sync
    """
    indices = sorted(range(len(primary)), key=lambda i: primary[i])
    
    sorted_primary = [primary[i] for i in indices]
    sorted_rest = [[arr[i] for i in indices] for arr in rest]
    
    return sorted_primary, *sorted_rest

# Example:
names = ["Alice", "Bob", "Charlie"]
ages = [30, 25, 35]
scores = [95, 88, 92]

sorted_names, sorted_ages, sorted_scores = sort_parallel_arrays(ages, names, scores)
# Sorts by ages, but keeps names and scores aligned
```

---

## 5. Segment Trees & Fenwick Trees Integration with Sorting

### 5.1 Inversion Count with Fenwick Tree
```python
class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)
    
    def update(self, i, delta=1):
        i += 1
        while i <= self.n:
            self.tree[i] += delta
            i += i & -i
    
    def query(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & -i
        return res
    
    def range_query(self, l, r):
        if l == 0:
            return self.query(r)
        return self.query(r) - self.query(l - 1)

def count_inversions_fenwick(a):
    """Count inversions using coordinate compression + Fenwick tree"""
    from bisect import bisect_left
    
    # Coordinate compress
    sorted_a = sorted(set(a))
    compress = {v: i for i, v in enumerate(sorted_a)}
    
    ft = FenwickTree(len(sorted_a))
    inversions = 0
    
    for i in range(len(a) - 1, -1, -1):
        compressed = compress[a[i]]
        inversions += ft.query(compressed - 1) if compressed > 0 else 0
        ft.update(compressed)
    
    return inversions

# Use when: need fast inversion count, or do multiple queries
```

---

## 6. Common Mistakes & Solutions

| Mistake | Problem | Solution |
|---------|---------|----------|
| Using `sorted()` in loop | O(n²log n) | Sort once outside loop |
| Custom comparator on large arrays | 50% slower | Use `key=` function |
| Not using `sys.stdin.readline` | TLE | Add to all solutions |
| Binary search off-by-one | WA on edge cases | Test with lo=0, hi=1 |
| Sorting with `cmp_to_key` | 2x slower | Rewrite with `key=` |
| Radix sort on random data | Slower than O(n log n) | Use when range small |
| Not handling duplicates in compress | RE/WA | Use `set()` before compress |
| Two-pointer assumes sorted | WA | Always sort first |
