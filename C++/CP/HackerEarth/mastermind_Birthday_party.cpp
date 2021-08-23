#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 1000000
using namespace std;
lli isPrime[MAX+1];
// lli sum[MAX+1];
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
    // sum[0] = 0;
    // for(int i = 1;i<=MAX;i++)
    // {
    //     if(isPrime[i] == 0 && i!=4)
    //     {
    //         sum[i] = sum[i-1]+1;
    //     }
    //     else sum[i]=sum[i-1];
    // }
    for(int i =1;i<=maxN;i++)
    {
        if(isPrime[i]) isPrime[i] = 0;
        else if(i==4) ; 
        else isPrime[i] = 1;
    }
    for(int i = 1;i<=maxN;i++) isPrime[i] += isPrime[i-1];
}
int main()
{

    fast;
    sieve();
    int t,n,count =0,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<(isPrime[r]-isPrime[l-1])<<endl;
    }
}