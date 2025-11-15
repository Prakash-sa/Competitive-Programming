# Paging, Segmentation & TLB

## Paging Basics
- Divide logical memory into fixed-size **pages** and physical memory into **frames**.
- Page table entry (PTE) stores frame number + bits (valid, protection, dirty, accessed, cache flags).
- Eliminates external fragmentation; only internal fragmentation inside final page.

## Address Translation
Logical address split into page number `p` and offset `d`.
```
frame = page_table[p]
physical_address = frame * page_size + d
```

## TLB (Translation Lookaside Buffer)
- Small associative cache storing recent page→frame mappings.
- Effective Memory Access Time (EMAT) ≈ `hit_ratio * memory_access + miss_ratio * (memory_access + page_table_access)`.

## Page Table Optimizations
- **Hierarchical/multi-level:** reduce memory usage for sparse address spaces.
- **Hashed page tables:** good for very large address spaces.
- **Inverted page table:** one entry per physical frame.

## Segmentation
- Logical view split into variable-length segments (code, data, stack).
- Segment table entry stores base + limit; hardware performs bounds checking.
- Facilitates protection and sharing but suffers external fragmentation.

## Paged Segmentation
Combine segmentation (logical protection) with paging (physical allocation) to avoid external fragmentation while preserving semantic grouping.

## Interview Prompts
- Compute physical address translation given TLB state and multi-level page table.
- Explain difference between page fault (valid bit 0) and protection fault (access violation).

## Placement Essentials
- Show you can compute physical addresses, TLB hit/miss penalties, and explain multi-level page tables.
- Contrast segmentation vs paging in terms of protection and fragmentation.
- Mention modern hardware features: huge pages, ASIDs, page coloring, sharing page tables for shared libraries.

## Python Demo — Page Table Lookup
```python
"""Simulate paging with a dictionary and compute EMAT."""
PAGE_SIZE = 4096
page_table = {
    0x00: {"frame": 0x10, "valid": True},
    0x01: {"frame": 0x05, "valid": True},
}

def translate(logical_addr):
    page = logical_addr // PAGE_SIZE
    offset = logical_addr % PAGE_SIZE
    entry = page_table.get(page)
    if not entry or not entry["valid"]:
        raise MemoryError("Page fault")
    frame = entry["frame"]
    physical = frame * PAGE_SIZE + offset
    return page, frame, physical

logical = 0x01_012
page, frame, physical = translate(logical)
print(f"VA {logical:#x} -> page {page:#x}, frame {frame:#x}, PA {physical:#x}")

TLB_hit_ratio = 0.9
memory_time = 100  # ns
TLB_lookup = 10
EMAT = TLB_hit_ratio * (TLB_lookup + memory_time) + (1 - TLB_hit_ratio) * (TLB_lookup + 2 * memory_time)
print(f"EMAT ≈ {EMAT} ns")
```

Explain each step of translation and how TLB hit ratio impacts effective memory access time.
