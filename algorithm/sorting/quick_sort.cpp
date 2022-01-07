/*
1. Time Complexities

    Worst Case Complexity [Big-O]: O(n^2)
    It occurs when the pivot element picked is either the greatest or the smallest element.

    This condition leads to the case in which the pivot element lies in an extreme end of the sorted array. One sub-array is always empty and another sub-array contains n - 1 elements. Thus, quicksort is called only on this sub-array.

    However, the quicksort algorithm has better performance for scattered pivots.

    Best Case Complexity [Big-omega]: O(n*log n)
    It occurs when the pivot element is always the middle element or near to the middle element.
    Average Case Complexity [Big-theta]: O(n*log n)
    It occurs when the above conditions do not occur.

2. Space Complexity

The space complexity for quicksort is O(log n).

*/

#include<bits/stdc++.h>
using namespace std;

int part(int a[],int st, int ed){
    int s=a[st];
    int j=st+1;
    for(int i=st+1;i<=ed;i++){
        if(s>a[i]){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[st],a[j-1]);
    return j-1;
}

void quick_sort(int a[],int st,int en){
    if(st<en){
        int po=part(a,st,en);
        quick_sort(a,st,po-1);
        quick_sort(a,po+1,en);
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

}

