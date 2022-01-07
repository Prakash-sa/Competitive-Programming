/*
#Time Complexity
					 
			
Best O(n)
			
Worst O(n^2)
			
Average O(n^2)
			
#Space Complexity:- O(1)

*/


#include<iostream>

using namespace std;

int main()
{
    int n,A[2014];
    cin>>n;
    for(int k=0;k<n;k++)cin>>A[k];

    //sorting

    for(int l=1;l<n;l++)
    {
        int current=l;
        while(current!=0){
            if(A[current-1]<A[current])break;

            else{
                int tmp=A[current-1];
                A[current-1]=A[current];
                A[current]=tmp;

            }
            current=current-1;
        }

    }
    for(int i=0;i<n;i++)cout<<A[i]<<endl;

}