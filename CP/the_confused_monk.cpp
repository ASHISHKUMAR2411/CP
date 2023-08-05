#include<bits/stdc++.h>
using namespace std;
int GCD(int A,int B)
{
    if(B==0) return A;
    else return GCD(B,A%B);
}
long long int modularExponentiation(long long int a , long int n , long int p)
{
    long int res = 1;
    while (n)
    {
        if(n%2) res = (res*a)%p , n--;
        else a = (a*a)%p , n = n/2;
    }
    return res;
}
int main()
{
    
    int n ,gcd = 0;
    int  A[n];
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>A[i];
    }
    gcd = A[0];
    for(int i =1;i<n;i++)
    {
        gcd = GCD(gcd,A[i]);
    }
    long long int f_x = 1, g_x = (long long int)gcd;
    for(int i =0;i<n;i++)
    {
        f_x = f_x * A[i];
    }
    cout << modularExponentiation(f_x,g_x,(long long int)(1000000007));
}