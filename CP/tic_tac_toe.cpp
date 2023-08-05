#include<bits/stdc++.h>
using namespace std;
bool prime(long int N)
{
    if(N==1) return false;
    for(long int i =2;i*i<=N;i++)
        if(N%i==0) return false;
    return true;
}
long int modularExponentiation(long int a , long int n , long int p)
{
    long int res = 1;
    while (n)
    {
        if(n%2) res = (res*a)%p , n--;
        else a = (a*a)%p , n = n/2;
    }
    return res;
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
int main()
{
    long long int t,n;
    int mo = 1e9 + 7;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        long long int min = (((((n%mo)*((n/2)%mo))%mo)*((n/2)%mo))%mo);
        n= n-1;
        long long int max = (((((((n%mo)*((n+1)%mo))%mo)*((2*n+1)%mo))%mo)*(modInverse(6,mo)))%mo);
        cout<<min<<" "<<max<<"\n";
    }
}