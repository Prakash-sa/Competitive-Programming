# Write your code here
import sys
from collections import deque

input=sys.stdin.readline

INF=10**18

dirs=[
    (0,1),
    (1,0),
    (-1,0),
    (0,-1)
]

def solve():
    n,m=list(map(int,input().split()))
    grid=[]
    for _ in range(n):
        grid.append(list(map(int,input().split())))
    
    dist=[[INF]*m for _ in range(n)]
    dist[0][0]=0
    
    q=deque([(0,0)])
    while q:
        x,y=q.popleft()
        for k in range(4):
            nx,ny=x+dirs[k][0],y+dirs[k][1]
            if 0<=nx<n and 0<=ny<m:
                cost=0 if grid[x][y]==k+1 else 1
                if dist[x][y]+cost<dist[nx][ny]:
                    dist[nx][ny]=cost+dist[x][y]
                    if cost==0:
                        q.appendleft((nx,ny))
                    else:
                        q.append((nx,ny))
    print(dist[n-1][m-1])

if __name__=="__main__":
    solve()