// !Error in code .
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define pie  3.1415926535897932
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
bool Compare(long double a,long double b) {
    std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}
int main()
{
    fast;
    lli min,max,a,b;
    cin>>min>>max;
    long double m = 1.000000000000;
    for(lli i = min;i<=max;i++)
    {
        long double x = (long double)i*3.0000000;
        long double y = (long double)i*4.0000000;
        if(abs((x/(long double)i)-pie) < m)
        {
            m = (double)abs((x/(long double)i)-pie);
            a =(lli) x;
            b= (lli)i;
        }
        else if(abs((y/(long double)i)-pie)<m)
        {
            m = (double)abs((y/(long double)i)-pie);
            a = (lli)y;
            b = (lli)i;
        }
    }
    cout<<(int)a<<"/"<<(int)b<<endl;
}