# https://maang.in/problems/Connected-Component-Size-684?resourceUrl=cs214-cp873-pl3338-rs684&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
You have a 2-D array of size N×M. Consider connected 0's (which share a common edge) as one single component and 1's as walls. Replace 0's with the size of the connected component but if the size of the component is one, then leave it with 0.

Input Format
The first line contains a single integer t, the number of test cases. For each test case, the first line contains two integers
N and M and then there are N lines containing N×M binary matrix.

Output Format
For each test case, print the final matrix after replacing all the 0's accordingly.

Constraints
(N×M) over all test cases ≤2×105

0≤Ai≤1

Sample Input 1
2
2 2
0 1
1 0
6 5
1 0 0 1 0
0 1 0 0 0
0 0 1 1 0
0 1 1 0 1
1 1 1 1 1
0 1 0 0 0
Sample Output 1
0 1
1 0
1 7 7 1 7
4 1 7 7 7
4 4 1 1 7
4 1 1 0 1
1 1 1 1 1
0 1 3 3 3
"""


import sys
from collections import deque

input = sys.stdin.readline
print = sys.stdout.write

direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]


def list_ints():
    return list(map(int, input().split()))


def bfs(x, y, grid):
    vis = set()
    vis.add((x, y))

    q = deque([(x, y)])
    size = 0

    while q:
        x, y = q.popleft()
        size += 1

        for dx, dy in direction:
            nx, ny = x + dx, y + dy

            if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]):
                if (nx, ny) in vis or grid[nx][ny] == "1":
                    continue

                vis.add((nx, ny))
                q.append((nx, ny))

    return size


def solve():
    t = int(input())

    for _ in range(t):
        n, m = list_ints()

        grid = []
        for _ in range(n):
            grid.append(input().strip().split())

        ans = []

        for i in range(n):
            row = []
            for j in range(m):
                if grid[i][j] == "1":
                    row.append("1")
                else:
                    size = bfs(i, j, grid)
                    row.append("0" if size == 1 else str(size))

            ans.append(" ".join(row))

        print("\n".join(ans) + "\n")


if __name__ == "__main__":
    solve()

    import sys
from collections import deque

input = sys.stdin.readline
print = sys.stdout.write

direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]


def list_ints():
    return list(map(int, input().split()))


def solve():
    t = int(input())

    for _ in range(t):
        n, m = list_ints()

        # for "0 1 0" input
        grid = [input().strip().split() for _ in range(n)]
        # if input is "010", use:
        # grid = [list(input().strip()) for _ in range(n)]

        comp_id = [[-1] * m for _ in range(n)]
        comp_size = []
        cid = 0

        # BFS to find components of '0'
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "0" and comp_id[i][j] == -1:
                    q = deque([(i, j)])
                    comp_id[i][j] = cid
                    size = 1

                    while q:
                        x, y = q.popleft()

                        for dx, dy in direction:
                            nx, ny = x + dx, y + dy

                            if 0 <= nx < n and 0 <= ny < m:
                                if grid[nx][ny] == "0" and comp_id[nx][ny] == -1:
                                    comp_id[nx][ny] = cid
                                    q.append((nx, ny))
                                    size += 1

                    comp_size.append(size)
                    cid += 1

        # Build answer
        ans = []
        for i in range(n):
            row = []
            for j in range(m):
                if grid[i][j] == "1":
                    row.append("1")
                else:
                    size = comp_size[comp_id[i][j]]
                    row.append("0" if size == 1 else str(size))
            ans.append(" ".join(row))

        print("\n".join(ans) + "\n")


if __name__ == "__main__":
    solve()


"""
Time Complexity per test case: O(N×M). Space Complexity per test case: O(N×M).
"""
