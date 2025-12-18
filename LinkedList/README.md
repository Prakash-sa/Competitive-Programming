# Linked List Playbook

Problems in this folder cover the core interview patterns for singly linked lists.

## Problem coverage
- `206. Reverse Linked List`, `92. Reverse Linked List II` (if present) - iterative reversal and in-place segment reversal.
- `21. Merge Two Sorted Lists`, `24. Swap Nodes in Pairs` - pointer juggling and dummy head usage.
- `19. Remove Nth Node From End of List` - two-pointer window, watch for `n == len(list)` edge case.
- `141/142. Linked List Cycle I/II` - cycle detection and locating the entry via Floyd's tortoise-hare.
- `143. Reorder List`, `234. Palindrome Linked List` - split + reverse + merge strategy.
- `287. Find the Duplicate Number` - array treated as linked list to detect cycles (Floyd's algorithm).

## KPIs & invariants
- Always track `prev`, `curr`, `next_node` explicitly when rewiring pointers - forgetting to store `next_node` is the #1 bug.
- For cycle problems, articulate the proof: after `mu` steps, slow=fast implies distance to entry equals meeting point offset.
- Use a dummy node when deletions could target the head.
- Time complexities stay linear `O(n)`; strive for O(1) extra space unless the problem allows storing values.

## Interview-ready checklist
- Draw pointer diagrams before coding - especially for reorder and k-group reversal patterns.
- Mention sentinel technique to simplify edge cases (empty list, single node).
- For palindrome checks, clarify when you reverse the second half and optionally restore the list.
- When flattening or merging k lists, call out the data structure (priority queue vs divide-and-conquer).
