#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
bool arr[86028122];
vi prime;
void sieve()
{
    int maxN = 86028122;
    arr[0] = arr[1] = true;
    for(int i = 2;i*i<=maxN;i++)
    {
        if(!arr[i])
        {
            for(int j = i*i;j<=maxN;j+=i)
            arr[j] = true;
        }
    }
    for(int i =2;i<=maxN;i++)
    {
        if(!arr[i])
        {
            prime.push_back(i);
        }
    }
}
// always use "\n" than endl ,
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* code  */
    int q ,n;
    cin>>q;
    sieve();
    while(q--)
    {
        cin>>n;
        cout<< prime[n-1] << endl;
    }
    return 0;
}
