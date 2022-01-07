/*
Time Complexity
					 
			
Best
					O(nlog n)
			
Worst
					O(nlog n)
			
Average
					O(nlog n)
			
Space Complexity
					O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int N;

void max_heap(int arr[],int i,int n){

    int l=2*i;
    int r=2*i+1;
    int larget=i;
    if(l<=n&&r<=n){
        if(arr[l]>arr[r])larget=l;
        else larget=r;
    }
    else if(l<=n&&arr[l]>arr[i])larget=l;
    else if(r<=n&&arr[r]>arr[i])larget=r;
    if(larget!=i){
        swap(arr[i],arr[larget]);
        max_heap(arr,larget,n);
    }


}

void build_maxheap(int arr[]){
for(int i=N/2;i>0;i--)max_heap(arr,i,N);

}

void heap_sort(int arr[]){
    
    for (int i = N; i > 0; i--) {
      swap(arr[1], arr[i]);
  
      // Heapify root element to get highest element at root again
      max_heap(arr, 1, i);
    }


}


int main()
{
    int n;
    cin>>N;
    int a[N+1];
    for(int i=1;i<=N;i++)cin>>a[i];
    build_maxheap(a);
    for(int i=1;i<=N;i++)cout<<a[i]<<" ";

}
