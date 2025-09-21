# https://www.geeksforgeeks.org/problems/sort-a-stack/1

'''
Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).

Examples:

Input: st[] = [1, 2, 3]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.

Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Constraints:
1 ≤ st.size() ≤ 103
0 ≤ stack element ≤ 103
'''

# recursive
class Solution:
    def sorted_insert(self,st,x):
        if not st or st[-1]<=x:
            st.append(x)
            return
        top=st.pop()
        self.sorted_insert(st,x)
        st.append(top)

    def sortStack(self, st):
        if not st:
            return
        top=st.pop()
        self.sortStack(st)
        self.sorted_insert(st,top)

# Time Complexity: O(n^2)
# Space Complexity: O(n) due to call stack


# iterative
class Solution:
    def sortStack(self, st):
        aux=[]
        while st:
            tmp=st.pop()
            while aux and aux[-1]<tmp:
                st.append(aux.pop())
            aux.append(tmp)
        while aux:
            st.append(aux.pop())


# Time Complexity: O(n^2)
# Space Complexity: O(n) due to call stack
