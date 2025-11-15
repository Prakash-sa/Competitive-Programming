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
