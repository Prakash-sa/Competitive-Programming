# https://leetcode.com/problems/lfu-cache/description/

'''
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
 

Constraints:
1 <= capacity <= 104
0 <= key <= 105
0 <= value <= 109
At most 2 * 105 calls will be made to get and put.
'''

class LFUCache:

    def __init__(self, capacity: int):
        self.cap=capacity
        self.key2val={}
        self.key2freq={}
        self.freq2key=defaultdict(OrderedDict)
        self.minf=0

    def get(self, key: int) -> int:
        if key not in self.key2val:
            return -1
        oldfreq=self.key2freq[key]
        self.key2freq[key]=oldfreq+1
        self.freq2key[oldfreq].pop(key)
        if not self.freq2key[oldfreq]:
            del self.freq2key[oldfreq]
        self.freq2key[oldfreq+1][key]=1
        if self.minf not in self.freq2key:
            self.minf+=1
        return self.key2val[key]   

    def put(self, key: int, value: int) -> None:
        if self.cap<=0:
            return
        if key in self.key2val:
            self.get(key)
            self.key2val[key]=value
            return
        
        if len(self.key2val)==self.cap:
            delkey,_=self.freq2key[self.minf].popitem(last=False)
            del self.key2val[delkey]
            del self.key2freq[delkey]
        
        self.key2val[key]=value
        self.key2freq[key]=1
        self.freq2key[1][key]=1
        self.minf=1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


# Complexity Analysis
# Here, N is the total number of operations.
# Time complexity: O(1), as required by the question.

# Since we only have basic HashMap/(Linked)HashSet operations. For details,
# Our utility function insert puts the key- value pair into the cache, queries and possibly puts an empty LinedHashSet in the frequencies, then queries frequencies again and adds a key into the associated value which is a LinkedHashSet. All the operations are based on the hash calculating for simple type (int or Integer) and the time complexity is constant.
# For each get operation, in the worst case, we query the frequencies and remove a key from the associated value which is a LinkedHashSet and call insert function once. All the operations have the constant time complexity based on the hash calculating for simple type.
# For each put operation, in the simple case we just insert the new key-value pair into the cache and call get function once. In the worst case, we query the frequencies to get the associated value, namely all the keys with the same frequencies which is a LinkedHashSet. And then we get the first key from the LinkedHashSet, remove it from both cache and frequencies. All the operations have the constant time complexity based on the hash calculating for simple type.

# Space complexity: O(N).
# We save all the key-value pairs as well as all the keys with frequencies in the 2 HashMaps (plus a LinkedHashSet), so there are at most $min(N, capacity) keys and values at any given time.
