//https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

class Solution{
  public:
   vector<bool> record;
  
   bool dfs(int ind , int cnt , int cur ,int nums[],int n , int k , int target)
    {
        if(cnt == k ) return true;
        if(cur == target) return dfs(0,cnt+1,0,nums,n,k,target);
        
        for(int i=ind;i<n;i++)
        {
            if(!record[i])
            {
                if(cur+nums[i] <= target)
                {
                    record[i]=1;
                    if(dfs(i+1,cnt,cur+nums[i] ,nums,n,k,target)) return true;
                    record[i]=0;
                }
                if(!cur || cur+nums[i] == target) return false;
                while(i+1<n && nums[i]==nums[i+1]) i++;
            }
        }
        return false;
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        record.resize(n,0);
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=a[i];
        if(sum%k) return false;
        sum/=k;
        sort(a,a+n);
        return dfs(0,0,0,a,n,k,sum);
    }
};
