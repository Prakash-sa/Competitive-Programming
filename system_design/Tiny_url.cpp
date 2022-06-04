/*
Let's assume we want to serve more than 1000 billion URLs. If we can use 62 characters [A-Z, a-z, 0-9] for the short URLs having length n, then we can have total 62^n URLs. So, we should keep our URLs as short as possible given that it should fulfill the requirement. For our requirement, we should use n=7 i.e the length of short URLs will be 7 and we can serve 62^7 ~= 3500 billion URLs.

https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-%28-TinyURL-%29-System/

*/



string idToShortURL(long int n)
{
    // Map to store 62 possible characters
    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                 "GHIJKLMNOPQRSTUVWXYZ0123456789";
  
    string shorturl;
  
    // Convert given integer id to a base 62 number
    while (n)
    {
        shorturl.push_back(map[n%62]);
        n = n/62;
    }
  
    // Reverse shortURL to complete base conversion
    reverse(shorturl.begin(), shorturl.end());
  
    return shorturl;
}
  
// Function to get integer ID back from a short url
long int shortURLtoID(string shortURL)
{
    long int id = 0; // initialize result
  
    // A simple base conversion logic
    for (int i=0; i < shortURL.length(); i++)
    {
        if ('a' <= shortURL[i] && shortURL[i] <= 'z')
          id = id*62 + shortURL[i] - 'a';
        if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
          id = id*62 + shortURL[i] - 'A' + 26;
        if ('0' <= shortURL[i] && shortURL[i] <= '9')
          id = id*62 + shortURL[i] - '0' + 52;
    }
    return id;
}




//https://practice.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener2031/1


#include<bits/stdc++.h>
using namespace std;
string idtostring(int id){
    char map[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string st;
    while(id){
        st+=map[id%62];
        id=id/62;
    }
    reverse(st.begin(),st.end());
    return st;
}

int stringtoid(string st){
    int id=0;
    for(int i=0;i<st.size();i++){
        if(st[i]>='a'&&st[i]<='z')id=id*62+st[i]-'a';
        if(st[i]>='A'&&st[i]<='Z')id=id*62+st[i]-'A'+26;
        if(st[i]>='0'&&st[i]<='9')id=id*62+st[i]-'0'+52;
    }
    return id;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s=idtostring(n);
	    int k=stringtoid(s);
	    cout<<s<<endl;
	    cout<<k<<endl;
	}
	return 0;
}