#include <iostream>
using namespace std;

void find(int s, int d, int e, int n1, int n2, int &count)
{
    if(n1<=0) return;
    find(s,e,d,n1-1,n2, count);
        count++;
        if(count==n2)
        cout<<s<<" "<<d<<" "<<endl;
    find(e,d,s,n1-1,n2, count);    
}
int main() {
	//code
	int t;
	cin>>t;
	int s=1;
	int e=2;
	int d=3;
	while(t--)
	    {
	        int n1=0, n2=0; 
	        cin>>n1;
	        cin>>n2;
	        int count=0;
	        find(s, d, e, n1, n2, count);
	    }
	return 0;
}


//second one
//https://practice.geeksforgeeks.org/problems/tower-of-hanoi/0

#include <iostream>
using namespace std;

int count;
void find(int s, int d, int e, int n)
{
    if(n<=0) return;
    find(s,e,d,n-1);
    count++;
    cout<<"move disk "<<n<<" from rod "<<s<<" to rod "<<d<<endl;  
    find(e,d,s,n-1);    
}
int main() {
	//code
	int t;
	cin>>t;
	int s=1;
	int e=2;
	int d=3;
	while(t--)
	    {
	        int  n=0; 
	        cin>>n;
	        count=0;
	        find(s, d, e, n);
	        cout<<count<<endl;
	    }
	return 0;
}