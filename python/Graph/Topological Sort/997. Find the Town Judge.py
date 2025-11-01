# https://leetcode.com/problems/find-the-town-judge/description/

'''
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

Example 1:
Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Constraints:
1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
'''

from collections import List

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        indegree=[0]*(n+1)
        outdegree=[0]*(n+1)

        for i in range(len(trust)):
            outdegree[trust[i][0]]+=1
            indegree[trust[i][1]]+=1
        
        for i in range(1,n+1):
            if outdegree[i]==0 and indegree[i]==n-1:
                return i
        return -1
        
    
# Complexity Analysis
# Let N be the number of people, and E be the number of edges (trust relationships).
# Time Complexity : O(E).
# We loop over the trust list once. The cost of doing this is O(E).
# We then loop over the people. The cost of doing this is O(N).
# Going by this, it now looks this is one those many graph problems where the cost is O(max(N,E)=O(N+E). After all, we don't know whether E or N is the bigger one, right?
# However, remember how we terminate early if E<N−1? This means that in the best case, the time complexity is O(1). And in the worst case, we know that E≥N−1. For the purpose of big-oh notation, we ignore the constant of 1. Therefore, in the worst case, E has to be bigger, and so we can simply drop the N, leaving O(E).
# Space Complexity : O(N).


# Bonus
# Can There Be More Than One Town Judge?
# In the problem description, we're told that iff there is a town judge, there'll only be one town judge.
# It's likely that not all interviewers would tell you directly that there can only be one town judge. If you asked them whether or not there could be more than one town judge, they might ask you if there could be. And the answer is... it's impossible!
# If there were two town judges, then they would have to trust each other, otherwise we'd have a town judge not trusted by everybody. But this doesn't work, because town judges aren't supposed to trust anybody. Therefore, we know there can be at most one town judge.
