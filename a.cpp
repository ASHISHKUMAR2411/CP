#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n"

using namespace std;

void solve()
{
    long long x, y, z;
    cin >> x >> y >> z;
    y = y + z;
    long long int val = 0;
    long long total = (x * (x + 1)) / 2;

    if ((total % y) == 0)
    {
        cout << "POSSIBLE" << endl;
        y = total / y;
        z = z * y;
        total = x;
        vector<long long int> arr(total + 3);
        for (int i = 1; i <= total; i++)
        {
            if (i >= 1)
            {
                arr[i - 1] = i;
            }
        }

        for (long long int i = total - 1; i >= 0; i--)
        {
            if (arr[i] <= z)

                z = z - arr[i],
                arr[i] = 0;
        }

        for (auto it : arr)
        {
            if (it != 0)
                ++val;
        }

        cout << val << endl;
        for (int i = 0; i < total; ++i)
        {
            if (arr[i] > 0 || arr[i] < 0)
            {

                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE";
        cout << endl;
    }
}

int main()
{
    fast;
    long long int k;
    cin >> k;
    long long int temp = k;
    while (k--)
    {
        cout << "Case #" << temp - k << ": ";
        solve();
    }
    return 0;
}