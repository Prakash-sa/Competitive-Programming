# https://leetcode.com/problems/daily-temperatures/description/

'''
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]
 
Constraints:
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
'''

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer=[0]*len(temperatures)
        stack=[]

        for curr_day,curr_temp in enumerate(temperatures):
            while stack and temperatures[stack[-1][0]]<curr_temp:
                prev_day,prev_temp=stack.pop()
                answer[prev_day]=curr_day-prev_day
            stack.append([curr_day,curr_temp])
        return answer
        

# Time Complexity: O(N)
# Space Complexity: O(N)


# Space optimized

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n=len(temperatures)
        hottest=0
        answer=[0]*n

        for curr_day in range(n-1,-1,-1):
            curr_temp=temperatures[curr_day]
            if curr_temp>=hottest:
                hottest=curr_temp
                continue

            days=1
            while temperatures[curr_day+days]<=curr_temp:
                days+=answer[curr_day+days]
            answer[curr_day]=days

        return answer
        

# Complexity Analysis
# Given N as the length of temperatures,
# Time complexity: O(N)
# Similar to the first approach, the nested while loop makes this algorithm look worse than O(N). However, same as in the first approach, the total number of iterations in the while loop does not exceed N, which gives this algorithm a time complexity of O(2⋅N)=O(N).
# The reason the iterations in the while loop does not exceed N is because the "jumps" prevent an index from being visited twice. If we had the example temperatures = [45, 43, 45, 43, 45, 31, 32, 33, 50], after 5 iterations we would have answer = [..., 4, 1, 1, 1, 0]. The day at index 2 will use answer[4] to jump to the final day (which is the next warmer day), and then answer[4] will not be used again. This is because at the first day, answer[2] will be used to jump all the way to the end. The final solution is answer = [8,1,6,1,4,1,1,1,0]. The 6 was found with the help of the 4 and the 8 was found with the help of the 6.

# Space complexity: O(1)
# As stated above, while answer does use O(N) space, the space used for the output does not count towards the space complexity. Thus, only constant extra space is used.
