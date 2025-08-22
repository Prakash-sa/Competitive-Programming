//https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/



class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator vi;
        struct comp{
            bool operator()(pair<vi,vi>a,pair<vi,vi>b){
                return *a.first>*b.first;
            }  
        };
        priority_queue<pair<vi,vi>,vector<pair<vi,vi>>,comp>pq;
        int mi=INT_MAX,mx=INT_MIN;
        for(auto &it:nums){
            mi=min(mi,it[0]);
            mx=max(mx,it[0]);
            pq.push({it.begin(),it.end()});
        }
        vector<int>ans;
        ans.push_back(mi);
        ans.push_back(mx);
        while(true){
            auto tmp=pq.top();
            pq.pop();
            ++tmp.first;
            if(tmp.first==tmp.second)return ans;
            pq.push(tmp);
            mi=*pq.top().first;
            mx=max(mx,*tmp.first);
            if(mx-mi<ans[1]-ans[0]){
                ans[0]=mi;
                ans[1]=mx;
            }
        }
        return ans;
        
    }
};
