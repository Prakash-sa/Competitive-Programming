# https://leetcode.com/problems/meeting-rooms-iii/description/

'''
You are given an integer n. There are n rooms numbered from 0 to n - 1.
You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.
Meetings are allocated to rooms in the following manner:
Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.
A half-closed interval [a, b) is the interval between a and b including a and not including b.

Example 1:
Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
Example 2:
Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 

Constraints:
1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.
'''


class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        count=[0]*n
        available=list(range(n))
        busy=[]

        for start,end in meetings:
            while busy and busy[0][0]<=start:
                _,room=heappop(busy)
                heappush(available,room)
            
            if available:
                room=heappop(available)
                heappush(busy,(end,room))
                count[room]+=1
            else:
                earliest_end,room=heappop(busy)
                heappush(busy,(earliest_end+(end-start),room))
                count[room]+=1

        maxi=max(count)

        for i in range(n):
            if count[i]==maxi:
                return i
        return -1


# Complexity Analysis
# Let N be the number of rooms.
# Let M be the number of meetings.

# Time complexity: O(M⋅logM+M⋅logN+N⋅logN)
# Sorting meetings will incur a time complexity of O(M⋅logM).
# Popping and pushing into the priority queue will each cost O(logN). These priority queue operations run inside a for loop that runs at most M times, leading to a time complexity of O(M⋅logN).
# The inner nested loop will incur a time complexity of O(logN). Additionally, initializing the heap of unused rooms takes O(N⋅logN) time in languages like C++ and Java.
# The combined time complexity is O(M⋅logM+M⋅logN+N⋅logN). As per the constraints, N is small, so the term O(M⋅logM) will typically dominate.

# Space complexity: O(N+sort).
# Initializing unused_rooms and meeting_count will incur a space complexity of O(N). Some extra space is used when we sort an array of size N in place. The space complexity of the sorting algorithm depends on the programming language.
# In Python, the sort method sorts a list using the Timsort algorithm which is a combination of Merge Sort and Insertion Sort and has a space complexity of O(N).

