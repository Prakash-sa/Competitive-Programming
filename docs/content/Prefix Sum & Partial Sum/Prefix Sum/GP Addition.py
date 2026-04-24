# You are given an array Arr of size N, Q update queries, and an integer K.
# Initially, all elements of Arr are 0.
#
# Each query contains 3 integers: A, L, R.
# For each query, perform GP addition from index L to R:
#
# Arr[L]   += A
# Arr[L+1] += A * K
# Arr[L+2] += A * K^2
# Arr[L+3] += A * K^3
# ...
# Arr[R]   += A * K^(R-L)
#
# After processing all queries, print the final array values modulo (10^9 + 7).
#
# Input format:
# - First line: N Q K
#   where 1 <= N <= 10^6, 1 <= Q <= 10^6, 1 <= K <= 10^9
# - Next Q lines: A L R
#   where 0 <= A <= 10^4 and 1 <= L <= R <= N
#
# Output format:
# - Print N space-separated integers:
#   Arr[1], Arr[2], ..., Arr[N] (each modulo 10^9 + 7)
#
# Sample Input:
# 5 5 2
# 3 1 5
# 4 2 2
# 6 3 5
# 9 5 5
# 4 2 4
#
# Sample Output:
# 3 14 26 52 81


import sys

MOD=10**9+7

def solve():
    data=list(map(int,sys.stdin.buffer.read().split()))
    ptr=0

    n=data[ptr]; ptr+=1
    q=data[ptr]; ptr+=1
    k=data[ptr]%MOD; ptr+=1

    # Precompute powers of k and inverse powers of k
    powk=[1]*(n+2)
    invpow=[1]*(n+2)

    invk=pow(k,MOD-2,MOD)

    for i in range(1,n+1):
        powk[i]=(powk[i-1]*k)%MOD
        invpow[i]=(invpow[i-1]*invk)%MOD

    # diff array for transformed array B[i] = Arr[i] * k^(-(i-1))
    diff=[0]*(n+3)

    for _ in range(q):
        A=data[ptr]; ptr+=1
        L=data[ptr]; ptr+=1
        R=data[ptr]; ptr+=1

        val=(A*invpow[L-1])%MOD
        diff[L]=(diff[L]+val)%MOD
        diff[R+1]=(diff[R+1]-val)%MOD

    # Recover B and then original Arr
    ans=[0]*n
    cur=0
    for i in range(1,n+1):
        cur=(cur+diff[i])%MOD
        ans[i-1]=(cur*powk[i-1])%MOD

    sys.stdout.write(" ".join(map(str,ans)))

solve()
