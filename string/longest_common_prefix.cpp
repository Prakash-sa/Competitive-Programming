//https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/14.%20Longest%20Common%20Prefix.cpp

//https://leetcode.com/problems/longest-common-prefix/



class Solution {
public:
    
    string lcp(string left,string right){
        int _min=min(left.size(),right.size());
        for(int i=0;i<_min;i++){
            if(left[i]!=right[i]){
                return left.substr(0,i);
            }
        }
        return left.substr(0,_min);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            ans=lcp(ans,strs[i]);
        }
        return ans;
    }
};
