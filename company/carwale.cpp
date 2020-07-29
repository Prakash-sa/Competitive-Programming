//degree of array
int findShortestSubArray(vector<int>& nums) {
    unordered_map<int,pair<int,pair<int,int>>>mp;
    int max1=INT_MIN,res=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i])==mp.end())mp[nums[i]].second.first=i;
        mp[nums[i]].second.second=i;
        max1=max(max1,++mp[nums[i]].first);
    }
    
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second.first==max1){
            res=min(res,(it->second.second.second)-(it->second.second.first)+1);
        }
    }
    return res;
}


//https://www.codechef.com/problems/KAN13F
//merging files
int main()
{
   boost;
   int t=1,h=1;
   cin>>t;
   while(t--){
       cout<<"Case "<<h<<": ";
       h++;
       int n,k;
       cin>>n>>k;
       lli a[n+1];
       multiset<lli>s;
       for(int i=1;i<=n;i++){
           cin>>a[i];
           s.insert(a[i]);
       }
       lli ans=0;
       lli md=(k-2)-(n-2)%(k-1);
       for(int i=0;i<md;i++)s.insert(0);
       while(s.size()!=1){
           int tmp=s.size();
           lli sum=0;
           for(int i=0;i<k;i++){
               lli p=*s.begin();
               s.erase(s.begin());
               sum+=p;
           }
           ans+=sum;
           s.insert(sum);
       }
        cout<<ans<<endl;

   }
   return 0;
}

//https://www.codechef.com/problems/STACKS
//stacks
int main()
{
   boost;
   int t=1,h=1;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)cin>>a[i];
       vector<int>s;
       for(int i=0;i<n;i++){
           int tmp=upper_bound(s.begin(),s.end(),a[i])-s.begin();
            if(tmp>=s.size()){
                s.push_back(a[i]);
            }
            else {
                s[tmp]=a[i];
            }
       }
       cout<<s.size()<<" ";
       for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
       cout<<endl;

   }
   return 0;
}

