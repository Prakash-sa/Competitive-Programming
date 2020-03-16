#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<boost/multiprecision/cpp_int.hpp>
#include <algorithm>
using namespace std;
#define lli long long int
#define max1 10000
namespace mp=boost::multiprecision;

int main() {
    lli n,t;
    cin>>t;
    while(t--){
        cin>>n;
        mp::cpp_int u=1;
        for(int i=1;i<=n;i++)u*=i;
            cout<<u<<endl;

    }
    return 0;
}
