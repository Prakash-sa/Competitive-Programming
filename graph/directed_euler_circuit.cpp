#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)
const int NODE =1e4+9;
/*
const int mod=1e9+9;
const int num=1e5+5;
lli dp[num+1];
lli ans[6][num+1]={0};

void init(){

}

 
int main()
{
   boost;
   int t=1,h=1;
   cin>>t;
   while(t--){
       double n;
       cin>>n;
       cout<<ceil(n/2)<<endl;
   }
   return 0;
}

*/
int n;
int graph[NODE][NODE] = {0};
               
void traverse(int u, bool visited[]) {
   visited[u] = true;    
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            traverse(v, visited);
      }
   }
}

bool isConnected() {
   bool *vis = new bool[NODE];
   for(int u; u < NODE; u++) {
      for(int i = 0; i<NODE; i++)
         vis[i] = false;    
      traverse(u, vis);
         
      for(int i = 0; i<NODE; i++) {
         if(!vis[i]) return false;
      }
   }
   return true;
}

bool isEulerCircuit() {
   if(isConnected() == false) { 
      return false;
   }

   vector<int> inward(NODE, 0), outward(NODE, 0);
         
   for(int i = 0; i<NODE; i++) {
      int sum = 0;
      for(int j = 0; j<NODE; j++) {
         if(graph[i][j]) {
            inward[j]++;    //increase inward edge for destination vertex
            sum++;    //how many outward edge
         }
      }
      outward[i] = sum;
   }

   if(inward == outward)    //when number inward edges and outward edges for each node is same
      return true;
   return false;
}

int main() {
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[--a][--b]=1;
    }
   if(isEulerCircuit())
      cout << "Euler Circuit Found.";
   else
      cout << "There is no Euler Circuit.";
}

