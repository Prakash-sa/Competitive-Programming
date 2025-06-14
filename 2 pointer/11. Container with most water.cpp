// https://leetcode.com/problems/container-with-most-water/?envType=problem-list-v2&envId=oizxjoit

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        long long int maxWater=0;
        while(left<right){
            int h=min(height[left],height[right]);
            int w=right-left;
            maxWater=max(maxWater,(long long int)h*w);

            if(height[left]<height[right]){
                left++;
            }
            else right--;
        }
        return maxWater;
    }
};
