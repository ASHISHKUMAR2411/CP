#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define pie 3.1415926535897932
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
// int MAX = 1e5;
// int ar[(int)1e5+1];
// void sumDigit()
// {
//     int dummy = 0;
//     for(int i = 1 ;i<=MAX;i++)
//     {
//         dummy = i;
//         while(dummy>0)
//         {
//             ar[i] += dummy%10;
//             dummy /= 10;
//         }
//     }
// }
int main()
{
    fast;
    // sumDigit();
    int n;
    cin >> n;
    vi factors;
    if (n == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 1; i < n * n; i++)
        {
            if (n % i == 0)
                factors.push_back(i);
        }
        for (int i = sqrt(n); i > 1; i--)
        {
            if (n % i == 0)
            {
                factors.push_back(n / i);
            }
        }
        sort(factors.begin(), factors.end());
        int index = 0, max = 0, sum = 0, dummy = 0;
        for (int i = 0; i < (int)(factors.size()); i++)
        {
            dummy = factors[i];
            sum = 0;
            while (dummy > 0)
            {
                sum += dummy % 10;
                dummy /= 10;
            }
            if (sum > max)
            {
                index = i;
                max = sum;
            }
        }
        cout << factors[index] << endl;
    }
}