//https://leetcode.com/problems/single-number-iii/
//https://www.thecodingshala.com/2021/02/single-number-3-leetcode-solution.html

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int first=0,sec=0,allnum=0;
        for(auto it:nums)allnum^=it;
        int shift=1;
        for(int i=0;i<32;i++){
            if(allnum&(1<<i)){
                shift=i;
                break;
            }
        }
        for(auto it:nums){
            if(it&(1<<shift))first^=it;
            else sec^=it;
        }
        return {first,sec};
    }
};
