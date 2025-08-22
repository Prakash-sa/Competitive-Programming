//https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1#


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int i=0,o=0,e=0;
	    int n=s.size(),max1=INT_MIN;
	    int a[n];
	    for(int i=0;i<n;i++){
	        if(s[i]=='0')a[i]=1;
	        else a[i]=-1;
	    }
	    int max_sum=a[0];
	    int cu=a[0];
	    for(int i=1;i<n;i++){
	        cu=max(a[i],cu+a[i]);
	        max_sum=max(cu,max_sum);
	    }
	    cout<<max_sum<<endl;
	
	}
	return 0;
}
