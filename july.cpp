<<<<<<< HEAD

#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
template <class T>
void sortArray(T a[], int n)
{ 
	sort(a,a+n);
}
template <class T>
void printArray(T a[], int n)
{
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	int n, q, i;
	cin>>n>>q;
	
	int intArr[n];
	string strArr[n];
    float floatArr[n];
    
	switch(q)
	{
	    case 1:
	    for(i=0; i<n; i++)
	    {
	        cin>>intArr[i];
	    }
	    sortArray(intArr, n);
    	printArray(intArr, n);
    	break;
        
        case 2:
	    for(i=0; i<n; i++)
	    {
	        cin>>strArr[i];
	    }
	    sortArray(strArr, n);
    	printArray(strArr, n);
    	break;
    	
        case 3:
	    for(i=0; i<n; i++)
	    {
	        cin>>floatArr[i];
	    }
	    sortArray(floatArr, n);
    	printArray(floatArr, n);
    	break;
	}
    }
	return 0;
}


=======
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F(i,a,b) for(lli i = a; i <= b; i++)
#define RF(i,a,b) for(lli i = a; i >= b; i--)
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
   // speed;
   lli n,sum=0,k=0;
   cin>>n;
   lli a[n],c[100],l=0,res=0;
   vector<int>v;
  // memset(v,-1,sizeof(v));
   //memset(c,-1,sizeof(c));
   F(i,0,n-1)cin>>a[i];
   F(i,0,n-1)sum+=a[i];
   sum=sum/2;
   if(n==2){
       if(a[0]>a[1]){
           cout<<"1"<<" "<<"1"<<endl;
       }
       else cout<<"0"<<endl;
   }
   else {
    for(lli i=1;i<n;i++){
        if(a[0]>=2*a[i]){
            res=a[0]+a[i]+res;
            v.push_back(i);
            if(res>sum){
                // c[l]=k;
                // k++;
                // l++;
                k=1;
                break;
                
            }
            
            //v[k].push_back(i);
        }

    }
if(k==1){
    cout<<v.size()+1<<endl;
    cout<<"1"<<" ";
    for(int i=0;i<v.size();i++)
    cout<<v[i]+1<<" ";
   }
   
   else cout<<"0";
   }
//    cout<<v[c[0]].size()<<endl;


    
    return 0;
}
>>>>>>> 4e1dc46759781f5165e6668e36a23c0b03142970
