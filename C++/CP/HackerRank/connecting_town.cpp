#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int main()
{
    fast;
    int mo = 1234567;
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        int A[n];
        for(int i =0;i<n;i++)
        {
            cin>>A[i];
        }
        int product = 1;
        for(int i = 1;i<n;i++)
        {
            product = (((product%mo) * (A[i]%mo))%mo); 
        }
        cout<<product<<endl;
    }
}