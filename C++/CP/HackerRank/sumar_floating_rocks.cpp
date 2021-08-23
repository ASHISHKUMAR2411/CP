#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define pii 3.14159
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
int main()
{
    fast;
    int t;
    lli x1, x2, y1, y2, check, count;
    long double m;
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        count = 0;
        lli b = abs(x1 - x2);
        lli c = abs(y2-y1);
        while(__gcd(b,c) != 1)
        {
            b = b/__gcd(b,c);
            c = c/__gcd(b,c);
        }
        if (x1 == x2)
        {
            count = abs(y1 - y2) - 1;
        }
        else 
        {
            count = (abs(x2-x1)/b) - 1;
        }
        if (count < 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << count << endl;
        }
    }
}