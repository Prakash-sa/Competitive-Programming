#include<iostream>
using namespace std;

bool checkSameElementExistence(vector<int> arr1, vector<int> arr2) {
    int flag=0;
    for(int i=0;i<arr1.size();i++){
        auto k=lower_bound(arr2.begin(),arr2.end(),arr1[i]);
        if(k-arr2.begin()<arr2.size()&&arr2[k-arr2.begin()]==arr1[i]){
            flag=1;
            break;
        }
    }
    if(flag==1)return true;
    else return false;
}


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