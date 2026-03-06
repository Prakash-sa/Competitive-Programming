'''

# You are given T test cases. In each test case, four integers A, B, C, and P are provided,
# where P is a prime number. For each test case, compute (A^(B^C)) % P and print the result.
# Use the rule 0^0 = 1.
#
# Input:
# - First line: integer T (number of test cases)
# - Next T lines: four space-separated integers A, B, C, P
#
# Output:
# - For each test case, print (A^(B^C)) % P on a new line.
#
# Constraints:
# - 1 <= T <= 2 * 10^5
# - 0 <= A, B, C <= 10^9
# - 2 <= P <= 10^4
'''

import sys
# Write your code here
t=int(input())

def fast_exponent(base,exponent,modulus):
    result=1
    base%=modulus
    while exponent:
        if exponent&1:
            result=(result*base)%modulus
        base=(base*base)%modulus
        exponent//=2
    return result

out=[]
for _ in range(t):
    a,b,c,p=list(map(int,input().split()))
    if (b==0 and c!=0):
        out.append('1')
        continue
    if (a==0 and b!=0 and c!=0) or (a!=0 and b!=0 and c!=0 and a%p==0):
        out.append('0')
        continue
    
    exponent_first=fast_exponent(b,c,p-1)
    last_exponent=fast_exponent(a,exponent_first,p)
    out.append(str(last_exponent))

sys.stdout.write('\n'.join(out))
