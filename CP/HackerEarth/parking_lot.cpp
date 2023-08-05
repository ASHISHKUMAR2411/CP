#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
using namespace std;
lli power(lli a, lli n)
{
    lli res = 1;
    while (n)
    {
        if (n % 2)
            res = res * a;
        n = n >> 1;
        a = a * a;
    }
    return res;
}
int main(){
    fast;
    int n;
    cin>>n;
    cout<<power(4,n-3)*1LL*(24+(n-3)*9)<<endl;
    return 0;
}