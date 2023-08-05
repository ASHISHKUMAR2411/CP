#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int
#define mod 1000000007
#define endl '\n'
using namespace std;
// int gcd(int a, int b, int &x, int &y)
// {
//     if (b == 0)
//     {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int x1, y1;
//     int d = gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return d;
// }

// bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
// {
//     g = gcd(abs(a), abs(b), x0, y0);
//     if (c % g)
//     {
//         return false;
//     }

//     x0 *= c / g;
//     y0 *= c / g;
//     if (a < 0)
//         x0 = -x0;
//     if (b < 0)
//         y0 = -y0;
//     return true;
// }
// void shift_solution(int &x, int &y, int a, int b, int cnt)
// {
//     x += cnt * b;
//     y -= cnt * a;
// }

// int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy)
// {
//     int x, y, g;
//     if (!find_any_solution(a, b, c, x, y, g))
//         return 0;
//     a /= g;
//     b /= g;

//     int sign_a = a > 0 ? +1 : -1;
//     int sign_b = b > 0 ? +1 : -1;

//     shift_solution(x, y, a, b, (minx - x) / b);
//     if (x < minx)
//         shift_solution(x, y, a, b, sign_b);
//     if (x > maxx)
//         return 0;
//     int lx1 = x;

//     shift_solution(x, y, a, b, (maxx - x) / b);
//     if (x > maxx)
//         shift_solution(x, y, a, b, -sign_b);
//     int rx1 = x;

//     shift_solution(x, y, a, b, -(miny - y) / a);
//     if (y < miny)
//         shift_solution(x, y, a, b, -sign_a);
//     if (y > maxy)
//         return 0;
//     int lx2 = x;

//     shift_solution(x, y, a, b, -(maxy - y) / a);
//     if (y > maxy)
//         shift_solution(x, y, a, b, sign_a);
//     int rx2 = x;

//     if (lx2 > rx2)
//         swap(lx2, rx2);
//     int lx = max(lx1, lx2);
//     int rx = min(rx1, rx2);

//     if (lx > rx)
//         return 0;
//     return (rx - lx) / abs(b) + 1;
// }
// int main()
// {
//     fast;
//     int  a, b, c,x1,y1,x2,y2;
//     cin >> a >> b >> c>>x1>>x2>>y1>>y2;
//     cout << find_all_solutions(a/__gcd(a,b), b/__gcd(a,b), c/__gcd(a,b), x1, x2, y1, y2) << endl;
// }

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    c = -c;
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (c < 0)
    {
        c = -c;
        a = -a;
        b = -b;
    }
    if (a < 0)
    {
        a = -a;
        l1 = -l1;
        r1 = -r1;
        swap(l1, r1);
    }
    if (b < 0)
    {
        b = -b;
        r2 = -r2;
        l2 = -l2;
        swap(r2, l2);
    }
    if (a == 0 && b == 0 && c == 0)
    {
        cout << (r1 - l1 + 1) * (r2 - l2 + 1) << endl;
        return 0;
    }
    else if (a == 0 && b == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (b == 0)
    {
        if (c % b == 0 && (-c) / b <= r2 && (-c) / b >= l2)
            cout << r1 - l1 + 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    else if (a == 0)
    {
        if (c % a == 0 && (-c) / a <= r1 && (-c) / a >= l1)
            cout << r2 - l2 + 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    ll d = gcd(a, b);
    if (c % d != 0)
        puts("0");
    else
    {
        ll x, y;
        //        c=-c;
        a /= d;
        b /= d;
        c /= d;
        exgcd(a, b, x, y);
        x = x * c;
        y = y * c;
        //        cout<<a<<"--"<<b<<"=="<<c<<"--"<<d<<"==="<<x<<"--"<<y<<endl;
        double rr1, ll1, rr2, ll2;
        rr1 = double(r1);
        ll1 = double(l1);
        rr2 = double(r2);
        ll2 = double(l2);
        ll upx = floor((rr1 - x) / b), downx = ceil((ll1 - x) / b);
        ll upy = floor((y - ll2) / a), downy = ceil((y - rr2) / a);
        ll ans = min(upx, upy) - max(downx, downy) + 1;
        cout << (ans < 0 ? 0 : ans) << endl;
    }
    return 0;
}