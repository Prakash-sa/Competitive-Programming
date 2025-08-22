//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/



class Solution {
public:
    int minDeletions(string s) {
        vector<int>arr(26,0);
        for(auto c:s){
            arr[c-'a']++;
        }
        vector<int>res;
        for(int i=0;i<26;i++){
            if(arr[i]>0)res.push_back(arr[i]);
        }
        sort(res.begin(),res.end());
        unordered_map<int,int>visited;
        int cnt=0;
        for(auto f:res){
            while(visited[f]){
                f--;
                cnt++;
            }
            if(f>0)visited[f]=1;
        }
        return cnt;
    }
};
