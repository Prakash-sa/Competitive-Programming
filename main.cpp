#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i, a, b) for (lli i = a; i <= b; i++)
#define RF(i, a, b) for (lli i = a; i >= b; i--)
#define endl "\n"
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<int> dp;

int main()
{
    speed;
    int n;
    cin >> n;
    while (n--)
    {
        int n1, k, ans = 0;
        if(root==nullptr){
            return 0;
        }
       queue<TreeNode*>q;
       q.push(root);
       int ans=0;
       while(!q.empty()){
        int len=q.size();
        for(int i=0;i<len;i++){
            TreeNode*node=q.front();
            q.pop();
            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
        }
       }

        cin >> n1;
        vector<int> a;
        for (int i = 0; i < n1; i++)
        {
            cin >> k;
            a.push_back(k);
        }
        for (int i = 0; i < n1 - 1; i++)
        {
            int d = 0;
            for (int j = i + 1; j < n1; j++)
            {
                d += a[j - 1] - a[j];
                if (d != a[j] - a[i])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
vector<int>dist(n,INT_MAX);
distances[source]=0;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
heap.push({0,source});



while(!heap.empty()){
    int curDist=heap.top().first;
    int node=heap.top().second;
    heap.pop();
    if(curDist>distance[node]){
        continue;
    }
    for(pair<int,int>edge:graph[node]){
        int nei=edge.first;
        int weight=edge.second;
        int dist=currDist+weight;
        if(dist<distances[nei]){
            distances[nei]=dist;
            heap.push({dist,nei});
        }
    }
}
