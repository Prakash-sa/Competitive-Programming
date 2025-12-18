# https://leetcode.com/problems/task-scheduler/description/

# https://www.youtube.com/watch?v=s8p8ukTyA2I

'''
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
Return the minimum number of CPU intervals required to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

Constraints:
1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
'''

from collections import List,Counter,deque
import heapq


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq=Counter(tasks)
        arr=[-cnt for cnt in freq.values()]
        heapq.heapify(arr)
        q=deque()
        time=0

        while q or arr:
            time+=1
            if arr:
                cnt=1+heapq.heappop(arr)
                if cnt<0:
                    q.append((cnt,time+n))
            if q and q[0][1]==time:
                heapq.heappush(arr,q[0][0])
                q.popleft()
        return time
    
# Complexity Analysis
# Let the number of tasks be N. Let k be the size of the priority queue. k can, at maximum, be 26 because the priority queue stores the frequency of each distinct task, which is represented by the letters A to Z.
# Time complexity: O(N)
# In the worst case, all tasks must be processed, and each task might be inserted and extracted from the priority queue. The priority queue operations (insertion and extraction) have a time complexity of O(logk) each. Therefore, the overall time complexity is O(N⋅logk). Since k is at maximum 26, logk is a constant term. We can simplify the time complexity to O(N). This is a linear time complexity with a high constant factor.

# Space complexity: O(26) = O(1)
# The space complexity is mainly determined by the frequency array and the priority queue. The frequency array has a constant size of 26, and the priority queue can have a maximum size of 26 when all distinct tasks are present. Therefore, the overall space complexity is O(1) or O(26), which is considered constant.