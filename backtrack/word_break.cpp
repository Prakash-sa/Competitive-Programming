//https://practice.geeksforgeeks.org/problems/word-break-part-23249/1#   

/*
Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. 
Each dictionary word can be used more than once. 
Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
*/

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

/*
Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
*/


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

/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
*/



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
