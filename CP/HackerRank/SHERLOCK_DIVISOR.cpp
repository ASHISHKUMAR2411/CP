#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define pii  3.14159
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
    int t,n,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        count = 0;
        for (int i = 1; i * i < n; i++)
        {
            if (n % i == 0)
            {
                if(i%2==0) count++;
            }
        }
        for (int i = sqrt(n); i >= 1; i--)
        {
            if (n % i == 0)
            {
                if(i%2==0) count++;
            }
        }
        cout<<count<<endl;
    }
}