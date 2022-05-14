//https://leetcode.com/problems/container-with-most-water/





class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int ans=INT_MIN;
        while(l<=r){
            int w=r-l;
            int area=w*min(height[l],height[r]);
            ans=max(ans,area);
            if(height[l]<height[r])l++;
            else if(height[l]>height[r])r--;
            else {
                l++;
                r--;
            }
        }
        return ans;
    }
};
