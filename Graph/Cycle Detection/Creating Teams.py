# https://maang.in/problems/Creating-Teams-193?resourceUrl=cs214-cp873-pl3339-rs193&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D


"""
Description
There are n students in the AlgoZenith course and m friendships between them. Your task is to divide the students into two teams in such a way that no two students in a team are friends. You can freely choose the sizes of the teams. The size of each team should be positive.

Input Format
The first input line has two integers n and m: the number of students and friendships. The students are numbered
1,2,…,n.
Then, there are m lines describing friendships. Each line has two integers a and b: students a and b are friends.
Every friendship is between two different students. You can assume that there is at most one friendship between any two students.

Output Format
Print YES if it's possible to divide students in two teams, otherwise print NO.

Constraints
1≤n≤105
0≤m≤2×105
1≤a,b≤n

Sample Input 1
5 3
1 2
1 3
4 5
Sample Output 1
YES
Sample Input 2
4 3
1 2
2 3
1 3
Sample Output 2
NO
"""

import sys
from sys import stdin, stdout

sys.setrecursionlimit(10**7)


def dfs(v, c, color, adj):
    color[v] = c
    for u in adj[v]:
        if color[u] == -1:
            if not dfs(u, 1 - c, color, adj):
                return False
        elif color[u] == color[v]:
            return False
    return True


def main():
    data = stdin.read().split()
    idx = 0
    n = int(data[idx])
    idx += 1
    m = int(data[idx])
    idx += 1
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = int(data[idx])
        v = int(data[idx + 1])
        idx += 2
        adj[u].append(v)
        adj[v].append(u)
    color = [-1] * (n + 1)
    for v in range(1, n + 1):
        if color[v] == -1:
            if not dfs(v, 0, color, adj):
                stdout.write("NO\n")
                return
    stdout.write("YES\n")


if __name__ == "__main__":
    main()


"""
⏱️ Time Complexity
O(N + M)

Where:

N = number of nodes
M = number of edges
Why?
Each node is visited once
Each edge is checked twice (undirected)
💾 Space Complexity
O(N + M)
Breakdown:
adj list → O(N + M)
color array → O(N)
recursion stack (DFS) / queue (BFS) → O(N) worst case
"""
