#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define pb push_back
#define sz(x) (int)(x).size()
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
lli modularExponent(lli a, lli n, lli p)
{
    lli res = 1;
    while (n)
    {
        if (n % 2)
            res = (res % p * a % p) % p, n--;
        else
            a = (a % p * a % p) % p, n /= 2;
    }
    return res;
}
int main(){
    fast;
    lli t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<modularExponent(a,b,10)<<endl;
    }
}