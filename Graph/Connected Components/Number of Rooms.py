# https://maang.in/problems/Find-the-Number-of-Rooms-191?resourceUrl=cs214-cp873-pl3337-rs191&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares. Each character in the map is either

Defination of Room : A maximal connected group of floor cells (.), where connectivity is only through up, down, left, or right moves.

Input Format
The first input line has two integers n and m: the height and width of the map. Then there are n lines of m characters describing the map.

Output Format
Print one integer: the number of rooms.

Constraints
1≤n,m≤1000

Sample Input 1
5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 1
3
Note

"""

# Write your code here

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


def dfs(x, y, grid, n, m, vis):
    # if vis[x][y]:
    #     return
    # vis[x][y] = True
    # for dx, dy in direction:
    #     nx, ny = x + dx, y + dy
    #     if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == ".":
    #         dfs(nx, ny, grid, n, m,vis)

    stack = [(x, y)]
    vis[x][y] = True

    while stack:
        x, y = stack.pop()
        for dx, dy in direction:
            nx, ny = x + dx, y + dy
            if (
                0 <= nx < n
                and 0 <= ny < m
                and grid[nx][ny] == "."
                and vis[nx][ny] == False
            ):
                vis[nx][ny] = True
                stack.append((nx, ny))


def solve():
    [n, m] = list_ints()
    grid = []
    for _ in range(n):
        grid.append(input().strip())

    vis = [[False] * m for _ in range(n)]
    component = 0
    for i in range(n):
        for j in range(m):
            if not vis[i][j] and grid[i][j] == ".":
                dfs(i, j, grid, n, m, vis)
                component += 1
    write_line(component)


if __name__ == "__main__":
    solve()


"""
Time Complexity per test case: O(n×m). Space Complexity per test case: O(n×m) for the visited array and recursion stack.
"""
