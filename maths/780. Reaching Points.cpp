//https://leetcode.com/problems/reaching-points/

//One special case we need to handle during this optimization is when tx=9,ty=3,sx=6, sy=3 which can be covered using the condition if(sy == ty) return (tx - sx) % ty == 0;

/*
Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.
The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).
 

Example 1:

Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: true
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

*/

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>sx && ty>sy){
            if(tx>ty)tx%=ty;
            else ty%=tx;
        }
        return sx==tx && sy<=ty && (ty-sy)%sx==0 || sy==ty && sx<=tx && (tx-sx)%sy==0; 
    }
};
