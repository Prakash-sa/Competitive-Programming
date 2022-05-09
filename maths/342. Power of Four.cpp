//https://leetcode.com/problems/power-of-four/


class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)return false;
        for(int i=0;i<32;i+=2){
            if(n==1<<i)return true;
        }
        return false;
    }
};


bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}
