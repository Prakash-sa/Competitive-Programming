//https://leetcode.com/problems/reaching-points/

//One special case we need to handle during this optimization is when tx=9,ty=3,sx=6, sy=3 which can be covered using the condition if(sy == ty) return (tx - sx) % ty == 0;



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
