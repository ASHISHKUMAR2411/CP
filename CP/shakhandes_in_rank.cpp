#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int main()
{
    fast;
    int n;
    lli t;
    cin>>n;
    while(n--)
    {
        cin>>t;
        cout<<(t*(t-1))/2<<endl;
    }
}