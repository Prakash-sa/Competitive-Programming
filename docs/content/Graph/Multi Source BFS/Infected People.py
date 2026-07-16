# https://maang.in/problems/Infected-People-589?resourceUrl=cs214-cp873-pl3340-rs589&returnUrl=%5B%22%2Fcourses%2FGraph-Level-1-214%3Ftab%3Dchapters%22%5D

'''
Description
Your city is represented as a grid with n rows and m columns.
Cells containing 2 are cells where people infected with the virus are present, cells containing 1 are cells with people not yet infected, and cells containing 0 are empty.

Every unit of time, infected people infect all their adjacent cells (up, down, left, right). The virus cannot pass through empty cells.

Print the minimum time in which all the people are infected. If not everyone can be infected, print −1.

Input Format
The first line contains two integers n and m — the number of rows and columns, respectively.

The following n lines contain m integers each; the j-th element in the i-th line is the number written in the j-th cell of the i-th row.

Output Format
Print the minimum time in which everyone can be infected −1 if everyone cannot be infected.
Constraints
1≤n≤1000
1≤m≤1000
Sample Input 1
3 3
0 1 2
0 1 2
1 1 2
Sample Output 1
2
Sample Input 2
3 3
0 1 2
0 1 2
1 0 2
Sample Output 2
-1
'''


import sys
from collections import deque

input=sys.stdin.readline

INF=10**18
dirs=[(1,0),(0,1),(-1,0),(0,-1)]

def solve():
    n,m=list(map(int,input().split()))
    grid=[]
    q=deque()

    fresh=0

    for i in range(n):
        row=list(map(int,input().split()))
        grid.append(row)
        for j in range(m):
            if row[j]==2:
                q.append((i,j,0))
            if row[j]==1:
                fresh+=1
    
    ans=0
    
    while q:
        x,y,time=q.popleft()
        ans=max(ans,time)
        for dx,dy in dirs:
            nx,ny=x+dx,y+dy
            if 0<=nx<n and 0<=ny<m and grid[nx][ny]==1:
                grid[nx][ny]=2
                fresh-=1
                q.append((nx,ny,time+1))


    if fresh>0:
        sys.stdout.write("-1")
    else:
        sys.stdout.write(str(ans))

if __name__=='__main__':
    solve()


'''
Time Complexity per test case: O(n×m) because each cell is visited at most once in BFS.

Space Complexity per test case: O(n×m) for the distance matrix and the queue.
'''
