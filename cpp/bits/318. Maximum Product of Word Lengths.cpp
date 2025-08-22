//https://leetcode.com/problems/maximum-product-of-word-lengths/

/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
If no such two words exist, return 0.

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
*/



public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        vector<int>mask(n,0);
        for(int i=0;i<n;i++){
            for(auto c:words[i]){
                mask[i]|=1<<(c-'a');
            }
            for(int j=0;j<i;j++){
                if(!(mask[j]&mask[i])){
                    ans=max(ans,(int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};
