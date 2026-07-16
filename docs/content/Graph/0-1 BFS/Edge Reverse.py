# https://maang.in/problems/Edge-Reverse-900?resourceUrl=cs214-cp873-pl3343-rs900&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

'''
Description
Given a directed graph with N vertices and M edges. What is the minimum number of edges needed to reverse in order to have at least one path from vertex 1 to vertex N, where the vertices are numbered from 1 to N?

Input Format
The first line contains T - the number of test cases.
The first line of each test case contains two space-separated integers N and M, denoting the number of vertices and the number of edges in the graph respectively. The ithith line of the next M lines of each test case contains two space-separated integers Xi and Yi, denoting that the ithith edge connects vertices from Xi to Yi.
Output Format
For each test case, in a single line, print the minimum number of edges we need to revert. If there is no way of having at least one path from 1 to N, print −1.

Constraints
1≤T≤10
1≤N,M≤105
1≤Xi,Yi≤N
There can be multiple edges connecting the same pair of vertices. There can be self-loops too, i.e., Xi=Yi.

Sample Input 1
1
7 7
1 2
3 2
3 4
7 4
6 2
5 6
7 5
Sample Output 1
2
'''

# Write your code here
import sys
from collections import deque

input = sys.stdin.readline
INF = 10**18


def solve():
    t = int(input())
    ans = []

    for _ in range(t):
        n, m = map(int, input().split())

        adj = [[] for _ in range(n + 1)]

        for _ in range(m):
            u, v = map(int, input().split())

            adj[u].append((v, 0))  # original edge
            adj[v].append((u, 1))  # reversed edge

        dist = [INF] * (n + 1)
        dist[1] = 0

        dq = deque([1])

        while dq:
            node = dq.popleft()

            for nei, cost in adj[node]:
                if dist[node] + cost < dist[nei]:
                    dist[nei] = dist[node] + cost

                    if cost == 0:
                        dq.appendleft(nei)
                    else:
                        dq.append(nei)

        ans.append(str(dist[n] if dist[n] != INF else -1))

    sys.stdout.write("\n".join(ans))


if __name__ == "__main__":
    solve()

'''
Time Complexity per test case: O(N+M).

Space Complexity per test case: O(N+M).
'''