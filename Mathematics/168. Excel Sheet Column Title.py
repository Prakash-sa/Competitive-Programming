# https://leetcode.com/problems/excel-sheet-column-title/description/

'''
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Example 1:
Input: columnNumber = 1
Output: "A"
Example 2:
Input: columnNumber = 28
Output: "AB"
Example 3:
Input: columnNumber = 701
Output: "ZY"

Constraints:
1 <= columnNumber <= 231 - 1
'''


class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans=''
        while columnNumber>0:
            columnNumber-=1
            ans+=chr(columnNumber%26+ord('A'))
            columnNumber//=26
        return ans[::-1]
    
'''
Complexity Analysis
Here, N is the column number given in the problem.
Time complexity: O(logN)
The number of operations would be equal to the number of while loop iterations. In each iteration, the number N gets divided by 26. Hence the time complexity would be O(log26N). Note that the base of the logarithm is not relevant when it comes to big O, since all logarithms are related by a constant factor.

Space complexity: O(1)
We only need one string to store the output, but generally the space to store the output is not considered as part of space complexity and hence the space complexity is constant.
'''

