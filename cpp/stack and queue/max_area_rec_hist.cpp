#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;

#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< lli,lli> pll;
typedef map< lli,lli> mll;
typedef map< int,int> mii;
lli max1=1e8+1;
map<lli,bool>mp;

int main()
{
   // boost;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        stack<int>s;
        int i=0;
        lli maxare=INT_MIN;
        lli area;
        while(i<n){
            if(s.empty()||a[i]>=a[s.top()]){
                s.push(i++);
            }
            else if(a[i]<a[s.top()]){
                int k=s.top();
                s.pop();
                if(!s.empty())area=a[k]*(i-s.top()-1);
                else area=a[k]*(i);
                
                maxare=max(area,maxare);
            }
            
        }
        while(!s.empty()){
            int k=s.top();
            s.pop();
                if(!s.empty())area=a[k]*(i-s.top()-1);
                else area=a[k]*(i);
                
                maxare=max(area,maxare);
            
        }



        cout<<maxare<<endl;
    }
    return 0;
}




//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        int i=0;
        long long ans=0;
        stack<int>st;
        while(i<n){
            if(st.empty() || arr[i]>=arr[st.top()]){
                st.push(i++);
            }
            else {
                int k=st.top();
                st.pop();
                long long tmp=0;
                if(!st.empty())tmp=arr[k]*(i-st.top()-1);
                else tmp=arr[k]*(i);
                ans=max(ans,tmp);
            }
        }
        
        while(!st.empty()){
            int k=st.top();
            st.pop();
            long long tmp;
            if(!st.empty())tmp=arr[k]*(i-st.top()-1);
            else tmp=arr[k]*(i);
            ans=max(ans,tmp);
        }
        return ans;
    }
};

