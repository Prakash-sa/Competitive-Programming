# https://maang.in/problems/One-Piece-902?resourceUrl=cs214-cp873-pl3343-rs902&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

'''
Description
Monkey D. Luffy, on his journey of becoming the "King of Pirates" and to conquer the "One Piece", wants to travel across the Grand Line. Grand Line is a mysterious sea, and is in the shape of a N×M grid S with every cell denoting the wind direction. The sign of 
S[i][j] can be: 1 which means wind in the cell flows to the right (i.e. from 
S[i][j] to 
S[i][j+1]), 2 which means wind in the cell flows to the left (i.e. from 
S[i][j] to 
S[i][j−1]), 
3 which means wind in the cell flows downwards (i.e. from 
S[i][j] to 
S[i+1][j]), or 
4 which means wind in the cell flows upwards (i.e. from 
S[i][j] to 
S[i−1][j]). Notice that there could be some signs on the cells of the grid 
S that point outside the Grand Line sea grid.

Merry, Luffy's ship, can only sail along the wind direction and cannot go outside the Grand Line sea grid 
S at any point. Luffy can modify the wind's direction on a cell with a 
cost=1 (he can modify the sign on a cell one time only).

Find the minimum cost to make Luffy's voyage from the top-left corner of the Grand Line, i.e., 
S[1][1], to its bottom-right corner, i.e., 
S[N][M], possible.

Input Format
Input is given from Standard Input in the following format:
S 1,1 S 1,2
​ …S 
1,M
 
Output Format
Print the minimum total cost required to make a path from 
S[1][1] to 
S[N][M].

Constraints
2≤N,M≤1000.
N and M are integers.

Sample Input 1
4 4
1 1 1 1
2 2 2 2
1 1 1 1
2 2 2 2
Sample Output 1
3
Sample Input 2
3 3
1 1 3
3 2 2
1 1 4
Sample Output 2
0
'''
# Write your code here
import sys
from collections import deque

input=sys.stdin.readline

INF=10**18

dirs=[
    (0,1),
    (0,-1),
    (1,0),
    (-1,0)
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


# Time Complexity per test case: O(N×M) because each cell is processed at most a constant number of times and there are 4 edges per cell.

# Space Complexity per test case: O(N×M) for the distance matrix and the deque.
