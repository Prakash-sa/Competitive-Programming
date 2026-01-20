# https://leetcode.com/problems/design-hashset/description/

'''
Design a HashSet without using any built-in hash table libraries.
Implement MyHashSet class:
void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

Example 1:
Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 
Constraints:
0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.
'''

class MyHashSet:

    def __init__(self):
        self.size=2069
        self.buckets=[[] for _ in range(self.size)]
        
    def _hash(self,key):
        return key%self.size

    def add(self, key: int) -> None:
        h=self._hash(key)
        if key not in self.buckets[h]:
            self.buckets[h].append(key)

    def remove(self, key: int) -> None:
        h=self._hash(key)
        if key in self.buckets[h]:
            self.buckets[h].remove(key)

    def contains(self, key: int) -> bool:
        h=self._hash(key)
        if key in self.buckets[h]:
            return True
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)


# Complexity Analysis

# Time Complexity: O(N/K) where N is the number of all possible values and K is the number of predefined buckets, which is 769.
# Assuming that the values are evenly distributed, thus we could consider that the average size of bucket is K N.
# Since for each operation, in the worst case, we would need to scan the entire bucket, hence the time complexity is O(KN).

# Space Complexity: O(K+M) where K is the number of predefined buckets, and M is the number of unique values that have been inserted into the HashSet.
