# https://leetcode.com/problems/meeting-rooms-ii/description/

'''
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:
Input: intervals = [[7,10],[2,4]]
Output: 1

Constraints:
1 <= intervals.length <= 104
0 <= starti < endi <= 106
'''

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        free_rooms=[]
        intervals.sort(key=lambda x:x[0])

        heappush(free_rooms,intervals[0][1])

        for i in intervals[1:]:
            if free_rooms[0]<=i[0]:
                heappop(free_rooms)
            heappush(free_rooms,i[1])
        return len(free_rooms)

# Complexity Analysis

# Time Complexity: O(NlogN).
# There are two major portions that take up time here. One is sorting of the array that takes O(NlogN) considering that the array consists of N elements.
# Then we have the min-heap. In the worst case, all N meetings will collide with each other. In any case we have N add operations on the heap. In the worst case we will have N extract-min operations as well. Overall complexity being (NlogN) since extract-min operation on a heap takes O(logN).

# Space Complexity: O(N) because we construct the min-heap and that can contain N elements in the worst case as described above in the time complexity section. Hence, the space complexity is O(N).
