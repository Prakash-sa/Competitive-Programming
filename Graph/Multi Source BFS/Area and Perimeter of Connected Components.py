# https://maang.in/problems/Area-and-Perimeter-of-Connected-Components-422?resourceUrl=cs214-cp873-pl3340-rs422&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

'''
Description
You have been given a grid of size N×N. Each cell is either empty (.) or occupied (#). Size of each cell is 1×1. In a connected component, you can reach any cell from every other cell in the component by repeatedly stepping to adjacent cells in the north, south, east, and west directions. Your task is to find the area and perimeter of the connected component having the largest area. The area of a connected component is the number of # characters that are part of it. If multiple connected components tie for the largest area, find the smallest perimeter among them.

Input Format
The first line of input contains N, and the next N lines describe the grid. At least one # character will be present.

Output Format
Please output one line containing two space-separated integers, the first being the area of the largest connected component, and the second being its perimeter. If multiple connected components tie for the largest area, print the one which has the smallest perimeter among them.

Constraints
1≤N≤1000

Sample Input 1
6
##....
....#.
.#..#.
.#####
...###
....##
Sample Output 1
13 22
'''

import sys
from collections import deque

input = sys.stdin.readline

dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def solve():
    n = int(input())
    grid = [list(input().strip()) for _ in range(n)]

    visited = [[False] * n for _ in range(n)]

    best_area = 0
    best_perimeter = 10**18

    for i in range(n):
        for j in range(n):
            if grid[i][j] == '#' and not visited[i][j]:
                q = deque([(i, j)])
                visited[i][j] = True

                area = 0
                perimeter = 0

                while q:
                    x, y = q.popleft()
                    area += 1

                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy

                        if nx < 0 or nx >= n or ny < 0 or ny >= n:
                            perimeter += 1
                        elif grid[nx][ny] == '.':
                            perimeter += 1
                        elif grid[nx][ny] == '#' and not visited[nx][ny]:
                            visited[nx][ny] = True
                            q.append((nx, ny))

                if area > best_area:
                    best_area = area
                    best_perimeter = perimeter
                elif area == best_area:
                    best_perimeter = min(best_perimeter, perimeter)

    print(best_area, best_perimeter)


if __name__ == "__main__":
    solve()


'''
Time Complexity per test case: O(N^2)
Space Complexity per test case: O(N^2) (for the grid and visited/region arrays) plus O(N^2) in the worst case for auxiliary arrays that store areas and perimeters of regions.
'''
