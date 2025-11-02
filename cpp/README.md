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
