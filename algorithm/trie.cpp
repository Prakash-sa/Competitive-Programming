#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ii> vii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second

struct trienode{
    trienode* child[26];
    bool isend;
};

trienode *getnode(){
    trienode* p=new trienode;
    p->isend=false;
    for(int i=0;i<26;i++)
    p->child[i]=NULL;
    return p;
}

void insert(trienode* node,string s){
    trienode* p=node;
    for(int i=0;i<s.length();i++){
      int index=s[i]-'a';
      if(p->child[index]==NULL)p->child[index]=getnode();
      p=p->child[index];
    }
    p->isend=true;
}

bool search(trienode *node,string s){
    trienode* p=node;
    for(int i=0;i<s.length();i++){
        int index =s[i]-'a';
        if(p->child[index]==NULL)return false;
        else p=p->child[index];
    }
    if(p->isend==true)return true;
}

int maxi_el(Trie* curr, int val)
{
	bitset<32> b(val);
	string s = b.to_string();
	int ans = 0;
	for(int j = 0; j < 32; j++)
	{
		if(s[j] == '0')
		{
			if(curr->zero) curr = curr->zero;
			else 
			{
				ans+=pow(2, 31 - j);
				curr = curr->one;
			}
		}
		else
		{
			if(curr->one) curr = curr->one;
			else
			{
				ans+=pow(2, 31 - j);
				curr = curr->zero;
			}
		}
		
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Trie* head = new Trie;
	int n, a, b; cin >> n;
	int xor_el = 0;
	add_element(head, 0);
	while(n--)
	{
		cin >> a ;
		if(a == 1) { cin >> b; add_element(head, b^xor_el); }
		if(a == 2) { cin >> b; xor_el^=b; }
		if(a == 3) { cout << maxi_el(head, xor_el) << endl; }
	}
}

