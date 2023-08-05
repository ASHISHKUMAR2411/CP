#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
int main()
{
    fast;
    int t, n, sum = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        vi A;
        A.reserve(n);
        f(i, n) cin >> A[i];
        for (int i = 0; i < (int)(A.size() - 1); i++)
        {
            if (A[i] > A[i + 1])
            {
                sum += min(A[i], A[i + 1]);
                A.erase(A.begin() + i);
                i--;
            }
            else
            {
                sum += A[i];
                A.erase(A.begin() + i + 1);
                i--;
            }
        }
        cout << sum << endl;
    }
    return 0;
}