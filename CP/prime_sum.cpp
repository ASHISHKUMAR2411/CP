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
int number[MAX+1];
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
    for(int i=1;i<=maxN;i++) 
    {
        if(isPrime[i]) number[i] = i;
        else number[i] =0;
    }
    for(int i=1;i<=maxN;i++) number[i] += number[i-1];
}
int main()
{
    fast;
    sieve();
    int n,l,r,count=0;
    cin>>n;
    while(n--)
    {
        cin>>l>>r;
        count = number[r]-number[l-1];
        cout<<count<<endl;
    }
}

