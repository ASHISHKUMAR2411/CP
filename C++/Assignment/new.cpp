#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0, f = -1, flag = 0, l = INT_MAX, min;
        int i = 0, j = 1;
        while (j < n)
        {
            if (a[j] > a[i])
            {
                while (j < n and a[j] > a[j - 1])
                    j++;
                ans += a[i] * (j - i);
                i = j - 1;
            }
            else if (a[j] < a[i])
            {
                while (j < n and a[j] < a[j - 1])
                    j++;
                ans += a[j - 1] * (j - i);
                i = j - 1;
            }
        }
        cout << ans << "\n";
    }
}
