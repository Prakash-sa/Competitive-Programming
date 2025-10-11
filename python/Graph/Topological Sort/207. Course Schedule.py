#https://leetcode.com/problems/course-schedule/description/

'''
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
'''

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree=[0]*numCourses
        graph=defaultdict(list)

        for src,dist in prerequisites:
            graph[src].append(dist)
            indegree[dist]+=1
        
        q=deque([i for i in range(numCourses) if indegree[i]==0])

        count=0

        while len(q)>0:
            k=q.popleft()
            count+=1

            for neighbor in graph[k]:
                indegree[neighbor]-=1
                if indegree[neighbor]==0:
                    q.append(neighbor)
        return count==numCourses

# Complexity Analysis
# Here, n be the number of courses and m be the size of prerequisites.

# Time complexity: O(m+n)

# Initializing the adj list takes O(m) time as we go through all the edges. The indegree array take O(n) time.
# Each queue operation takes O(1) time, and a single node will be pushed once, leading to O(n) operations for n nodes. We iterate over the neighbors of each node that is popped out of the queue iterating over all the edges once. Since there are total of m edges, it would take O(m) time to iterate over the edges.

# Space complexity: O(m+n)
# The adj arrays takes O(m) space. The indegree array takes O(n) space.
# The queue can have no more than n elements in the worst-case scenario. It would take up O(n) space in that case.
