# https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

'''
You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
You have to calculate the total number of moves required to transfer all n disks from the starting rod to the target rod, following these rules:
      1. Only one disk can be moved at a time.
      2. A disk can only be placed on top of a larger disk or on an empty rod.
Return the number of moves needed to complete the task.

Examples:

Input: n = 2
Output: 3
Explanation: For n =2 , steps will be as follows in the example and total 3 steps will be taken.
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
Input: n = 3
Output: 7
Explanation: For N=3 , steps will be as follows in the example and total 7 steps will be taken.
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
Input: n = 0
Output: 0
Explanation: Total 0 steps will be taken.
Constraints:
  0 ≤ n ≤ 20
'''

# pow(2,n)-1

class Solution:
    def  towerOfHanoi(self, n, fromm, to, aux):
        # code here
        if n==0:
            return 0
        moves=0
        moves+=self.towerOfHanoi(n-1,fromm,aux,to)
        moves+=1
        moves+=self.towerOfHanoi(n-1,aux,to,fromm)
        return moves
    
# Time complexity: O(2^N)
# Space complexity: O(N)
