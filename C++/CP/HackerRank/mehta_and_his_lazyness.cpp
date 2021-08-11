#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
lli MAX = 1e6;
bool ar[(int)1e6+1];
void perfectSquare()
{
    lli j;
    for (lli i = 2; i <= MAX; i++)
    {
        if (i % 2)
            ar[i] = 0;
        else
        {
            j = sqrt(i);
            if (j * j == i)
                ar[i] = 1;
        }
    }
}
int main()
{
    fast;
    perfectSquare();
    int n, t;
    cin >> t;
    int p , q;
    while (t--)
    {
        cin >> n;
        vi factors;
        p = 0, q = 1;
        for (int i = 2; i * i <= n; i++)
        {
            int cnt = 0;
            int a = n;
            while (n % i == 0)
            {
                cnt++;
                a /= i;
                q++;
                factors.push_back((i * cnt));
            }
        }
        if (n > 1) factors.push_back(n);
        sort(factors.begin(),factors.end());
        for(int i = 0;i<(int)(factors.size());i++)
        {
            if(ar[factors[i]]) p++;
        }
        if(p==0) cout<<p<<endl;
        else
        cout<<p<<"/"<<q<<endl;
    }
}
