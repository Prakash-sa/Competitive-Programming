#include<bits/stdc++.h>
using namespace std;
/*
int GCD(int a,int b)
{
    if(b==0) return a;

    return GCD(b,a%b);

}


int main()
{
    cout<<"hi there";
    int k;
    k=GCD(270,192);
    cout<<k<<endl;

}
*/

long long x,y;
long long extended_gcd(long long a,long long b)
{
    if(b==0)
    {
        //x=1;y=0;
        return a;
    }
    long long g=extended_gcd(b,a%b);
    // long long x1=x;
    // long long y1=y;
    // x=y1;
    // y=x1-((a/b)*y1);
    return g;

}

int main()
{
    int k,k1;
    cin>>k>>k1;
    int l=__gcd(k,k1);
    cout<<l;
    
}

//-----------------------------------
#include<iostream> 
using namespace std; 
  
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y); 
  
// Function to find modulo inverse of a 
void modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // m is added to handle negative x 
        int res = (x%m + m) % m; 
        cout << "Modular multiplicative inverse is " << res; 
    } 
} 
  
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
  
// Driver Program 
int main() 
{ 
    int a = 221, m = 11; 
    modInverse(a, m); 
    return 0; 
} 