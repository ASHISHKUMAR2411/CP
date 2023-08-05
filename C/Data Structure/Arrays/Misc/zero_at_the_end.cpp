#include<iostream>
using namespace std;
int main()
{
    int n , count = 0 ;
    cout<<"enter the number of element in array ";
    cin>>n;
    int A[n];
    cout<<"enter the array data : ";
    for(int i =0 ;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]!=0)
        {
            A[count++]=A[i];
        }
    }
    while(count<n)
    {
        A[count++]=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<" "<<A[i];
    }

}