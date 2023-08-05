#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define endl '\n'
#define pi pair<lli, lli>
using namespace std;
pi fib(lli n){
    if (n == 0)
        return {0, 1};
    auto p = fib(n >> 1);
    lli c = ((p.first % mod) * ((2 * (p.second % mod)) % mod - p.first % mod + mod)) % mod;
    lli d = (p.first % mod * p.first % mod) % mod + (p.second % mod * p.second % mod) % mod;
    if (n & 1)
        return {d, (c + d) % mod};
    else
        return {c, d};
}
int main()
{
    fast;
    lli t, n;
    pi p;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 0)
            cout << 0 << endl;
        else if (n == 1)
            cout << 2 << endl;
        else if (n % 2 == 0)
        {
            p = fib(n + 1);
            cout << (p.first % mod + p.second % mod) % mod << endl;
        }
        else
        {
            p = fib(n + 2);
            if(p.second<0) p.second += mod;
            cout << p.second % mod<<endl;
        }
    }
}
// 101 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 1000000000000000000
