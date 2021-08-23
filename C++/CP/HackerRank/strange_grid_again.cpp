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
    lli r,c;
    cin>>r>>c;
    r = r-1;
    c = c-1;
    if(r%2) cout<<(((r-1)*5 + 1) + c*2)<<endl;
    else cout<<(((r*5)+2*c))<<endl;
}