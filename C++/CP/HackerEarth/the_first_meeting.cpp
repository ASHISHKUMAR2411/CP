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
    sieve();
    int n;
    cin>>n;
    int A[n];
    for(int i = 0;i<n;i++) cin>>A[i];
    sort(A,A+n);
    int i = 0,first = 0 , last =0;
    while(i<n)
    {
        if(isPrime[A[i]]) {
            first = A[i] ;
            break;
        }
        i++;
    }
    for(int i = n-1 ;i>=0;i--)
    if(isPrime[A[i]]){
        last = A[i];
        break;
    }
    if(first)
    cout<<abs(last-first)<<endl; 
    else 
    cout<<-1<<endl;

}