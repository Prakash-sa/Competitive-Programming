#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
int main(){
cpp_int a,b;
while(cin>>a>>b)
{
cout<<a+b<<"\n";
}
}