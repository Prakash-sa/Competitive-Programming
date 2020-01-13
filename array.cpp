//-----------biotonic-array-------------------------//

long long int biotonic_sum(int a[],int n){
    long long int msis[n],msds[n];
    
    msis[0]=a[0];
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i])msis[i]=msis[i-1]+a[i];
        else msis[i]=a[i];
    }
    msds[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1])msds[i]=msds[i+1]+a[i];
        else msds[i]=a[i];
    }
    long long int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        if(max_sum<(msds[i]+msis[i]-a[i]))max_sum=msds[i]+msis[i]-a[i];
    }
    
    return max_sum;
}