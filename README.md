Binary
======

Some helpful utility snippets:

- Test kth bit is set: num & (1 << k) != 0.
- Set kth bit: num |= (1 << k).
- Turn off kth bit: num &= ~(1 << k).
- Toggle the kth bit: num ^= (1 << k).
- To check if a number is a power of 2, (num & num - 1) == 0 or (num & (-num)) == num.
- Swapping two variables: num1 ^= num2; num2 ^= num1; num1 ^= num2
- When dealing with floating point numbers, take note of rounding mistakes. Consider using epsilon comparisons instead of equality checks. E.g. abs(x - y) <= 10e7 instead of x == y).

String
======

#Non-repeating Characters

Use a 26-bit bitmask to indicate which lower case latin characters are inside the string.

    mask = 0
    for c in set(word):
      mask |= (1 << (ord(c) - ord('a')))

To determine if two strings have common characters, perform & on the two bitmasks. If the result is non-zero, mask_a & mask_b > 0, then the two strings have common characters.

#Anagram

An anagram is word switch or word play. It is the result of re-arranging the letters of a word or phrase to produce a new word or phrase, while using all the original letters only once. In interviews, usually we are only bothered with words without spaces in them.

To determine if two strings are anagrams, there are a few plausible approaches:

Sorting both strings should produce the same resulting string. This takes O(nlgn) time and O(lgn) space.
If we map each character to a prime number and we multiply each mapped number together, anagrams should have the same multiple (prime factor decomposition). This takes O(n) time and O(1) space.
Frequency counting of characters will help to determine if two strings are anagrams. This also takes O(n) time and O(1) space.

#Palindrome
A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as forward, such as madam or racecar.


BFS uses a queue while DFS uses a stack


Tree
====

A tree is an undirected and connected acyclic graph.

Binary tree of n depth.
	
left=pow(2,n)
edges=2(pow(2,n)-1)
level=n+1



Graph
=====


Dijkastra-> shortest path from one node to all nodes.
Bellman-Ford-> Dijkastra + negative edges
Floyd Warshall-> Shortest path bw all pairs of vertices, negative edges allowed


Heap
====

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


Some common formulas
====================

- Sum of 1 to N = (n+1) * n/2
- Sum of GP = 20 + 21 + 22 + 23 + ... 2n = 2n+1 - 1
- Permutations of N = N! / (N-K)!
- Combinations of N = N! / (K! * (N-K)!)


Notes
=====

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
	int myoperation(int a,int b){ return a*b; }

- cout(v.begin(),v.end(),10)-> count 10 in array

OOPS
====

- How would you design a chess game? What classes and objects would you use? What methods would they have?
- How would you design the data structures for a book keeping system for a library?
- Explain how you would design a HTTP server? Give examples of classes, methods, and interfaces. What are the challenges here?
- Discuss algorithms and data structures for a garbage collector?
- How would you implement an HR system to keep track of employee salaries and benefits?
- How would you implement an Elevator system?
- How would you implement a Parking Lot system?



Resources
=========

//--------codeforces everything link--------
https://codeforces.com/blog/entry/57282

//-------------dp---------------------
https://codeforces.com/blog/entry/43256
https://atcoder.jp/contests/dp/tasks

GCPC11J - Time to live
https://www.spoj.com/problems/NITTROAD/
