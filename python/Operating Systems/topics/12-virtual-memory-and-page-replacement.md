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
