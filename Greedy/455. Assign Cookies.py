# https://leetcode.com/problems/assign-cookies/description/

'''
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Example 1:
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

Constraints:
1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1
'''

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j=i=0
        n=len(g)
        cnt=0
        while i<len(g) and j<len(s):
            if s[j]>=g[i]:
                cnt+=1
                i+=1
            j+=1

        return cnt

# Complexity Analysis
# Time Complexity: O(n⋅logn+m⋅logm) where n is the size of the array g and m is the size of the array s.

# Sorting an array of length k takes O(k⋅logk), we need to sort two given arrays. The while loop iterates over each cookie and child once, taking O(m+n). To sum up, the overall time complexity is O(n⋅logn+m⋅logm)

# Space Complexity: O(m+n) or O(logm+logn)

# Some extra space is used when we sort s and g in place. The space complexity of the sorting algorithm depends on the programming language.
# In Python, the sort method sorts a list using the Timesort algorithm which is a combination of Merge Sort and Insertion Sort and has O(n+m) additional space.
# In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with a worse-case space complexity of O(logn+logm).
# In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of O(logn+logm) for sorting two arrays.