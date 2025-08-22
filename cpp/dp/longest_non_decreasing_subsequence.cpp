//O(Nlog(N))

//https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/


class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int longest=0;
        for(int i=0;i<k;i++){
            vector<int>tmp;
            for(int j=i;j<arr.size();j+=k){
                if(tmp.empty() || tmp.back()<=arr[j])tmp.push_back(arr[j]);
                else *upper_bound(tmp.begin(),tmp.end(),arr[j])=arr[j];
            }
            longest+=tmp.size();
        }
        return arr.size()-longest;
    }
};
