
// minimum number of room required
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
bool cmp(vector<int>a,vector<int>b){
    return a[0]<b[0];
}

int Solution::solve(vector<vector<int> > &A) {
    int ans=1;
    sort(A.begin(),A.end(),cmp);
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(A[0][1]);
    for(int i=1;i<A.size();i++){
        if(A[i][0]>=pq.top())pq.pop();
        else ans++;
        pq.push(A[i][1]);
    }
    return ans;
}

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    }
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int,int>>ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back({arr[i],dep[i]});
        }
        sort(ans.begin(),ans.end(),cmp);
        int cnt=1;
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(ans[0].second);
        for(int i=1;i<ans.size();i++){
            if(ans[i].first>pq.top())pq.pop();
            else cnt++;
            pq.push(ans[i].second);
        }
        
        return cnt;
        
    }
};

// maximum number of room required
// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
  public:
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int ans=1;
        vector<pair<int,int>>newv;
        for(int i=0;i<start.size();i++){
            newv.push_back({start[i],end[i]});
        }
        sort(newv.begin(),newv.end(),cmp);
        int lastEnd=newv[0].second;
        for(int i=1;i<newv.size();i++){
            if(newv[i].first>lastEnd){
                ans++;
                lastEnd=newv[i].second;
            }
        }
        return ans;
    }
};
