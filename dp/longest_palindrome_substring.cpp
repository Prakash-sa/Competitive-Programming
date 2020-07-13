#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    
	    int maxLength = 1; 
  
        int start = 0; 
        int len = s.size(); 
      
        int low, high; 
        for (int i = 1; i < len; ++i) { 
            low = i - 1; 
            high = i; 
            while (low >= 0 && high < len 
                   && s[low] == s[high]) { 
                if (high - low + 1 > maxLength) { 
                    start = low; 
                    maxLength = high - low + 1; 
                } 
                --low; 
                ++high; 
            } 
      
            low = i - 1; 
            high = i + 1; 
            while (low >= 0 && high < len 
                   && s[low] == s[high]) { 
                if (high - low + 1 > maxLength) { 
                    start = low; 
                    maxLength = high - low + 1; 
                } 
                --low; 
                ++high; 
            } 
        } 
        string ans=s.substr(start,maxLength);
        if(ans.size()>0)
	    cout<<ans<<endl;
	    else cout<<s[0]<<endl;
	
	}
	return 0;
}