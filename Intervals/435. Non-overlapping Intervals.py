# https://leetcode.com/problems/non-overlapping-intervals/description/

'''
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
 

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:
1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
'''

from collections import List

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:x[1])
        ans=0
        k=float(-'inf')
        for x,y in intervals:
            if x>=k:
                k=y
            else:
                ans+=1
        return ans
        
# Complexity Analysis
# Given n as the length of intervals,
# Time complexity: O(n⋅logn)
# We sort intervals, which costs O(n⋅logn). Then, we iterate over the input, performing constant time work at each iteration. This means the iteration costs O(n), which is dominated by the sort.

# Space Complexity: O(logn) or O(n)
# The space complexity of the sorting algorithm depends on the implementation of each programming language:
# In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm, which has a space complexity of O(logn)
# In C++, the sort() function provided by STL uses a hybrid of Quick Sort, Heap Sort and Insertion Sort, with a worst case space complexity of O(logn)
# In Python, the sort() function is implemented using the Timsort algorithm, which has a worst-case space complexity of O(n)
