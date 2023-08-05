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
    // for(int i=1;i<=maxN;i++) 
    // {
    //     if(isPrime[i]) number[i] = 1;
    //     else number[i] =0;
    // }
    // for(int i=1;i<=maxN;i++) number[i] += number[i-1];
}
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int calculate(int n)
{
    int count=0;
    for(int i =2;i<n;i++)
    {
        if(isPrime[i]);
        else if(gcd(i,n)!=i)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    fast;
    sieve();
    int n,l,r,count=0;
    cin>>n;
    while(n--)
    {
        cin>>l;
        count = 0;
        if(isPrime[l]);
        else{
            count = calculate(l);
        }
        cout<<count<<endl;
    }
}

