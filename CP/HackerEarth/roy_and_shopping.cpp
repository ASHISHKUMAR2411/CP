#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 1000000
using namespace std;
// int isPrime[MAX+1];
int ar[MAX+1];
void sieveFactorization()
{
    int maxN = MAX;
    for(int i = 1 ;i<=maxN;i++) ar[i] = -1;
    for(int i = 2; i*i<=maxN;i++){
        if(ar[i]==-1)
        {
            for(int j = i*i;j<=maxN;j+=i){
                if(ar[j]== -1) ar[j] = i;
            }
        }
    }
    for(int i = 2;i<+maxN;i++)
    if(ar[i]==-1) ar[i]=i;
}
int main()
{
    fast;
    sieveFactorization();
    int n,r;
    cin>>n;
    while(n--)
    {
        cin>>r;
        cout<<(r-ar[r])<<endl;
    }
}