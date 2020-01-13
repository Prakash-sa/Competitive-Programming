#include<iostream>
using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    int A[n];
    for(int k=0;k<n;k++)cin>>A[k];
    int low=0;
    int high=n-1;
    int mid;
    int pos=-1;

    while(high>=low){
        mid=(high+low)/2;

        if(A[mid]==s){

            pos=mid;
            break;

        }
        else if(A[mid]<=s){
            low=mid+1;
        }
        else{
            high=mid-1;
        }


    }

    cout<<pos<<endl;
    return 0;

}