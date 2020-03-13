#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

lli  cnt=0;
void merge(lli ar[ ] , lli start, lli mid, lli end) {
    lli p = start,q = mid+1;
    lli k = 0;
    lli j ;
    lli arr[end - start + 1];

    while( (p <= mid) && ( q <= end) ){
        if(ar[p] <= ar[q]) arr[k++] = ar[p++];

        else if(ar[p] > ar[q]){
            cnt += (mid-p+1);
            arr[k++] = ar[q++];
        }
    }

    while(p <= mid) arr[k++] = ar[p++];
    
    while(q <= end) arr[k++] = ar[q++];
    
    for(p = 0;p < k;p++) ar[start+p] = arr[p];
 
}

   void merge_sort (lli A[ ] , lli start , lli end )
   {
           if( start < end ) {
           lli mid = (start + end ) / 2 ;           // defines the current array in 2 parts .
           merge_sort (A, start , mid ) ;                 // sort the 1st part of array .
           merge_sort (A,mid+1 , end ) ;              // sort the 2nd part of array.
          merge(A,start , mid , end );   
   }                    
}

int main()
{
    speed;
    lli n;
    cin>>n;
    lli a[n],b[n];
    F(i,0,n-1)cin>>a[i];
    F(i,0,n-1)b[i]=a[i];
    merge_sort(b,0,n-1);
    // F(i,0,n-1){
    //     if(a[i]!=b[i])cnt++;
    // }
    cout<<cnt;


    return 0;
}

//------------------dnf(dutch national flag)--------------------//

int *dnf(int *a,int high){
    int l=0;
    int h=high-1;
    int mid=0;
    while(mid<=h){
        switch(a[mid]){
            case 0:swap(a[l++],a[mid++]);
            break;
            case 1:mid++;
            break;
            case 2:swap(a[mid],a[h--]);
            break;
        }
    }
    return a;
}

//inversion is the no. of steps
int countInversions(std::vector<int> a) {
    int n=a.size();
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (a[i] > a[j]) 
                inv_count++; 
    return inv_count;

}
