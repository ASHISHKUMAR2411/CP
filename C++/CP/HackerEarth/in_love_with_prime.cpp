#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 100000
using namespace std;
int ar[MAX+1];
vi prime;
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
    prime.push_back(2);
    prime.push_back(3);
    for(int i = 2;i<+maxN;i++)
    if(ar[i]==-1) prime.push_back(i);
}
int main()
{
    fast;
    sieveFactorization();
    int n,tc;
    cin>>tc;
    xyz:
    while(tc--)
    {
        cin>>n;
        if(n%2==0)
        {
            if(n==2)
            {
                cout<<"Arjit"<<endl;
            }
            else{
                for(int i = 0;i<(int)(prime.size());i++)
                {
                    for(int j = 0;j<(int)(prime.size());j++)
                    {
                        if((prime[i]+prime[j])==n)
                        {
                            cout<<"Deepa"<<endl;
                            goto xyz;
                        }
                    }
                }
                cout<<"Arjit"<<endl;
                
            }
        }
    }
}