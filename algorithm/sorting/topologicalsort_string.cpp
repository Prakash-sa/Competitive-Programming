#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

int32_t main(){
	boost;
	int  n; cin>>n;
    string str[n];
    for(int i=0; i<n; i++)
        cin>>str[i];
    vector<int> graph[26];
    int in[26]={0};
    queue<int> q;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<str[i].length() && j<str[i-1].length(); j++)
        {
            if(str[i][j]!=str[i-1][j])
            {
                graph[str[i-1][j]-'a'].push_back(str[i][j]-'a');
                in[str[i][j]-'a']++;
                break;
            }
            if(j+1==str[i].length() && j+1<str[i-1].length()) 
                { cout<<"Impossible" ; return 0; }   
        }
    } 
    for(int i=0; i<26; i++)
        if(in[i]==0) q.push(i);
        
    vector<int> topo;    
    while(!q.empty())
    {
        int temp=q.front(); q.pop();
        topo.push_back(temp);
        for(int i=0; i<graph[temp].size(); i++)
        {
            in[graph[temp][i]]--;
            if(in[graph[temp][i]]==0) q.push(graph[temp][i]);
        }
    }
    if(topo.size()==26)
        for(int i=0; i<26; i++)
            cout<<(char)(topo[i]+'a');    
    else cout<<"Impossible";        
    return 0;         

}
