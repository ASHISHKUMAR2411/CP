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
    lli t , a,b,x,result;
    lli mo = 1e9 +1;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x;
        if(b<0)
        {
            cout<<0<<endl;
            continue;
        }
        a = a%mo;
        b = b%mo;
        lli po = modularExponent(a,b,mo);
        long long int i  = po/x;
        if(abs((po-(x*i)))<= abs((po-(x*(i+1))))) result = (x*i);
        else result = (x*(i+1));
        cout<<result<<endl;
    }
}