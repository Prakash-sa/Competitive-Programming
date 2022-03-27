//https://stackoverflow.com/questions/21297067/single-number-ii-from-leetcode
//https://leetcode.com/problems/single-number-ii/submissions/



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first=0,sec=0;
        for(auto it:nums){
            first=(first^it)&(~sec);
            sec=(sec^it)&(~first);
        }
        return first;
        
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first=0,sec=0;
        int cnt=0;
        for(int i=0;i<32;i++){
            int mask=(1<<i);
            cnt=0;
            for(auto it:nums){
                if(it&mask)cnt++;
            }
            if(cnt%3==1){
                first|=mask;
            }
        }
        
        return first;
    }
};
