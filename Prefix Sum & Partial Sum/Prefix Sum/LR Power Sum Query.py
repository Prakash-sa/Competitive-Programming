# You are given:
# - An array A of N integers
# - Q queries
# - An integer K
#
# For each query (L, R), compute:
# (A[L] + A[L+1] * K + A[L+2] * K^2 + ... + A[R] * K^(R-L)) % (10^9 + 7)
#
# Input format:
# - First line: N Q K
#   where 1 <= N <= 10^6, 1 <= Q <= 10^6, 1 <= K <= 10^9
# - Second line: N integers A[i]
#   where -10^9 <= A[i] <= 10^9
# - Next Q lines: L R
#   where 1 <= L <= R <= N
#
# Output format:
# - For each query, print:
#   (A[L] + A[L+1] * K + ... + A[R] * K^(R-L)) % (10^9 + 7)
# - Print each answer on a new line.
#
# Sample Input:
# 10 10 234565
# 12 -23 -123 2345 2345 44 345 -93945 -5353 1
# 1 5
# 1 8
# 1 10
# 2 2
# 6 6
# 4 8
# 2 9
# 4 10
# 3 6
# 5 9
#
# Sample Output:
# 644011223
# 645979052
# 534876628
# 999999984
# 44
# 725883751
# 503173837
# 859246404
# 845338365
# 605774687



import sys

MOD = 10**9 + 7

data = list(map(int, sys.stdin.buffer.read().split()))
ptr = 0

n = data[ptr]; ptr += 1
q = data[ptr]; ptr += 1
k = data[ptr] % MOD; ptr += 1

A = data[ptr:ptr+n]
ptr += n

out = []

# Special case: k == 0
# Sum becomes A[l] only
if k == 0:
    for _ in range(q):
        l = data[ptr]; ptr += 1
        r = data[ptr]; ptr += 1
        out.append(str(A[l - 1] % MOD))
    sys.stdout.write("\n".join(out))
    sys.exit(0)

invK = pow(k, MOD - 2, MOD)

# invPowK[i] = k^(-i) mod MOD
invPowK = [1] * (n + 1)
for i in range(1, n + 1):
    invPowK[i] = (invPowK[i - 1] * invK) % MOD

# pref[i+1] = A[0]*k^0 + A[1]*k^1 + ... + A[i]*k^i
pref = [0] * (n + 1)
p = 1
s = 0
for i in range(n):
    s = (s + (A[i] % MOD) * p) % MOD
    pref[i + 1] = s
    p = (p * k) % MOD

for _ in range(q):
    l = data[ptr] - 1; ptr += 1
    r = data[ptr]; ptr += 1

    seg = (pref[r] - pref[l]) % MOD
    ans = (seg * invPowK[l]) % MOD
    out.append(str(ans))

sys.stdout.write("\n".join(out))
