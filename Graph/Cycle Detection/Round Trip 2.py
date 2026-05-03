# https://maang.in/problems/Round-Trip-II-388?resourceUrl=cs214-cp873-pl3339-rs388&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
Zenithland has n cities and m flight connections. Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
For java please use Fast I/O

Input Format
The first line contains T - Number of test cases.

First input line of each test case has two integers n and m: the number of cities and flights. The cities are numbered
1,2,…,n.
Then, for each test case, there are m lines describing the flights. Each line has two integers a and b: there is a flight connection from city a to city b. All connections are one-way flights from a city to another city.

Output Format
For each test case, Print "Yes" if such round trip exists, otherwise print "No" in a new line.

Constraints
1≤T≤10
1≤n≤105
1≤m≤2⋅105
1≤a,b≤n

Sample Input 1
1
4 5
1 3
2 1
2 4
3 2
3 4
Sample Output 1
Yes
"""


import sys
from sys import stdin, stdout

sys.setrecursionlimit(10**7)


def dfs(v, par, color, adj):
    color[v] = 1
    for u in adj[v]:
        if color[u] == 0:
            if dfs(u, v, color, adj):
                return True
        elif color[u] == 1:
            return True
    color[v] = 2
    return False


def main():
    data = stdin.read().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
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

        color = [0] * (n + 1)
        flag = False
        for v in range(1, n + 1):
            if color[v] == 0:
                if dfs(v, -1, color, adj):
                    stdout.write("Yes\n")
                    flag = True
                    break
        if not flag:
            stdout.write("No\n")


if __name__ == "__main__":
    main()

'''
Time: O(n + m) per test case
Space: O(n + m) per test case.

Time Complexity per test case: 
O(n+m) because each vertex and edge is processed at most once.

Space Complexity per test case: 
O(n+m) for the adjacency list and O(n) for the color array.
'''
