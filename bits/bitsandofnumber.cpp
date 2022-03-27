//https://leetcode.com/problems/bitwise-and-of-numbers-range/






class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int i=31;i>=0;i--){
            if((left&(1<<i))!=(right&(1<<i)))break;
            else ans=ans|(left&(1<<i));
        }
        return ans;
    }
};
