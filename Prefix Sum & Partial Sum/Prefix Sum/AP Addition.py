# You are given an array Arr of size N and Q update queries.
# Initially, all elements of Arr are 0.
#
# Each query has 4 integers: A, D, L, R.
# For this query, add an arithmetic progression (AP) to Arr from index L to R:
#
# Arr[L]   += A
# Arr[L+1] += A + D
# Arr[L+2] += A + 2*D
# ...
# Arr[R]   += A + (R - L)*D
#
# After processing all Q queries, print the final array values modulo (10^9 + 7).
#
# Input format:
# - First line: N Q
#   where 1 <= N <= 10^6, 1 <= Q <= 10^6
# - Next Q lines: A D L R
#   where 0 <= A, D <= 10^4 and 1 <= L <= R <= N
#
# Output format:
# - Print N space-separated integers:
#   Arr[1], Arr[2], ..., Arr[N] (each modulo 10^9 + 7)
#
# Sample Input:
# 5 5
# 1 3 1 5
# 2 4 2 2
# 5 6 3 5
# 6 9 5 5
# 1 4 2 4
#
# Sample Output:
# 1 7 17 30 36


MOD=10**9+7

# Write your code here
n,q=list(map(int,input().split()))
arr_a=[0]*(n+2)
arr_d=[0]*(n+2)
for _ in range(q):
    a,d,l,r=list(map(int,input().split()))
    arr_a[l]+=(a-d*l)%MOD
    arr_a[r+1]-=(a-d*l)%MOD
    arr_d[l]+=d
    arr_d[r+1]-=d

for i in range(1,n+1):
    arr_a[i]=(arr_a[i]+arr_a[i-1])%MOD

for i in range(1,n+1):
    arr_d[i]=(arr_d[i]+arr_d[i-1])%MOD

final_arr=[]
for i in range(1,n+1):
    final_arr.append(str((arr_a[i]+i*arr_d[i])%MOD))
print(' '.join(item for item in final_arr))

