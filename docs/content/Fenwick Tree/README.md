## Fenwick tree (`feenwick.py`)

- Supports point updates and prefix sums in `O(log n)` using least-significant-bit jumps.
- Ideal for:
  - Frequency counting with many prefix queries (e.g. inversion counts).
  - Maintaining cumulative sums where range queries = `prefix(r) - prefix(l-1)`.
- Interview reminder: mention 1-based indexing internally and show how `i += i & -i` climbs the tree.
- [Video](https://www.youtube.com/watch?v=9uaXG62Y8Uw&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN)
- [Binary Lifting](https://www.youtube.com/watch?v=nuUspQ7ORXE&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN&index=2)