//https://leetcode.com/problems/container-with-most-water/

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
*/



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
