#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
using namespace std;
lli pow_of_3(lli n)
{
    lli t = n;
    lli res = 1, base = 3;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        n = n >> 1;
    }
    return res;
}

int main()
{
    fast;
    lli t, ans, n, n1, c;
    cin>>t;
    while (t--)
    {
        cin>>n;
        if (n == 1)
        {
            ans = 1;
            goto l;
        }
        c = n % 3;
        if (c == 2)
            n1 = (n - 2) / 3;
        else if (c == 1)
            n1 = (n - 4) / 3;
        else
            n1 = n / 3;
        ans = pow_of_3(n1);
        if (n % 3 == 2)
            ans = (ans * 2) % mod;
        else if (n % 3 == 1)
            ans = (ans * 4) % mod;
    l:
        cout<<ans<<endl;
    }
    return 0;
}