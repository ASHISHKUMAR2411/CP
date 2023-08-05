#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
lli modularExponent(lli a, lli n,lli p)
{
    lli res = 1;
    while (n)
    {
        if(n%2)
            res = (res%p * a%p)%p,n--;
        else a = (a%p * a%p)%p , n/=2;
    }
    return res ;
}
int main()
{
    fast;
    int t;
    lli mo = 1e9+7;
    lli a , b ,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        lli f = ((((((modularExponent(b,n-1,mo))%mo)*(a%mo))%mo)*((modularExponent((modularExponent(a,n-1,mo)),mo-2,mo))%mo))%mo);
        cout<<f<<endl;
    }
}