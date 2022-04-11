/*
https://leetcode.com/problems/container-with-most-water/

https://leetcode.com/problems/container-with-most-water/discuss/1915172/JavaC%2B%2B-Easiest-Explanations
*/



class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int ans=INT_MIN;
        while(l<r){
            int w=r-l;
            int h=min(height[r],height[l]);
            ans=max(ans,h*w);
            if(height[l]<height[r])l++;
            else if(height[r]<height[l])r--;
            else {
                l++;
                r--;
            }
        }
        return ans;
    }
};




