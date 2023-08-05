#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
using namespace std;
void multiply(lli F[2][2], lli M[2][2])
{
    lli a = (((F[0][0] % mod) * (M[0][0] % mod)) % mod + ((F[0][1] % mod) * (M[1][0] % mod)) % mod)%mod;
    lli b = (((F[0][0] % mod) * (M[0][1] % mod)) % mod + ((F[0][1] % mod) * (M[1][1] % mod)) % mod)%mod;
    lli c = (((F[1][0] % mod) * (M[0][0] % mod)) % mod + ((F[1][1] % mod) * (M[1][0] % mod)) % mod)%mod;
    lli d = (((F[1][0] % mod) * (M[0][1] % mod)) % mod + ((F[1][1] % mod) * (M[1][1] % mod)) % mod)%mod;
    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}
void power(lli F[2][2], lli n)
{
    if (n == 0 || n == 1)
        return;
    lli M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}
lli fibonacci_matrix(lli n)
{
    lli F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}
// Driver code
int main()
{
    fast;
    lli res , t, n ;
    cin>>t;
    while(t--){
        cin >> n;
        res = fibonacci_matrix(n);
        cout<<res<<endl;
    }
    return 0;
}
