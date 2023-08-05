#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// long long dp[1000001];

int main()
{
    int t;
    cin >> t;
    int mod = 1000007;
    // memset(dp, 0, sizeof(dp));
    for (int k = 0; k < t; k++)
    {
        long long n, sum = 0;
        cin >> n;
        sum = (n * (3 * n + 1)) / 2;
        cout << sum % mod << endl;
    }
    return 0;
}