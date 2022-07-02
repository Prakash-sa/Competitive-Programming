#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    //long d[n+1];
    long int *d=new long int[n+1]();
    for(int i=1;i<n+1;i++)d[i]=0;
    for(int i=0;i<queries.size();i++){
        d[queries[i][0]]+=queries[i][2];
       if(queries[i][1]+1<=n) d[queries[i][1]+1]-=queries[i][2];
    }
    long int *a=new long int[n+1]();
    for(int i=1;i<=n;i++)a[i]=0;
    for(int i=1;i<=n;i++){
        if(i==1)a[i]=d[i];
        else a[i]=d[i]+a[i-1];
    }
    long ans=INT_MIN;
    for(int i=1;i<=n;i++){
        if(a[i]>ans)ans=a[i];
    }
    return ans;
}