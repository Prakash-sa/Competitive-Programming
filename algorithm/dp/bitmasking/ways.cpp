int numberWays(vector<vector<int>>& hats) {
    int n=hats.size();
    vector<vector<int>> p(40);
    vector<int>mask(1<<n);
    int mod=1e9+7;
    mask[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<hats[i].size();j++)p[hats[i][j]-1].push_back(i);
    }
    for(int i=0;i<40;i++){
        for(int j=(1<<n)-1;j>=0;j--){
            for(int k=0;k<p[i].size();k++){
                int tmp=p[i][k];
                if((j&(1<<tmp))==0 && mask[j]){
                    mask[j|(1<<tmp)]+=mask[j];
                    mask[j|(1<<tmp)]%=mod;
                }
            }
        }
    }
    return mask[(1<<n)-1];
}