
int ch(int a[],int n){
    int dp1[n]={1},dp2[n]={1};
    for(int i=0;i<n;i++)dp1[i]=1;
    for(int i=0;i<n;i++)dp2[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&(dp1[i]<dp1[j]+1))dp1[i]=dp1[j]+1;
        }
    }    
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j]&&(dp2[i]<dp2[j]+1))dp2[i]=dp2[j]+1;
        }
    }
    
    int max1=INT_MIN;
    for(int i=0;i<n;i++){
        int o=dp1[i]+dp2[i];
        max1=max(max1,o);
    }
    return max1-1;
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<ch(a,n)<<endl;
	
	}
	return 0;
}