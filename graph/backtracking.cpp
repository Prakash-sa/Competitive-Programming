#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;

bool isSafe(int b[][10],int r,int c,int n)
{
    int i,j;

    for(i=0;i<c;i++)
    {
        if(b[r][i])
        return false;
    }

    for(i=r,j=c;i>=0&&j>=0;i--,j--)
    {
        if(b[i][j])
        return false;
    }

    for(i=r,j=c;i<n&&j>=0;i++,j--)
    {
        if(b[i][j])
        return false;
    }

    return true;
}

bool solve(int b[][10],int c,int n)
{
    int i;
    if(c>=n)
    return true;

    for(i=0;i<n;i++)
    {
        if(isSafe(b,i,c,n)){
        b[i][c]=1;

        if(solve(b,c+1,n))
        return true;

        b[i][c]=0;
        }
    }
    return false;
}
void display(int b[][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<b[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int c[10][10]={0};
    if(solve(c,0,n)==false)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
        display(c,n);
    }
    return 0;
}