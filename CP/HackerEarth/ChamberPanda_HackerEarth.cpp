#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
using namespace std;
lli n, x, t;
lli mod = 1e6 + 3;
int main()
{
    cin >> t;
    lli a[(int)1e5 + 1];
    a[0] = 1;
    for (int i = 1; i <= 1e5; i++)
    {
        a[i] = (a[i - 1] % mod * i % mod) % mod;
    }
    while (t--)
    {
        cin >> n >> k;
        lli ans = 1;
        if (n > mod)
            cout << 0 << endl;
        else
            cout << (a[n] % mod * k % mod) % mod << endl;
    }
}