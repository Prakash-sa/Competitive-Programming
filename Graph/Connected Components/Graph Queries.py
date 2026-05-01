# https://maang.in/problems/Easy-Graph-Queries-400?resourceUrl=cs214-cp873-pl3337-rs400&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
You are given an undirected graph G with N nodes and M edges. You have to answer Q queries. Each query is one of the following two types.

Type 1: 1 X — print the size of the connected component containing node
Type 2: 2 X Y — print YES if nodes X and Y are in the same connected component, otherwise print NO.

Input Format
The first line contains three space-separated integers
N, M, Q
The next M lines each contain two integers u, v denoting an undirected edge between nodes u and v.

Each of the next Q lines contains a single query in one of the formats: 1X 2 X Y

Output Format
Print
Q lines as the answers to the
Q
Q queries, each on a new line.
Constraints
1≤N,M,Q≤105

Sample Input 1
6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6
Sample Output 1
3
1
NO
2
YES
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


def solve():
    [n, m, q] = list_ints()
    adj_list = defaultdict(list)
    for i in range(m):
        [u, v] = list_ints()
        if u != v:
            adj_list[u].append(v)
            adj_list[v].append(u)

    comp_id = [-1] * (n + 1)
    cid = 0
    comp_size = []

    for node in range(1, n + 1):
        if comp_id[node] == -1:
            size = 0
            stack = [node]
            comp_id[node] = cid

            while stack:
                child = stack.pop()
                size += 1
                for nei in adj_list[child]:
                    if comp_id[nei] == -1:
                        comp_id[nei] = cid
                        stack.append(nei)
            cid += 1
            comp_size.append(size)

    for _ in range(q):
        query_list = list_ints()
        if len(query_list) == 2:
            write_line(comp_size[comp_id[query_list[1]]])
        else:
            if comp_id[query_list[1]] == comp_id[query_list[2]]:
                write_line("YES")
            else:
                write_line("NO")


if __name__ == "__main__":
    solve()

"""
No recursive DFS because of the stack overflow risk
✅ Time Complexity
Build graph: O(N + M)
DFS traversal (all nodes): O(N + M)
Each query:
Type 1 (size): O(1)
Type 2 (connected?): O(1)

👉 Total:

O(N+M+Q)
✅ Space Complexity
Adjacency list: O(N + M)
Component array (comp_id): O(N)
Component sizes: O(N) (worst case)

👉 Total:

O(N+M)
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
    [n, m, q] = list_ints()
    dsu = DSU(n)
    for i in range(m):
        [u, v] = list_ints()
        dsu.union(u, v)

    for _ in range(q):
        query_list = list_ints()
        if len(query_list) == 2:
            write_line(dsu.component_size(query_list[1]))
        else:
            if dsu.find(query_list[1]) == dsu.find(query_list[2]):
                write_line("YES")
            else:
                write_line("NO")


if __name__ == "__main__":
    solve()

"""
✅ Time Complexity
Each union / find: O(α(N)) (inverse Ackermann, ~constant)
Processing edges: O(M α(N))
Each query: O(α(N))

👉 Total:

O((N+M+Q)α(N))≈O(N+M+Q)
✅ Space Complexity
Parent array: O(N)
Size array: O(N)

👉 Total:

O(N)
"""
