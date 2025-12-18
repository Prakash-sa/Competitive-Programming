# https://leetcode.com/problems/meeting-rooms/description/

'''
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:
Input: intervals = [[7,10],[2,4]]
Output: true

Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106
'''

class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key=lambda x:x[0])

        for i in range(len(intervals)-1):
            if intervals[i][1]>intervals[i+1][0]:
                return False
        return True        
    


# Complexity Analysis
# Time complexity: O(nlogn).
# The time complexity is dominated by the sorting step. Once the array has been sorted, only O(n) time is required to go through the array and determine if there is any overlap.

# Space complexity: O(logn) or O(n)
# Note that some extra space is used when we sort an array in place. The space complexity of the sorting algorithm depends on the programming language.

# In Python, the sort method sorts a list using the Tim Sort algorithm which is a combination of Merge Sort and Insertion Sort and has O(n) additional space. Additionally, Tim Sort is designed to be a stable algorithm.
# In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of O(logn) for sorting an array.
