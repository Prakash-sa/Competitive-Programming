#include<bits/stdc++.h>
using namespace std;

int ch(int a[]){
    queue<int>q;
    int dis[100];
    for(int i=0;i<100;i++)dis[i]=INT_MAX;
    q.push(1);
    dis[1]=0;
    while(1){
        int s=q.front();
        q.pop();
        if(s==30)break;
        for(int i=s+1;i<=s+6&&i<=30;i++){
            if(a[i]==-1){
                dis[i]=min(dis[i],dis[s]+1);
                q.push(i);
            }
            else {
                dis[a[i]]=min(dis[a[i]],dis[s]+1);
                q.push(a[i]);
            }
        }
    }
    return dis[30];
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k1,k2; 
	    cin>>n;
	    int a[100];
	    for(int i=0;i<100;i++)a[i]=-1;
	    for(int i=0;i<n;i++){
	        cin>>k1>>k2;
	        a[k1]=k2;
	    }
        cout<<ch(a)<<endl;    	    
	}
	return 0;
}