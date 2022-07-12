//https://leetcode.com/problems/matchsticks-to-square/

class Solution {
    
    bool backtrack(vector<int>&matchsticks,vector<bool>&visited,int x,int target,int curr,int cnt){
        if(cnt==1)return true;
        
        if(curr==target)return backtrack(matchsticks,visited,0,target,0,cnt-1);
        
        
        for(int i=x;i<matchsticks.size();i++){
            if(visited[i] || curr+matchsticks[i]>target)continue;
            visited[i]=true;
            if(backtrack(matchsticks,visited,i+1,target,curr+matchsticks[i],cnt))return true;
            visited[i]=false;
        }
        return false;
        
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        if (matchsticks.size() < 4 || sum % 4) return false;
        
        vector<bool>visited(matchsticks.size(), false);
        return backtrack(matchsticks, visited,0, sum / 4, 0, 4);
    }
    
};