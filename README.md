# Time Complexity

- n<20: 2^n,n!(brute force, backtracking)
- n<3000 : n^2(dynamic programming)
- 3000<n<10^6: O(n),O(nlogn)(2 pointers, greedy, heap, sorting)
- n>10^6 : O(logn),O(1) (binary search, math)


# Sliding Window

- Linear data structures (arrays, lists, strings)
- Must scan through a subarray or substring
- When the subarray must satisfy some condition (shortest/longest/min/max)
- Improve time complexity from O(N^2) to O(N)

# Two Pointers

- Linear data structures (arrays, lists, strings)
- When you need to scan the start and end of a list
- When you have a sorted list and need to find pairs
- Removing duplicates or filtering

# Slow and Fast Pointer

- Linear data structures (arrays, lists, strings)
- Detect cycle in linked list
- Find middle of linked list
- Perform in one pass with O(1) space

# Linked List Reversal

- Reverse a linked list in 1 pass and O(1) space
- Reverse a specific portion of a linked list
- Reverse nodes in groups of k

# Binary Search

- Input is sorted and you need to find a number
- Finding the position of insertion in a sorted list
- Handling duplicates in sorted arrays
- Searching in rotated sorted arrays

# Top K elements

- Find the top k smallest or largest elements
- Find the kth smallest or largest element
- Find the k most frequent elements

# Binary Tree Traversal

- Preorder: Serialize or deserialize a tree
- Inorder: Retrieve elements in sorted order (BSTs)
- Postorder: Process children before parent (bottom-up)
- BFS: Level by level scanning

# Graph and Matrix

- Search graphs or matrices
- DFS: Explore all possible paths (e.g., maze)
- BFS: Find the shortest path
- Topological Sort: Order tasks based on dependencies

# Backtracking

- Combinatorial problems (combinations, permutations, subsets)
- Constraint satisfaction (Sudoku, N-Queens)
- Prune paths using constraints to reduce search space

# DP

- Overlapping subproblems and optimal substructure
- Optimization problems (min/max distance, profit, etc.)
- Sequence problems (longest increasing subsequence)
- Combinatorial problems (number of ways to do something)
- Reduce time complexity from exponential to polynomial

# Bit Manupulation

- Count number of 0 or 1 bits in a number
- Add numbers without using addition or substraction
- Find a missing number in a list

# Overlapping Intervals

- Merge or consolidate ranges
- Schedule or find conflicts (e.g. meeting rooms)
- Find gaps or missing intervals

# Monotonic Stack

- Find Next Greater or Smaller Element
- Find left/right boundary points in histograms or rectangles
- Maintain elements in order to optimize operations

# Prefix Sum

- Cumulative sums are needed from index 0 to any element
- Querying subarray sums frequently across multiple ranges
- Partial sums can be reused efficiently


# Links

- [Leetcode]https://leetcode.com/discuss/general-discussion/665604/Important-and-Useful-links-from-all-over-the-Leetcode

- [Google Docs]https://docs.google.com/document/d/1wUCqhVHydWiDk6FJdFLSMpgigNrGcs4OFZg0Wa7JGEw/edit?usp=sharing

- [Devops Exercise]https://github.com/bregman-arie/devops-exercises

# Hard

https://www.geeksforgeeks.org/find-the-number-of-sub-arrays-in-the-permutation-of-first-n-natural-numbers-such-that-their-median-is-m/

sub-array with k mean:- https://codeforces.com/blog/entry/91768

- Fenwick tree[http://usaco.org/current/data/sol_median.html]

## Substring vs Subsequence

- Subarray need to be consecutive. Subsequence don't have to be consecutive.

## Time Complexity

- Recursion O(2^N)

## STL

# Map

- Insertion O(log(n)) and find O(log(n))
- Based on Red Black Tree(Inbuilt implementation)
- Key as string O(s.size() \* log(n))
-

# Unordered Map

- Hash tables
- Time complexity insertion O(1) and find O(1)
- can't use pairs as key(maps insert using comparision)

# Multimap

- can use multiple keys

## Topics

# Catalan Number

Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

- Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
- Count the number of possible Binary Search Trees with n keys (See this)
- Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
- Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.

# Binary

Some helpful utility snippets:

- Test kth bit is set: num & (1 << k) != 0.
- Set kth bit: num |= (1 << k).
- Turn off kth bit: num &= ~(1 << k).
- Toggle the kth bit: num ^= (1 << k).
- To check if a number is a power of 2, (num & num - 1) == 0 or (num & (-num)) == num.
- Swapping two variables: num1 ^= num2; num2 ^= num1; num1 ^= num2
- When dealing with floating point numbers, take note of rounding mistakes. Consider using epsilon comparisons instead of equality checks. E.g. abs(x - y) <= 10e7 instead of x == y).

# String

# Non-repeating Characters

Use a 26-bit bitmask to indicate which lower case latin characters are inside the string.

    mask = 0
    for c in set(word):
      mask |= (1 << (ord(c) - ord('a')))

To determine if two strings have common characters, perform & on the two bitmasks. If the result is non-zero, mask_a & mask_b > 0, then the two strings have common characters.

# Anagram

An anagram is word switch or word play. It is the result of re-arranging the letters of a word or phrase to produce a new word or phrase, while using all the original letters only once. In interviews, usually we are only bothered with words without spaces in them.

To determine if two strings are anagrams, there are a few plausible approaches:

Sorting both strings should produce the same resulting string. This takes O(nlgn) time and O(lgn) space.
If we map each character to a prime number and we multiply each mapped number together, anagrams should have the same multiple (prime factor decomposition). This takes O(n) time and O(1) space.
Frequency counting of characters will help to determine if two strings are anagrams. This also takes O(n) time and O(1) space.

# Palindrome

A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as forward, such as madam or racecar.

BFS uses a queue while DFS uses a stack

# LinkedList

- Quick sort is preferred for Arrays and MergeSort of [LinkedList](https://www.geeksforgeeks.org/why-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists/).
-

# Tree

A tree is an undirected and connected acyclic graph.

Binary tree of n depth.
left=pow(2,n)
edges=2(pow(2,n)-1)
level=n+1

# BST

Inorder traverse of BST will give an ascending sequence of all values.
By slightly modifying the inorder traverse such that we firstly travel right subtree and then left subtree, we can get the descending order of the BST.

# Graph

- Dijkastra-> shortest path from one node to all nodes.
- Bellman-Ford-> Dijkastra + negative edges
- Floyd Warshall-> Shortest path bw all pairs of vertices, negative edges allowed

# Heap

- If node is at index:- i
  left Node->2*i
  right Node->2*i+1
  its parent->mod(i/2)

- If h is height that max no. of nodes is pow(2,h+1)-1

if vector<double>numbers={0,1,2,3,...,9}

- max_heap(numbers.begin(),numbers.end())
- push_heap(numbers.begin(),numbers.end()) in vector numbers.push_back(4)
- largest no. by numbers.front()
- pop_heap(numbers.begin(),numbers.end()) and numbers.pop_back() // remove 9 at back

# Some common formulas

- Sum of 1 to N = (n+1) \* n/2
- Sum of GP = 20 + 21 + 22 + 23 + ... 2n = 2n+1 - 1
- Permutations of N = N! / (N-K)!
- Combinations of N = N! / (K! \* (N-K)!)

# Notes

- A priority queue is an abstract data type, while a Heap is a data structure. Therefore, a Heap is not a Priority Queue, but a way to implement a Priority Queue.
- int->string use to_string(int)
- string->int use stoi(string) or stol(large int)
- next_permutation(v.begin(),v.end()) or prev_permutation(v.begin(),v.end())
- pair<int,int>p and p=minmax(arr) then p.first->min and p.second->max
- copy(v1.begin(),v1.end(),v2.begin())
- fill(v.begin(),v.end(),1)
- lower_bound(v.begin(),v.end(),6)
- upper_bound(v.begin(),v.end(),10) -> point to the element location
- reverse , reverse_copy, rotate
- unique-> to copy same element unique(v.begin(),v.end());
- v.resize(n)
- iota -> increment the value

  iota(v.begin(),v.end(),10) -> increment the value by 10

- accumulate -> add all the value in the vector

  accumulate(v.begin(),v.end(),result, myoperation)
  int myoperation(int a,int b){ return a\*b; }

- cout(v.begin(),v.end(),10)-> count 10 in array

# OOPS

- How would you design a chess game? What classes and objects would you use? What methods would they have?
- How would you design the data structures for a book keeping system for a library?
- Explain how you would design a HTTP server? Give examples of classes, methods, and interfaces. What are the challenges here?
- Discuss algorithms and data structures for a garbage collector?
- How would you implement an HR system to keep track of employee salaries and benefits?
- How would you implement an Elevator system?
- How would you implement a Parking Lot system?

# Resources

# codeforces everything link

- https://codeforces.com/blog/entry/57282
- https://leetcode.com/discuss/interview-question/2189149/amazon-online-assessment-questions
