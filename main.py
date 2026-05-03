
import sys
from collections import deque

input=sys.stdin.readline

INF=10**18
dirs=[(1,0),(0,1),(-1,0),(0,-1)]

def solve():
    n,m=list(map(int,input().split()))
    grid=[]
    monster=[]

    for i in range(n):
        row=list(map(int,input().split()))
        grid.append(row)
        for j in range(m):
            if row[j]==2:
                monster.append((i,j))
    
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
                if grid[nx][ny]==1 and monster_time[nx][ny]==INF:
                    monster_time[nx][ny]=monster_time[x][y]+1
                    q.append((nx,ny))

    min_time=-1
    for i in range(n):
        for j in range(m):
            if grid[i][j]==1:
                if monster_time[i][j]==INF:
                    sys.stdout.write("-1")
                    return
                else:
                    min_time=max(min_time,monster_time[i][j]+1)
    if min_time!=-1:
        sys.stdout.write(str(min_time))

if __name__=='__main__':
    solve()


