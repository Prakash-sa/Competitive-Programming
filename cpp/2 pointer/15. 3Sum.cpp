//https://leetcode.com/problems/3sum/





class Solution {
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(i!=0&& nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                int mid=nums[j]+nums[k];
                if(mid==-nums[i]){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k]==nums[k-1])k--;
                    j++;k--;
                }
                else if(mid<-nums[i]){
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return res;
    }
};



//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#



using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+7;
const int num=1e5+5;

void init(){

}

 
int main()
{
   boost;
   int t=1;
   cin>>t;
   while(t--){
       int n,s;
       cin>>n>>s;
       int a[n];
       int max1=0;
       for(int i=0;i<n;i++){
           cin>>a[i];
           max1=max(max1,a[i]);
       }
       int flag=0;
       int m[max1+1]={0};
       for(int i=0;i<n;i++)m[a[i]]++;
       for(int i=0;i<n;i++){
           m[a[i]]--;
           for(int j=i+1;j<n;j++){
               m[a[j]]--;
               int tmp=s-a[i]-a[j];
               if(tmp>0 && tmp <=max1 && m[tmp]>0){
                   flag=1;
                   break;
               }
               m[a[j]]++;
           }
           if(flag)break;
           m[a[i]]++;
       }
       if(flag){
           cout<<1<<endl;
       }
       else cout<<0<<endl;
   }
   return 0;
}
