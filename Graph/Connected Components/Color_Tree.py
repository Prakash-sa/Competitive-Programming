"""
Description
You have been given a tree with N nodes and N−1 edges. You want to colour each node, such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent nodes (both directly connected to a common node with edges) has the same colour. Your task is to find the minimum number of colours required to accomplished this.

Input Format
The first line of input contains N. Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.

Output Format
Print the minimum number of colours required.

Constraints
1≤N≤10 5


Sample Input 1
4
1 2
4 3
2 3
Sample Output 1
3

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


direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]


def solve():
    [n] = list_ints()
    degree = [0] * (n + 1)
    for _ in range(n - 1):
        [u, v] = list_ints()
        degree[u] += 1
        degree[v] += 1

    write_line(max(degree) + 1)


if __name__ == "__main__":
    solve()

"""
Time:  O(N)
Space: O(N)
"""
