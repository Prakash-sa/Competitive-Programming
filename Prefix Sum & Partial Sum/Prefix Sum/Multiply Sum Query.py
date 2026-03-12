
'''
Given an array of N integers and Q queries. In each query two integers L, R is given, you have to find (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4...A[R]*(R-L+1)) % 10^9+7.

Input Format
The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.

Output Format
For each query print the value of (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4...A[R]*(R-L+1)) % 10^9+7 in a new line.

Constraints
Sample Input 1
10 10
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9
Sample Output 1
20702
999271828
999223661
999999984
44
999538829
999318004
999506718
11778
999600930

'''


import sys

MOD=10**9+7

# Write your code here
n,q=list(map(int,input().split()))
arr=list(map(int,input().split()))
mul_arr=[arr[0]]
pre_arr=[arr[0]]

for i in range(1,n):
    pre_arr.append(pre_arr[i-1]+arr[i])
    mul_arr.append(mul_arr[i-1]+(i+1)*arr[i])

out=[]
for _ in range(q):
    l,r=list(map(int,input().split()))
    l-=1
    r-=1
    if l==0:
        s=pre_arr[r]
        w=mul_arr[r]
    else:
        s=pre_arr[r]-pre_arr[l-1]
        w=mul_arr[r]-mul_arr[l-1]
    total=w-(l)*s
    out.append(str(total%MOD))

sys.stdout.write("\n".join(out))


# Intuition:
# We need to compute:
# A[L] + 2*A[L+1] + 3*A[L+2] + ... + (R-L+1)*A[R]
#
# Note that (i - L + 1) = i - (L - 1)
#
# So:
# sum_{i=L..R} A[i] * (i-L+1)
# = sum_{i=L..R} i*A[i] - (L-1) * sum_{i=L..R} A[i]
#
# Precompute two prefix arrays:
# P1[i] = sum of A[1..i]
# P2[i] = sum of i*A[i] for i in [1..i]
#
# For each query:
# S = P1[R] - P1[L-1]
# W = P2[R] - P2[L-1]
#
# answer = W - (L-1) * S   (mod 1e9+7)
#
# This allows answering each query in O(1) time.