#include<iostream>
using namespace std;
int main()
{
    int n , temp =0 ;
    cin>>n;
    int A[n];
    for(int i =0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i =1;i<n;i+=2)
    {
        if(A[i]<=A[i-1])
        {
            swap(A[i],A[i-1]);
        }
    }
    for(int i =0;i<n;i++)
    {
        cout<<" "<<A[i];
    }
}