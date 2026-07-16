# https://maang.in/problems/One-Edge-196?resourceUrl=cs214-cp873-pl3337-rs196&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
You are given an undirected graph with n nodes, and m edges between them. The nodes are numbered 1,2,…,n. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases. Your task is to find the number of ways to add such an edge.

Input Format
The first input line has two integers n and m: the number of nodes and edges. After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes. An edge always connects two different nodes, and there is at most one edge between any two nodes.

Output Format
Print the number of ways to add such an edge, described in the statement.

Constraints
1≤n≤105

1≤m≤2×105
1≤a,b≤n

Sample Input 1
5 4
1 2
2 3
1 3
4 5
Sample Output 1
6
Sample Input 2
4 3
1 2
2 3
3 4
Sample Output 2
0
"""

# DSU solution

import sys
from collections import defaultdict

input = sys.stdin.readline
print = sys.stdout.write
sys.setrecursionlimit(1 << 25)

MOD = 10**9 + 7
INF = 10**18


def read():
    return sys.stdin.buffer.read()


def ints():
    return map(int, input().split())


def list_ints():
    return list(map(int, input().split()))


def write_line(value=""):
    sys.stdout.write(str(value) + "\n")


def write_lines(values):
    sys.stdout.write("\n".join(map(str, values)))
    if values:
        sys.stdout.write("\n")


class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)

    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, x, y):
        ra = self.find(x)
        rb = self.find(y)

        if ra == rb:
            return

        if self.size[ra] < self.size[rb]:
            ra, rb = rb, ra

        self.parent[rb] = ra
        self.size[ra] += self.size[rb]

    def component_size(self, x):
        return self.size[self.find(x)]


def solve():
    [n, m] = list_ints()
    dsu = DSU(n)
    for i in range(m):
        [u, v] = list_ints()
        dsu.union(u, v)
    freq = defaultdict(int)
    for i in range(1, n + 1):
        freq[dsu.find(i)] = dsu.component_size(i)

    ans = 1
    if len(freq) == 1:
        write_line(0)
        return
    total = 0
    square_total = 0
    for value in freq.values():
        total += value
        square_total += value * value
    write_line((total**2 - square_total) // 2)


if __name__ == "__main__":
    solve()

## DFS solution
from sys import stdin, stdout


def main():
    data = stdin.read().split()
    idx = 0
    n = int(data[idx])
    idx += 1
    m = int(data[idx])
    idx += 1
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = int(data[idx])
        v = int(data[idx + 1])
        idx += 2
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * (n + 1)
    sqsum = 0
    total = 0
    for i in range(1, n + 1):
        if not visited[i]:
            temp = 0
            stack = [i]
            while stack:
                cur = stack.pop()
                if visited[cur]:
                    continue
                visited[cur] = True
                temp += 1
                for u in graph[cur]:
                    if not visited[u]:
                        stack.append(u)
            sqsum += temp * temp
            total += temp
    ans = (total * total - sqsum) // 2
    stdout.write(str(ans))


if __name__ == "__main__":
    main()
