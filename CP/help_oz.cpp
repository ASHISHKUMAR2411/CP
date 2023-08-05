#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr , factors;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(arr.begin(),arr.end());
    int num = (arr[n-1]-arr[0]);
    for(int i = 2; i <=sqrt(num) ;i++)
    {
        if((num%i) == 0)
        {
            if(num/i == i)
            {
                factors.push_back(i);
            }
            else{
                factors.push_back(i);
                factors.push_back(num/i);
            }
        }
    }
    for(int i =0;i<(int)(factors.size());i++)
    {
        int k = A[0]%factors[i];
        int  j =0;
        for(j = 0;j<n;j++)
        {
            if((A[j]%factors[i]) == k);
            else break;
        }
        if(j==n)
        {
            cout<<factors[i]<<" ";
        }
    }
}