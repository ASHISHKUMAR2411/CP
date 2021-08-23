#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define f(i,m) for(int i = 0 ; i<m;i++)
#define fi(i,m) for(int i = 1 ; i<=m;i++)
#define fir(i,n,m) for(int i = n ; i<=m;i++)
#define MAX 1000000000
using namespace std;
bool prime(long int N)
{
    if(N==1) return false;
    for(long int i =2;i*i<=N;i++)
        if(N%i==0) return false;
    return true;
}
int main()
{
    fast;
    int t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(lli i = m ;i<=n;i++)
        {
            if(prime(i)) cout<<i<<endl;
        }
        cout<<endl;
    }
}