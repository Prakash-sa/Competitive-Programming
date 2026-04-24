# https://leetcode.com/problems/reverse-words-in-a-string/description/

'''
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
'''

class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.split()

        ans=[]
        while s:  ## for loop is inefficient
            ans.append(s.pop())
        return " ".join(ans)


# since strings in python are immutable so have to convert that into the list
class Solution:

    def reverse(self,arr,left,right):
        while left<right:
            arr[left],arr[right]=arr[right],arr[left]
            left+=1
            right-=1

    def reverseWords(self, s: str) -> str:
        arr=list(s)
        n=len(arr)

        self.reverse(arr,0,n-1)

        write=0
        read=0

        while read<n:
            if arr[read]!=' ':
                if write!=0:
                    arr[write]=' '
                    write+=1
                start=write
                while read<n and arr[read]!=' ':
                    arr[write]=arr[read]
                    write+=1
                    read+=1

                self.reverse(arr,start,write-1)
            else:
                read+=1
        return ''.join(arr[:write])


# Complexity Analysis
# Time complexity: O(N)
# Space complexity: O(N)

