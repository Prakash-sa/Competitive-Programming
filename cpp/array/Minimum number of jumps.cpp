//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1








int cnt;
int ch(int a[],int n){
    int ans=INT_MAX;
    int jumps[n]={INT_MAX};
    for(int i=0;i<n;i++)jumps[i]=INT_MAX;
    if(a[0]==0||n==0)return -1;
    jumps[0]=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<=i+a[i] && j<n;j++){
            if(jumps[i]!=INT_MAX)
               jumps[j]=min(jumps[j],jumps[i]+1);
        }
    }
    if(jumps[n-1]==INT_MAX)return -1;
    return jumps[n-1];
}
