//https://leetcode.com/problems/maximum-product-of-word-lengths/




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
