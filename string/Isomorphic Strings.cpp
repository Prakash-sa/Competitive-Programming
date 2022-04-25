//https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#






class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int s1[26]={0};
        int s2[26]={0};
        for(auto it:str1)s1[it-'a']++;
        for(auto it:str2)s2[it-'a']++;
        int n=str1.size();
        if(n!=str2.size())return false;
        for(int i=0;i<n;i++){
            if(s1[str1[i]-'a']!=s2[str2[i]-'a'])return false;
        }
        return true;
        
    }
};
