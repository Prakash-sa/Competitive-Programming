    #include<bits/stdc++.h>
    #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define debug cout<<"here"<<endl;
    #define ll long long int
    #define mp make_pair
    #define pb push_back
    const ll MOD=1e9+7;
    #define MAX 100005
    #define eps 1e-9
    #define infi 1000000000000000
    #define intial 0
    #define waiting 1
    #define visited 2
    #define nill -1
    #define max3(a,b,c) max(a,max(b,c))
    #define min3(a,b,c) min(a,min(b,c))
    #define PII pair<ll,ll>
    #define input freopen("input.txt","r",stdin);
    #define output freopen("output.txt","w",stdout);
    using namespace std;
    int n,m,e;
    struct city{
    	int dest,er,dis;
    };
    std::vector<city> adj[15];
     
    ll dp[35000][15][105];
    ll min_dist(int mask,int ver,int energy_rem){
        
    	if(energy_rem<0)
    		return infi;
    	if(__builtin_popcount(mask)==n)
    		return 0;
    	if(dp[mask][ver][energy_rem]==-1){
    		ll ans=infi;
    		for(int i=0;i<adj[ver].size();i++){
    			if((mask&(1<<adj[ver][i].dest))==0)
    				ans=min(ans,min_dist(mask|(1<<adj[ver][i].dest),adj[ver][i].dest,energy_rem-adj[ver][i].er)+adj[ver][i].dis);
    		}
    		dp[mask][ver][energy_rem]=ans;
    	}
    	return dp[mask][ver][energy_rem];
    }
    int main()
    {
    	fast;
    	memset(dp,-1,sizeof(dp));
    	cin>>n>>m>>e;
    	for(int i=0;i<m;i++){
    		int u,v,d,e;
    		cin>>u>>v>>d>>e;
    		city c;
    		c.dest=v;
    		c.dis=d;
    		c.er=e;
    		adj[u].pb(c);
    		c.dest=u;
    		adj[v].pb(c);
    	}
     
    	ll ans=min_dist(2,1,e);
    	if(ans>=infi)
    		ans=-1;
    	cout<<ans<<endl;
    	return 0;
    }