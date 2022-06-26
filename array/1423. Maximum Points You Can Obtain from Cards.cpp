//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/



class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0,ans=0;
		//sum of first k elements from start
        for(int i=0;i<k;i++)sum+=cardPoints[i];
        ans=sum;
		// remove the first k elements from start and added the elements from the end
        for(int i=0;i<k;i++){
            sum+=cardPoints[n-1-i]-cardPoints[k-i-1];
            ans=max(ans,sum);
        }
        return ans;
    }
};
