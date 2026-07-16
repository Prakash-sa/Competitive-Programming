# https://maang.in/problems/Building-Roads-192?resourceUrl=cs214-cp873-pl3338-rs192&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
Zenithland has n cities and m roads between them. The goal is to construct new roads so that there is a route between any two cities. A road is bidirectional.

Your task is to find out the minimum number of roads required.

Input Format
The first line contains two integers n and m — the number of cities and the number of roads. The cities are numbered 1,2,…,n.

The next m lines each contain two integers a and b indicating there is a road between cities a and b.

Note -
Each road connects two different cities (a≠b)(a=b).
There is at most one road between any pair of cities.

Output Format
Print the number of Minimum roads required.
Constraints
1≤n≤105
1≤m≤2×105
1≤a,b≤n
Sample Input 1
4 2
1 2
3 4
Sample Output 1
1
"""

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


adj_list = defaultdict(list)
vis = set()


def dfs(node):
    if node in vis:
        return
    vis.add(node)
    for child in adj_list[node]:
        dfs(child)


def solve():
    [n, m] = list_ints()
    for _ in range(m):
        [u, v] = list_ints()
        adj_list[u].append(v)
        adj_list[v].append(u)

    component = 0
    for i in range(1, n + 1):
        if i not in vis:
            dfs(i)
            component += 1
    write_line(component - 1)


if __name__ == "__main__":
    solve()
