// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
    
    int merge(vector<int>&arr,int start,int mid,int end){
        int p=start,q=mid+1;
        int arr_tmp[end-start+1];
        int k=0;
        int cnt=0;
        while((p<=mid ) && (q<=end)){
            if(arr[p]<=arr[q])arr_tmp[k++]=arr[p++];
            else {
                cnt+=(mid-p+1);
                arr_tmp[k++]=arr[q++];
            }
        }
        while(p<=mid)arr_tmp[k++]=arr[p++];
        while(q<=mid)arr_tmp[k++]=arr[q++];
        for(p=0;p<k;p++)arr[start+p]=arr_tmp[p];
        return cnt;
    }
    
    int merge_sort(vector<int>&arr,int start,int end){
        int cnt=0;
        if(start>=end)return cnt;
        int mid=(start+end)/2;
        cnt+=merge_sort(arr,start,mid);
        cnt+=merge_sort(arr,mid+1,end);
        cnt+=merge(arr,start,mid,end);
        return cnt;
    }
 
    
    
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
       return merge_sort(arr,0,arr.size()-1);
    }
};
