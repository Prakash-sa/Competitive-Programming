'''
# You are given T test cases. Each test case is an equation of the form:
# (a op1 b op2 c) mod p
# where op1 and op2 can be one of: +, -, *, /
#
# Task:
# Compute the value of each equation modulo p, and output a result in the range [0, p-1].
#
# Important conditions:
# - p is a prime number.
# - gcd(a, p) = gcd(b, p) = gcd(c, p) = 1, so modular division is valid.
# - Operators follow normal precedence:
#   multiplication and division are evaluated before addition and subtraction.
#
# Input format:
# - First line: integer T (number of test cases), 1 <= T <= 100000
# - Next T lines: one equation in the form (a op1 b op2 c) mod p
#
# Constraints:
# - 1 <= a, b, c, p <= 10^9
# - p is prime
# - gcd(a, p) = gcd(b, p) = gcd(c, p) = 1
#
# Output format:
# - For each test case, print one integer: the value of the expression modulo p
#   (must lie between 0 and p-1).
#
# Example:
# Input:
# 2
# (1 + 2 / 1) mod 3
# (2 * 3 - 8) mod 5
#
# Output:
# 0
# 3
'''


# Write your code here
import re
t=int(input())

def fast_multiplication(a,m):
    exponent=m-2
    result=1
    a%=m
    while exponent:
        if exponent&1:
            result=(result*a)%m
        a=(a*a)%m
        exponent//=2
    return result%m

def eval(a,b,op,m):
    a%=m
    b%=m
    if op=='+':
        return (a+b)%m
    elif op=='-':
        return (a-b)%m
    elif op=='*':
        return (a*b)%m
    else:
        return (a*fast_multiplication(b,m))%m


for _ in range(t):
    line=input().strip()
    m=re.match(r"\((.*)\)\s*mod\s*(\d+)",line)
    expr=m.group(1).strip()
    mod_val=int(m.group(2))

    tokens=expr.split()
    val1,val2,val3=int(tokens[0]),int(tokens[2]),int(tokens[4])
    op1,op2=tokens[1],tokens[3]
    total=0
    if (op1 in '*/') or ( op1 not in '*/' and op2 not in '*/'):
        tmp1=eval(val1,val2,op1,mod_val)
        total=eval(tmp1,val3,op2,mod_val)
    elif op2 in '*/':
        tmp1=eval(val2,val3,op2,mod_val)
        total=eval(val1,tmp1,op1,mod_val)

    print(int(total)%mod_val)

