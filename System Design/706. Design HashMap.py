# https://leetcode.com/problems/design-hashmap/description/

'''
Design a HashMap without using any built-in hash table libraries.
Implement the MyHashMap class:
MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

Example 1:
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]
Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

Constraints:
0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.
'''


class MyHashMap:
    def __init__(self):
        self.size=2069
        self.buckets=[[] for _ in range(self.size)]

    def _hash(self,key):
        return key%self.size

    def put(self, key: int, value: int) -> None:
        h=self._hash(key)
        for i,(k,v) in enumerate(self.buckets[h]):
            if k==key:
                self.buckets[h][i]=(key,value)
                return
        self.buckets[h].append((key,value))

    def get(self, key: int) -> int:
        h=self._hash(key)
        for k,v in self.buckets[h]:
            if k==key:
                return v
        return -1

    def remove(self, key: int) -> None:
        h=self._hash(key)
        for i,(k,v) in enumerate(self.buckets[h]):
            if k==key:
                self.buckets[h].pop(i)
                return



# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)

'''

Complexity Analysis

Time Complexity: O(N/K) where N is the number of all possible keys and K is the number of predefined buckets in the hashmap, which is 2069 in our case.
In the ideal case, the keys are evenly distributed in all buckets. As a result, on average, we could consider the size of the bucket is KN.
Since in the worst case we need to iterate through a bucket to find the desire value, the time complexity of each method is O(KN).

Space Complexity: O(K+M) where K is the number of predefined buckets in the hashmap and M is the number of unique keys that have been inserted into the hashmap.
'''