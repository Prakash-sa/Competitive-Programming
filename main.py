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


def dfs(x, y, grid, n, m,vis):
    if vis[x][y]:
        return
    vis[x][y] = True
    for dx, dy in direction:
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == ".":
            dfs(nx, ny, grid, n, m,vis)


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
                dfs(i, j, grid, n, m,vis)
                component += 1
    write_line(component)


if __name__ == "__main__":
    solve()
