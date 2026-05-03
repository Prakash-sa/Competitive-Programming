# https://maang.in/problems/Round-Trip-194?resourceUrl=cs214-cp873-pl3339-rs194&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
Zenithland has n cities and m roads between them. Your task is to check for the existence of a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input Format
The first input line has two integers n and m: the number of cities and roads. The cities are numbered
1,2,…,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities. Every road is between two different cities, and there is at most one road between any two cities. The roads are undirected.

Output Format
Print YES if such a round trip exists, otherwise print NO.

Constraints
1≤n≤10
1≤m≤2×105
1≤a,b≤n

Sample Input 1
5 6
1 3
1 2
5 3
1 5
2 4
4 5
Sample Output 1
YES
Sample Input 2
4 3
1 2
1 3
3 4
Sample Output 2
NO
"""

import sys
from sys import stdin, stdout

sys.setrecursionlimit(10**7)

cycle_start = -1
cycle_end = -1


def dfs(v, par, color, adj, parent):
    global cycle_start, cycle_end

    color[v] = 1

    for u in adj[v]:
        if u == par:
            continue

        if color[u] == 0:
            parent[u] = v

            if dfs(u, v, color, adj, parent):
                return True

        elif color[u] == 1:
            cycle_start = u
            cycle_end = v
            return True

    color[v] = 2
    return False


def main():
    global cycle_start, cycle_end

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

    color = [0] * (n + 1)
    parent = [-1] * (n + 1)

    for v in range(1, n + 1):
        if color[v] == 0:
            if dfs(v, -1, color, adj, parent):
                break

    if cycle_start == -1:
        stdout.write("NO\n")
    else:
        stdout.write("YES\n")


if __name__ == "__main__":
    main()

"""
Time Complexity per test case:
O(n+m)

Space Complexity per test case: 
O(n+m) (for adjacency lists and arrays)
"""
