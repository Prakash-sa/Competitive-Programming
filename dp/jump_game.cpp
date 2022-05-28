//https://leetcode.com/problems/jump-game/

//Jump Game 1


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        if(nums[0]==0)return false;
        int can=nums[0];
        for(int i=0;i<=can;i++){
            if(i>=n-1)return true;
            can=max(can,i+nums[i]);
        }
        return false;
    }
};



//https://leetcode.com/problems/jump-game-ii/

//Jump Game 2

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for(int i = 1;i < n;i++){
            int minValue = INT_MAX;
            for(int j = i - 1;j >= 0;j--){
                if((i - j) <= nums[j]) minValue = min(minValue,res[j] + 1);
            }
            res[i] = minValue;
        }
        return res[n - 1];
    }
};



//https://leetcode.com/problems/jump-game-iii/

//Jump Game 3



class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>visited(n,0);
        int i=start;
        queue<int>q;
        q.push(i);
        while(q.size()){
            i=q.front();
            q.pop();
            if(visited[i])continue;
            visited[i]=1;
            if(arr[i]==0)return true;
            int l=i-arr[i];
            int r=i+arr[i];
            if(l>=0)q.push(l);
            if(r<n)q.push(r);
        }
        return false;
        
    }
};



//https://leetcode.com/problems/jump-game-iv/

//Jump Game 4


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int step=0;
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>visited(n,0);
        visited[0]=1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int i=q.front();
                q.pop();
                if(i==n-1)return step;
                vector<int>&next=mp[arr[i]];
                next.push_back(i+1);
                next.push_back(i-1);
                for(auto j:next){
                    if(j>=0 && j<n && !visited[j]){
                        visited[j]=1;
                        q.push(j);
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};



//https://leetcode.com/problems/jump-game-v/

//Jump Game 5


class Solution {
    vector<int> dp;
    int n;
    
    int solve(vector<int>&arr,int x,int d){
        if(dp[x]!=-1)return dp[x];
        dp[x]=0;
        for(int i=x+1;i<=x+d && i<n && arr[i]<arr[x] ;i++){
            dp[x]=max(dp[x],1+solve(arr,i,d));
        }
        for(int i=x-1;i>=x-d && i>=0 && arr[i]<arr[x] ;i--){
            dp[x]=max(dp[x],1+solve(arr,i,d));
        }
        return dp[x];
    }
    
public:
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.resize(n,-1);
        int result=0;
        for(int i=0;i<n;i++){
            result=max(result,1+solve(arr,i,d));
        }
        return result;
    }
};





//https://leetcode.com/problems/jump-game-vi/

//Jump Game 6


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int>q;
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        q.push_back(0);
        for(int i=1;i<n;i++){
            if(q.front()<i-k)q.pop_front();
            dp[i]=nums[i]+dp[q.front()];
            while(!q.empty() && dp[q.back()]<=dp[i])q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};





//https://leetcode.com/problems/jump-game-vii/

//Jump Game 7


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1')return false;
        vector<int>dp(n,false);
        dp[0]=true;
        int pre=0;
        for(int i=1;i<n;i++){
            if(i>=minJump)pre+=dp[i-minJump];
            if(i>maxJump)pre-=dp[i-maxJump-1];
            dp[i]=pre>0 && s[i]=='0';
        }
        return dp[n-1];
    }
};


