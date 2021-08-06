#include<bits/stdc++.h>
using namespace std;
int counofsubsetsum(int arr[],int sum,int n)
{
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
            {
                t[0][j]=0;
            }
            if(j==0)
            {
                t[i][0]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];//respectively...include kiya or include nhi kiya i jo h vo array ko represent krra h
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main()
{
    int arr[]={2,3,5,6,8,10};
    int n=6;
    int sum=10;
    cout<<counofsubsetsum(arr,sum,n);
}
