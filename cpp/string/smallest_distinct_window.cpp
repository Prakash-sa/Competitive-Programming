//https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#






class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>mp;
        for(auto it:str)mp[it]++;
        int size=mp.size();
        mp.clear();
        int count=0,len=INT_MAX;
        int sInd=-1,start=0;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
            count=mp.size();
            if(count==size){
                while(mp[str[start]]>1){
                    if(mp[str[start]]>1)
                    mp[str[start]]--;
                    start++;
                }
                int len_tmp=i-start+1;
                if(len>len_tmp){
                    len=len_tmp;
                    sInd=start;
                }
            }
            
        }
        return len;
    }
};
