#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int total = 0, n = 0, sum = 0, j = 0;
        cin >> total >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n, greater<int>());
        sum = a[0], j = 1;
        for (int i = 1; i < n; i++)
        {
            if (sum >= total)
            {
                break;
            }
            else
            {
                sum += a[i];
                j++;
            }
        }
        cout << "Scenario #" << k + 1 << ":\n";
        if (sum >= total)
        {
            cout << j << "\n\n";
        }
        else{
            cout << "impossible\n\n";
        }
    }
    return 0;
}