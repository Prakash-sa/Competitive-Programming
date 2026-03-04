# https://leetcode.com/problems/minimum-absolute-difference/description/

'''
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

Example 1:
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:
Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]

Constraints:
2 <= arr.length <= 105
-106 <= arr[i] <= 106
'''


class Solution:
    def minimumAbsDifference(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        min_difference=math.inf
        ans=[]

        for i in range(len(nums)-1):
            diff=abs(nums[i+1]-nums[i])
            if diff<min_difference:
                min_difference=diff
                ans=[[nums[i],nums[i+1]]]
            elif diff==min_difference:
                ans.append([nums[i],nums[i+1]])
        return ans

# Complexity Analysis

# Let n be the length of the array arr.
# Time complexity: O(n⋅log(n))
# First, we sort arr using comparision sorting, which takes O(n⋅log(n)).
# We then traverse the array, which takes O(n) time.
# To sum up, the overall time complexity is O(n⋅log(n)).

# Space complexity: O(n).


# Counting Sort
class Solution:
    def minimumAbsDifference(self, nums: List[int]) -> List[List[int]]:
        min_element=min(nums)
        max_element=max(nums)
        shift=-min_element
        line=[0]*(max_element-min_element+1)
        min_diff=max_element-min_element
        prev=0
        ans=[]

        for num in nums:
            line[num+shift]=1

        for curr in range(1,max_element+shift+1):
            if line[curr]==0:
                continue
            current_diff=curr-prev
            if current_diff<min_diff:
                min_diff=current_diff
                ans=[[prev-shift,curr-shift]]
            elif current_diff==min_diff:
                ans.append([prev-shift,curr-shift])
            prev=curr
        return ans 

# Complexity Analysis

# Let n be the size of the input array arr, and m be the range of values in arr.
# Time complexity: O(m+n)
# We initialize an auxiliary array of all zeros, which takes O(m) time.


# Space complexity: O(m+n)
# We used an auxiliary array line of size O(m).

