#include <bits/stdc++.h>

using namespace std;

//propagating error
class Calculator{
    public:

    int power(int n,int p){
        if(n<0||p<0)throw runtime_error("n and p should be non-negative");
        return pow(n,p);
    }

};

//Generics
template<typename E>
void printArray(vector<E> s){
    for(int i=0;i<s.size();i++)cout<<s[i]<<endl;
}


int main(){
    string S;
    cin >> S;
    try{
        int k=stoi(S);
        cout<<k<<endl;
    }catch(exception a){
        cout<<"Bad String\n";
    }
    return 0;
}