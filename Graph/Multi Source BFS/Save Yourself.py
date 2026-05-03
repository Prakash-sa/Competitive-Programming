# https://maang.in/problems/Save-Yourself-195?resourceUrl=cs214-cp873-pl3340-rs195&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

"""
Description
You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input Format
The first input line has two integers n and m: the height and width of the matrix.
After this, there are n lines of m characters describing the matrix. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.

Output Format
First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest path that you'll follow.

Constraints
1≤n,m≤1000

Sample Input 1
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
Sample Output 1
YES
5
Sample Input 2
1 3
##A
Sample Output 2
YES
0
Sample Input 3
3 3
###
#A#
#M.
Sample Output 3
NO
"""

# Write your code here
import sys
from collections import deque

input=sys.stdin.readline

INF=10**18
dirs=[(1,0),(0,1),(-1,0),(0,-1)]

def solve():
    n,m=list(map(int,input().split()))
    grid=[]
    monster=[]
    start=None

    for i in range(n):
        row=list(input().strip())
        grid.append(row)
        for j in range(m):
            if row[j]=='M':
                monster.append((i,j))
            elif row[j]=='A':
                start=(i,j)
    
    monster_time=[[INF]*m for _ in range(n)]
    q=deque()

    for x,y in monster:
        monster_time[x][y]=0
        q.append((x,y))
    
    while q:
        x,y=q.popleft()
        for dx,dy in dirs:
            nx,ny=x+dx,y+dy
            if 0<=nx<n and 0<=ny<m:
                if grid[nx][ny]!='#' and monster_time[nx][ny]==INF:
                    monster_time[nx][ny]=monster_time[x][y]+1
                    q.append((nx,ny))

    sx,sy=start
    if sx==0 or sx==n-1 or sy==0 or sy==m-1:
        sys.stdout.write("YES\n")
        sys.stdout.write(str(0))
        return
    
    dist=[[-1]*m for _ in range(n)]
    q=deque([(sx,sy)])
    dist[sx][sy]=0

    while q:
        x,y=q.popleft()
        for dx,dy in dirs:
            nx,ny=x+dx,y+dy
            if 0<=nx<n and 0<=ny<m:
                if grid[nx][ny]=='#' or dist[nx][ny]!=-1:
                    continue
                
                new_time=dist[x][y]+1

                if new_time>=monster_time[nx][ny]:
                    continue
                dist[nx][ny]=new_time

                if nx==0 or nx==n-1 or ny==0 or ny==m-1:
                    sys.stdout.write("YES\n")
                    sys.stdout.write(str(new_time))
                    return
                q.append((nx,ny))
    sys.stdout.write("NO")


if __name__=='__main__':
    solve()


