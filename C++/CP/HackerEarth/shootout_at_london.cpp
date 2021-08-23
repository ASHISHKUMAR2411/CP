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
    vi position;
    int n,pr = 0;
    cin>>n;
    int A[n+1];
    for(int i =1;i<=n;i++)
    {
        cin>>A[i];
        if(isPrime[A[i]]) pr = 1;
    }
    if(pr)
    {
        for(int i = 1;i<=n;i++)
        {
            if(isPrime[A[i]])
            {
                A[i] = i;
                pr = i;
                position.push_back(i);
            }
            else A[i] = 0;
        }
        int j = 0;
        for(int i = 1;i<=n;i++)
        {
            while( ((j+1) < (int)(position.size())) && i <= position[j+1] && i<=n)
            {
                if((abs(i-position[j])) <= (abs(i-position[j+1])))
                {
                    A[i] = position[j];
                }
                else{
                    A[i] = position[j+1];
                }
                i++;
            }
            if((j+1)==(int)(position.size()))
            {
                i = position[j] ;
                while(i++ <= n)
                {
                    A[i] = position[j];
                }
            }
            j++;
        }
        for(int i =1;i<=n;i++)
        {
            if(A[i]==0) A[i] = A[i-1];
            cout<<A[i]<<" ";
        }
    }
    else {
        for(int i =0;i<n;i++)
        {
            cout<<-1<<" ";
        }
    }
}