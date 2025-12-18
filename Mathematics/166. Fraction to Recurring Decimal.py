# https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=daily-question&envId=2025-09-24

'''
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 4, denominator = 333
Output: "0.(012)"
 
Constraints:
-231 <= numerator, denominator <= 231 - 1
denominator != 0
'''

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator==0:
            return "0"

        fraction=[]
        if numerator*denominator<0:
            fraction.append("-")

        numerator=abs(numerator)
        denominator=abs(denominator)

        fraction.append(str(numerator//denominator))

        remainder=numerator%denominator
        if remainder==0:
            return "".join(fraction)
        fraction.append(".")
        
        lookup={}
        while remainder!=0:
            if remainder in lookup:
                fraction.insert(lookup[remainder],'(')
                fraction.append(')')
                break
            
            lookup[remainder]=len(fraction)
            remainder*=10
            fraction.append(str(remainder//denominator))
            remainder%=denominator

        return "".join(fraction)



# Complexity:
# Time Complexity: O(n)
# Space Complexity: O(n)


