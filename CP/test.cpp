#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 100000
using namespace std;
// int isPrime[MAX+1];
// int ar[(int)1e3+1];
// void sieveFactorization()
// {
//     int maxN = 1e3;
//     for(int i = 1 ;i<=maxN;i++) ar[i] = -1;
//     for(int i = 2; i*i<=maxN;i++){
//         if(ar[i]==-1)
//         {
//             for(int j = i*i;j<=maxN;j+=i){
//                 if(ar[j]== -1) ar[j] = i;
//             }
//         }
//     }
//     for(int i = 2;i<+maxN;i++)
//     if(ar[i]==-1) ar[i]=i;
// }
int ar[(int)1e5+1];
vi prime;
void sieveFactorization()
{
    int maxN = 1e5;
    for(int i = 1 ;i<=maxN;i++) ar[i] = -1;
    for(int i = 2; i*i<=maxN;i++){
        if(ar[i]==-1)
        {
            for(int j = i*i;j<=maxN;j+=i){
                if(ar[j]== -1) ar[j] = i;
            }
        }
    }
    prime.push_back(3);
    for(int i = 2;i<+maxN;i++)
    if(ar[i]==-1) prime.push_back(i);
}
int main()
{
    fast;
    sieveFactorization();
    for(int i = 2;i<(int)(prime.size());i++)
    {
        cout<<prime[i]<<" ";
    }
}