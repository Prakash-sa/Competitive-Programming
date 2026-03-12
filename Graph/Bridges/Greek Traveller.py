'''
# Anaximander described his travels as an undirected graph:
# - Each node is a city.
# - Each edge is a bidirectional road.
#
# A "country" has these properties:
# 1. All cities inside a country are directly connected to each other
#    (i.e., each country forms a complete graph / clique).
# 2. Each country has at least 3 cities.
# 3. Between any two countries, there is exactly one connecting road.
# 4. From one country, it is possible to reach any other country
#    (the country-level graph is connected).
#
# Task:
# For each test case, determine how many countries exist in the given graph.
#
# Input format:
# - First line: integer T (number of test cases)
# - For each test case:
#   - One line with N M: number of cities and roads
#   - Next M lines: Ui Vi, an undirected road between cities Ui and Vi
#
# Output format:
# - For each test case, print one integer:
#   the number of countries visited by Anaximander.
#
# Constraints:
# - 1 <= T <= 100
# - 3 <= N <= 10^3
# - 1 <= Ui, Vi <= N
# - No self-loops or multiple edges
# - Sum of N over all test cases <= 10^3
#
# Example 1:
# Input:
# 1
# 6 7
# 1 2
# 1 3
# 2 3
# 2 4
# 4 5
# 4 6
# 5 6
# Output:
# 2
#
# Example 2:
# Input:
# 1
# 9 11
# 1 2
# 1 3
# 2 3
# 2 4
# 4 5
# 4 6
# 5 6
# 6 7
# 7 8
# 7 9
# 8 9
# Output:
# 3
#
# Example 3:
# Input:
# 1
# 3 3
# 1 3
# 2 3
# 1 2
# Output:
# 1

'''


# Write your code here

import sys
sys.setrecursionlimit(10**6)

t=int(input())

def find_bridges(node,parent,vis,tin,low,adj,bridges,timer):
    vis[node]=True
    tin[node]=low[node]=timer[0]
    timer[0]+=1
    for nei in adj[node]:
        if nei==parent:
            continue
        if vis[nei]:
            low[node]=min(low[node],tin[nei])
        else:
            find_bridges(nei,node,vis,tin,low,adj,bridges,timer)
            low[node]=min(low[node],low[nei])
            if low[nei]>tin[node]:
                bridges.add((node,nei))
                bridges.add((nei,node))

def traversal(node,vis,adj_list,bridges):
    vis[node]=True
    for nei in adj_list[node]:
        if not vis[nei] and (node,nei) not in bridges:
            traversal(nei,vis,adj_list,bridges)


for _ in range(t):
    n,m=list(map(int,input().split()))
    adj_list=[[] for _ in range(n+1)]
    
    for _ in range(m):
        u,v=list(map(int,input().split()))
        adj_list[u].append(v)
        adj_list[v].append(u)
    
    tin=[-1]*(n+1)
    low=[-1]*(n+1)
    vis=[False]*(n+1)
    bridges=set()
    timer=[0]

    find_bridges(1,-1,vis,tin,low,adj_list,bridges,timer)

    vis=[False]*(n+1)
    counteries=0

    for i in range(1,n+1):
        if not vis[i]:
            traversal(i,vis,adj_list,bridges)
            counteries+=1
    
    print(counteries)




