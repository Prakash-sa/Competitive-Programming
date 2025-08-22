
//Course Schedule 3

//https://leetcode.com/problems/course-schedule-iii/


class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int>q;
        int sum=0;
        for(auto it:courses){
            sum+=it[0];
            q.push(it[0]);
            if(sum>it[1]){
                sum-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};
