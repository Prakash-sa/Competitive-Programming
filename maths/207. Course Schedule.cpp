//course schedule 1

//https://leetcode.com/problems/course-schedule/

//topological sorting 


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>in_degree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in_degree[prerequisites[i][0]]++;
        }
        
        int cnt=0;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!in_degree[i])q.push(i);
        }
        
        while(!q.empty()){
            int k=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[k]){
                in_degree[it]--;
                if(!in_degree[it])q.push(it);
            }
        }
        if(numCourses!=cnt)return false;
        return true;
    }
};




//course schedule 2

//https://leetcode.com/problems/course-schedule-ii/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>in_degree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in_degree[prerequisites[i][0]]++;
        }
        
        int count=0;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!in_degree[i])q.push(i);
        }
        vector<int>ans;
        
        while(!q.empty()){
            int k=q.front();
            q.pop();
            ans.push_back(k);
            for(auto it:adj[k]){
                in_degree[it]--;
                if(!in_degree[it])q.push(it);
            }
        }
        if(ans.size()==numCourses)return ans;
        return {};
        
    }
};
