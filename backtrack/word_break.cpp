//https://practice.geeksforgeeks.org/problems/word-break-part-23249/1#   

   vector<string> ans;
   map<string,int>mp; 
  void solve(string &s,string &v,int pos)
  {
      if(pos==s.size())
      {
          v.pop_back();
          ans.push_back(v);
          return;
      }
      
      string temp="";
      for(int i=pos;i<s.size();++i)
      {
          temp+=s[i];
          if(mp.find(s.substr(pos,i-pos+1))!=mp.end())
          {
              string p=v+temp+" ";
              solve(s,p,i+1);
          }
      }
  }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        for(int i=0;i<n;++i)
        mp[dict[i]]++;
        string str;
        solve(s,str,0);
       // cout<<endl;
        return ans;
    }

//Word break 1

//https://leetcode.com/problems/word-break/


class Solution {
public:
    
    int dp[305];
    
    bool find(string s,int in,unordered_set<string>&arr){
        if(s.length()==in){
            return 1;
        }
        
        if(dp[in]!=-1)return dp[in];
        
        for(int i=1;i<=s.length()-in;i++){
            if(arr.find(s.substr(in,i))!=arr.end() && find(s,i+in,arr))return dp[in]=1;
        }
        return dp[in]=0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string>arr(wordDict.begin(),wordDict.end());
        return find(s,0,arr);
    }
};



//Word break 2

//https://leetcode.com/problems/word-break-ii/




class Solution {
    vector<string>res;
    unordered_set<string>st;
    void backtrack(string s,string &ans,int x){
        if(x==s.size()){
            ans.pop_back();
            res.push_back(ans);
            return;
        }
        string tmp="";
        for(int i=1;i<=s.size()-x;i++){
            tmp=s.substr(x,i);
            if(st.find(tmp)!=st.end()){
                string t=ans+tmp+" ";
                backtrack(s,t,x+i);
            }
        }
        
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st=unordered_set<string>(wordDict.begin(),wordDict.end());
        string ans="";
        backtrack(s,ans,0);
        return res;
    }
};









