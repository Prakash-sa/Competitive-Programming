# File Systems

## Abstractions
- **Files:** named byte/record sequences with attributes (name, type, size, timestamps, permissions, owner).
- **Directories:** hierarchical namespace (tree, DAG, general graph with links).
- **Links:** hard links (same inode) vs symbolic links (path references).

## Allocation Methods
| Method | Highlights | Pros | Cons |
| --- | --- | --- | --- |
| Contiguous | File stored in adjacent blocks | Fast sequential access | External fragmentation, difficult growth |
| Linked | Blocks stored anywhere, pointer to next | Easy growth, no external fragmentation | Poor random access, pointer overhead |
| Indexed | Index block (inode) lists direct/indirect pointers | Fast random access, dynamic growth | Index overhead, multi-level logic |

## Free Space Management
Bitmaps, linked lists, grouping, counting. Bitmaps enable quick search for contiguous blocks.

## Directory Implementation
Linear lists (simple), hash tables (faster lookup), B-trees (journaling FS like NTFS/APFS).

## Journaling & Logging
Record intent (metadata updates, writes) in a log before committing to main file system to recover quickly after crashes. Ext3/ext4, NTFS, XFS, APFS use journaling; ZFS/Btrfs use copy-on-write with checksums.

## Buffer Cache
Page cache/buffer cache store recently accessed blocks; write-back vs write-through policies, read-ahead heuristics.

## Interview Prompts
- How does UNIX resolve `/usr/bin/python` using inode + directory entries?
- Explain pros/cons of journaling vs log-structured file systems.
