#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)


int main(){
  boost;
  string s;
	map<string,int> m;
	cin >> s;
	vector<string> v;
	for(int i = 0; i < s.size();i++)
	{
		m[s.substr(i,s.size()-i)] = i;
		v.push_back(s.substr(i,s.size()-i));
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<" ";
	for(int i = 0; i < v.size();i++)
	{
		cout << m[v[i]] << " ";
	}
	return 0;
}
