#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf (1000*1000*1000+5)

//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3

typedef struct data
{
  data* child[26];
  int cnt=0;
}trie;

const int N=1e5+1;
trie* root;
int n,k;
string a[N];
int ans;

void insert(string s){
  trie* cur=root;
  for(int i=0;i<s.size();i++){
    int ch=s[i]-'A';
    if(cur->child[ch]==0){
        cur->child[ch]=new trie();
    }
    cur=cur->child[ch];
  }
  cur->cnt++;
}

void dfs(trie* tmp,int l){
  for(int i=0;i<26;i++){
    if(tmp->child[i]){
      dfs(tmp->child[i],l+1);
      tmp->cnt+=tmp->child[i]->cnt;
    }
  }
  while (tmp->cnt>=k)
  {
    tmp->cnt-=k;
    ans+=l;
  }
  
}

int main(){
  boost;
  int t,cnt=1;
  cin>>t;
  while(t--){
    cin>>n>>k;
    ans=0;
    root=new trie();
    string tmp;
    for(int i=0;i<n;i++){
      cin>>tmp;
      insert(tmp);
    }
    dfs(root,0);
    cout<<"Case #"<<cnt<<": "<<ans<<endl;
    cnt++;
  }
return 0;
}
