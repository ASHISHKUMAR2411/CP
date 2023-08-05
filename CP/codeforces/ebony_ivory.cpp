#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define endl '\n'
using namespace std;
int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_solution(int a, int b, int c)
{
    int x, y, g;
    g = gcd(abs(a), abs(b), x, y);
    if (c % g)
    {
        return false;
    }
    x = x * c / g;
    y = y * c / g;
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
}
int main()
{
    fast;
    int  a, b, c;
    cin >> a >> b >> c;
    if (find_solution(a/__gcd(a,b), b/__gcd(a,b), c/__gcd(a,b)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}