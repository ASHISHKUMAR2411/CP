#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 10000007
#define endl '\n'
using namespace std;
lli modularExponent(lli a, lli n)
{
    lli res = 1;
    while (n)
    {
        if (n % 2)
            res = (res % mod * a % mod) % mod, n--;
        else
            a = (a % mod * a % mod) % mod, n /= 2;
    }
    return res;
}
int main()
{
    fast;
    lli n = 1, k = 1, res;
    while (true)
    {
        cin >> n >> k;
        if(n==0 && k == 0) break;
        res = ((2 * (modularExponent(n - 1, k) % mod)) % mod + (2 * (modularExponent(n - 1, n - 1) % mod)) % mod + modularExponent(n, k) % mod + modularExponent(n, n) % mod) % mod;
        cout << res << endl;
    }
    return 0;
}