# https://leetcode.com/problems/maximize-the-minimum-powered-city/description/?envType=daily-question&envId=2025-11-07

'''
You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.
Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.
Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.
The power of a city is the total number of power stations it is being provided power from.
The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.
Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.
Note that you can build the k power stations in multiple cities.

Example 1:

Input: stations = [1,2,4,5,0], r = 1, k = 2
Output: 5
Explanation: 
One of the optimal ways is to install both the power stations at city 1. 
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.
Example 2:
Input: stations = [4,4,4,4], r = 0, k = 3
Output: 4
Explanation: 
It can be proved that we cannot make the minimum power of a city greater than 4.

Constraints:
n == stations.length
1 <= n <= 105
0 <= stations[i] <= 105
0 <= r <= n - 1
0 <= k <= 109
'''

class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        n=len(stations)
        diff_arr=[0]*(n+1)

        for i in range(n):
            left=max(0,i-r)
            right=min(n,i+r+1)
            diff_arr[left]+=stations[i]
            diff_arr[right]-=stations[i]
        
        def can_achieve(target):
            curr_p=0
            curr_k=k
            diff_cpy=diff_arr.copy()
            for i in range(n):
                curr_p+=diff_cpy[i]
                if curr_p<target:
                    addi=target-curr_p
                    if addi>curr_k:
                        return False
                    curr_p+=addi
                    curr_k-=addi
                    right=min(i+2*r+1,n)
                    diff_cpy[right]-=addi
            return True

        l_bound,r_bound=min(stations),sum(stations)+k
        res=l_bound
        while l_bound<=r_bound:
            target=(l_bound+r_bound)//2
            if can_achieve(target):
                res=target
                l_bound=target+1
            else:
                r_bound=target-1
        return res


# SC: nlog(n), TC: N