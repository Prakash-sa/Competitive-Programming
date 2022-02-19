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
