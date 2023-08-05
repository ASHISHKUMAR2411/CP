#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isOK(int p, int k, vector<vector<int> > &a, vector<vector<int> > &dp)
{
    int n = a.size() - 1;
    int m = a[0].size() - 1;

    bool ok = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
                continue;

            int x1 = max(1LL, i - p);
            int y1 = max(1LL, j - p);
            int x2 = min(n, i + p);
            int y2 = min(m, j + p);

            int sum = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
            if (sum >= k)
                ok = true;
        }

    return ok;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        k++;

        int sum = 0;
        vector<vector<int> > a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                sum += a[i][j];
            }

        vector<vector<int> > dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = a[i][j];
                dp[i][j] += dp[i][j - 1];
                dp[i][j] += dp[i - 1][j];
                dp[i][j] -= dp[i - 1][j - 1];
            }

        if (sum < k)
        {
            cout << -1 << endl;
            continue;
        }

        int lo = 0, hi = max(n, m), md;
        while (lo < hi)
        {
            md = (lo + hi) / 2;
            if (isOK(md, k, a, dp))
                hi = md;
            else
                lo = md + 1;
        }

        cout << lo << endl;
    }
}
