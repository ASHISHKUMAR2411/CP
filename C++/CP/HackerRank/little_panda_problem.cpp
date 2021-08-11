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
bool isPrime(lli n)
{
    if(n==1)
    {
        return false;
    }
    for(lli i =2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}
lli modularExponent(lli a, lli n,lli p)
{
    lli res = 1;
    while (n)
    {
        if(n%2)
            res = (res%p * a%p)%p,n--;
        else a = (a%p * a%p)%p , n/=2;
    }
    return res ;
}
lli d , x , y ;
void extendedEuclid(lli A, lli B)
{
    if(B==0) d = A,x = 1,y =0;
    else {
        extendedEuclid(B,A%B);
        lli temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
lli modInverse(lli A,lli M)
{
    if(isPrime(M)) return modularExponent(A,M-2,M);
    extendedEuclid(A,M);
    return ((x%M + M)%M);
}
int main()
{
    fast;
    lli t,a,b,x,res;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x;
        if(b>=0)
        {
            res = modularExponent(a,b,x);
        }
        else
        {
            b *= -1;
            res = modularExponent(modInverse(a,x),b,x);
        }
        cout<<res<<endl;
    }
}