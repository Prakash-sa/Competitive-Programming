//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#


    
    void backtrack(string str,string &maxs,int start,int k)
    {
        if(k==0){
            return;
        }
        int n=str.size();
        char maxi=str[start];
        
        for(int i=start+1;i<n;i++){
            if(maxi<str[i])maxi=str[i];
        }
        
        if(maxi!=str[start])k--;
        
        
        for(int i=n-1;i>=start;i--){
            if(str[i]==maxi){
                swap(str[i],str[start]);
                if(str.compare(maxs)>0)maxs=str;
                backtrack(str,maxs,start+1,k);
                swap(str[i],str[start]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string maxs=str;
       backtrack(str,maxs,0,k);
       return maxs;
       
    }


