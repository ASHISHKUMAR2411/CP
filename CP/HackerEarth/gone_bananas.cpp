#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 1000000
using namespace std;
bool isPrime[MAX+1];
void sieve()
{
    int maxN = MAX;
    for(int i = 1;i<=maxN;i++)
    isPrime[i]=1;
    isPrime[0]=isPrime[1]=0;
    for(int i =2 ;i*i<=maxN;i++)
    {
        if(isPrime[i])
        {
            for(int j = i*i ;j<=maxN;j+=i)
            {
                isPrime[j] = 0;
            }
        }
    }
}
int main()
{
    fast;
    int t,n;
    sieve();
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(isPrime[n]) cout<<"No"<<endl;
        else if(n/2 > 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}