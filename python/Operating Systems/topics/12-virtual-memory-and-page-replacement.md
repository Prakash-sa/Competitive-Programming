# Virtual Memory & Page Replacement

## Virtual Memory Concepts
- Allows processes to execute even when not fully resident in physical memory.
- Demand paging loads pages only when referenced; invalid page table entry triggers page fault.
- Lazy loading + working set tracking reduce memory pressure.

## Page Fault Handling Steps
1. Hardware traps to kernel on invalid PTE.
2. OS verifies access and locates page on disk.
3. Chooses free frame or selects victim frame via replacement algorithm.
4. Writes victim to disk if dirty; reads requested page into frame.
5. Updates page table + TLB; restarts faulting instruction.

## Thrashing
Excessive page faults due to working set exceeding available frames. Mitigation: working-set model, page-fault frequency control, reduce multiprogramming level.

## Replacement Algorithms
| Algorithm | Idea | Notes |
| --- | --- | --- |
| FIFO | Replace oldest page | Subject to Belady's anomaly |
| Optimal | Replace page with farthest future use | Theoretical benchmark |
| LRU | Replace least recently used | Needs stack/counter/timestamps |
| LFU/MFU | Replace by frequency counts | Requires aging to avoid stale hot pages |
| Clock / Second-Chance | Circular list giving pages second chance if reference bit set | Efficient approximation of LRU |
| Enhanced Clock | Considers reference + dirty bits | Lowers writes |
| NRU | Categorize pages by R/D bits; choose lowest class |

## Working-Set Model
Track set `W(t, Δ)` of pages referenced in last `Δ` time units; ensure each process has at least |W| frames to avoid thrashing.

## Interview Prompts
- Compute Effective Access Time given TLB, page-fault cost, and hit ratio.
- Compare FIFO vs LRU on sample reference strings.

## Placement Essentials
- Be ready to derive page-fault rates, working-set sizes, and thrashing scenarios.
- Compare replacement algorithms qualitatively (hardware support, complexity, Belady's anomaly).
- Discuss OS data structures: page-fault handler path, swap daemon, dirty page writeback, and prefetchers.

## Python Demo — LRU Cache for Page Replacement
```python
"""Implement a simple LRU page replacement simulator."""
from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = OrderedDict()
        self.page_faults = 0

    def access(self, page):
        if page not in self.cache:
            self.page_faults += 1
            if len(self.cache) >= self.capacity:
                self.cache.popitem(last=False)
        else:
            self.cache.move_to_end(page)
        self.cache[page] = True

reference_string = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3]
lru = LRUCache(capacity=3)
for page in reference_string:
    lru.access(page)
print(f"Page faults with LRU: {lru.page_faults}")
```

Use this snippet to discuss stack algorithms (LRU never suffers Belady's anomaly) and compare to FIFO for the same reference string.
