#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    int A[2*n-1][2*n-1];
    int k =n;
    for(int i =0;i<n;i++)
    {
        for(int j = i ; j<(2*n-1-i);j++)
        {
            A[i][j] = k;
            A[j][i] = k;
            A[j][2*n-2-i] = k;
            A[2*n-2-i][j] = k;
            
        }
        k--;
    }
    for(int i =0;i<2*n-1;i++)
    {
        for(int j =0;j<2*n-1;j++)
        {
            cout<<" "<<A[i][j];
        }
        cout<<"\n";
    }
}