//https://leetcode.com/problems/construct-target-array-with-multiple-sums/

//https://www.youtube.com/watch?v=h9t7JF50Mpw&ab_channel=AlgorithmsMadeEasy


class Solution {
public:
    bool isPossible(vector<int>& target) {
        long total=accumulate(target.begin(),target.end(),(long)0);
        priority_queue<int>pq(target.begin(),target.end());
        while(1){
            int a=pq.top();
            pq.pop();
            total-=a;
            if(total==1 || a==1)return true;
            if(a<total || total==0 || a%total==0)return false;
            a%=total;
            total+=a;
            pq.push(a);
        }
        return false;
    }
};
