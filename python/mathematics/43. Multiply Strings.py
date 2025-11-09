# https://leetcode.com/problems/multiply-strings/description/

'''
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Constraints:
1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
'''


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1=="0" or num2=="0":
            return "0"
        n,m=len(num1),len(num2)
        ans=[0]*(n+m+1)
        num1,num2=num1[::-1],num2[::-1]
        for i in range(n):
            for j in range(m):
                k=int(num1[i])*int(num2[j])
                ans[i+j]+=k
                ans[i+j+1]+=ans[i+j]//10
                ans[i+j]=ans[i+j]%10
        
        res=ans[::-1]
        base=0
        while base<len(res) and res[base]==0:
            base+=1
        res=map(str,res[base:])
        return "".join(res)


# Time Complexity: O(n × m)
# Where n = len(num1) and m = len(num2)
# Space Complexity: O(n + m)