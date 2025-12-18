# https://leetcode.com/problems/add-binary/description/

'''
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
'''

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n=max(len(a),len(b))
        a,b=a.zfill(n),b.zfill(n)

        carry=0
        ans=[]
        for i in range(n-1,-1,-1):
            if a[i]=='1':
                carry+=1
            if b[i]=='1':
                carry+=1
            
            if carry%2==1:
                ans.append('1')
            else:
                ans.append('0')
            carry//=2
        if carry==1:
            ans.append('1')
        
        ans.reverse()
        return "".join(ans)

# Complexity Analysis
# Time complexity: O(max(N,M)), where N and M are lengths of the input strings a and b.
# Space complexity: O(max(N,M)) to keep the answer.
