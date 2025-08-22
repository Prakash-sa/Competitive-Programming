//https://leetcode.com/problems/count-of-smaller-numbers-after-self/


class Solution {
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    }
    
    void mergeSort(vector<pair<int,int>>&v,vector<int>&res,int l,int r){
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(v, res, l, mid);
        mergeSort(v, res, mid+1, r);
        auto compare = [](pair<int, int> a, pair<int, int> b) { return a.first < b.first;};
        for(int i=mid;i>=l;i--){
            auto it=lower_bound(v.begin()+mid+1,v.begin()+r+1,v[i],compare);
            int di=distance(v.begin()+mid+1,it);
            if(di==0)break;
            res[v[i].second]+=di;
        }
        inplace_merge(v.begin()+l, v.begin()+mid+1, v.begin()+r+1, compare);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        vector<int>res(nums.size(),0);
        mergeSort(v,res,0,nums.size()-1);
        return res;
    }
};

