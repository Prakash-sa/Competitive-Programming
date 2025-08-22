//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#





class Solution 
{
    bool validConfig(int a[],int n,int k,int ans){
        int student=1;
        int current_pages=0;
        for(int i=0;i<n;i++){
            if(current_pages+a[i]>ans){
                student++;
                current_pages=a[i];
                if(student>k)return false;
            }
            else {
                current_pages+=a[i];
            }
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(m>n)return -1;
        
        int total_pages=0;
        int s=0,e=0;
        for(int i=0;i<n;i++){
            total_pages+=a[i];
            s=max(s,a[i]);
        }
        e=total_pages;
        int ans=s;
        while(s<=e){
            int mid=(s+e)/2;
            if(validConfig(a,n,m,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};
