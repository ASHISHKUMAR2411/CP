#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
bool isPrime(int n)
{
    if(n==1)
    {
        return false;
    }
    for(int i =2;i*i<=n;i++)
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
long int d , x , y ;
void extendedEuclid(long int A, long int B)
{
    if(B==0) d = A,x = 1,y =0;
    else {
        extendedEuclid(B,A%B);
        long int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
long int modInverse(long int A,long int M)
{
    if(prime(M)) return modularExponentiation(A,M-2,M);
    extendedEuclid(A,M);
    return ((x%M + M)%M);
}