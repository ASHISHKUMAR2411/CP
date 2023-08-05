#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
vi factors;
void primeFac(int N)
{
    for(int i =2;i*i<=N;i++)
    {
        int cnt = 0;
        while(N%i ==0)
        {
            cnt++;
            N/=i;
        }
        if(cnt>0) factors.push_back((i*cnt));
    }
    if(N>1) factors.push_back(N);
}
int main()
{
    fast;
    int n;
    cin>>n;
    primeFac(n);
    int sum1 = 0,sum2 = 0;
    while(n) 
    {
        sum1 += n%10;
        n = n/10;
    }
    for(int i =0;i<(int)(factors.size());i++ )
    {
        while(factors[i])
        {
            sum2 += factors[i]%10;
            factors[i] = factors[i]/10;
        }
    }
    if(sum1==sum2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
}