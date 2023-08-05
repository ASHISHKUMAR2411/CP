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
int primePrime[MAX+1];
/* or we can use bool isPrime[max+1] */
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
    int cnt = 0;
    for(int i=1;i<=maxN;i++)
    {
        if(isPrime[i]==1) cnt++;
        if(isPrime[cnt]==1) primePrime[i] = 1;
        else primePrime[i] = 0;
    }
    for(int i=1;i<=maxN;i++) primePrime[i]+=primePrime[i-1];
}
int main()
{
    fast;
    sieve();
    int t,l,r,cnt=0;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<primePrime[r]<<endl;
    }
}










