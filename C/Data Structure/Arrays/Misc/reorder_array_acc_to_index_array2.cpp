#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    int ind[n],arr[n];
    cout<<"\nenter the index input and array input : \n";
    for(int i =0;i<n;i++)
    {
        there:
        cout<<"\nenter the index : ";
        cin>>ind[i];
        if(ind[i]>=n)
        {
            cout<<"\nenter again: ";
            goto there;
        }
        cout<<"\nenter the corresponding array element : ";
        cin>>arr[ind[i]];
    }
    cout<<"\nthe array is : ";
    for(int i =0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
    cout<<" \nthe index array is : ";
    for(int i =0 ;i<n;i++)
    {
        cout<<" "<<i;
    }
}