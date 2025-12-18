# https://leetcode.com/problems/longest-repeating-character-replacement/description/

'''
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 
Constraints:
1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
'''

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq=[0]*26
        l=0
        maxf=0
        best=0

        for r,ch in enumerate(s):
            idx=ord(ch)-65
            freq[idx]+=1
            if freq[idx]>maxf:
                maxf=freq[idx]

            while (r-l+1)-maxf>k:
                left_idx=ord(s[l])-65
                freq[left_idx]-=1
                l+=1
            
            curr_len=r-l+1
            if curr_len>best:
                best=curr_len
        return best
    
# Use sliding window with a 26 bucket frequency array and a running max_count.
# Time O(n). Space O(1).