#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define f(i,m) for(int i = 0 ; i<m;i++)
#define fi(i,m) for(int i = 1 ; i<=m;i++)
#define fir(i,n,m) for(int i = n ; i<=m;i++)
using namespace std;

// always use "\n" than endl ,

// for sieve of eratosthenes where we have to find the kth prime or check for primes then this is used 

#define MAX 1000000 
int isPrime[MAX+1];
/* or we can use bool isPrime[max+1] */
void sieve()
{
    int maxN = MAX;
    for(int i = 1;i<=maxN;i++)
    isPrime[i]=1;
    isPrime[0]=isPrime[1]=0;
    for(int i =2 ;i*i<=maxN;i++)
    {
        if(isPrime[i])
        {
            for(int j = i*i ;j<=maxN;j+=i)
            {
                isPrime[j] = 0;
            }
        }
    }
}
// sieve for factorization optimized one (better)
int ar[(int)1e6+1];
void sieveFactorization()
{
    int maxN = 1e6;
    for(int i = 1 ;i<=maxN;i++) ar[i] = -1;
    for(int i = 2; i*i<=maxN;i++){
        if(ar[i]==-1)
        {
            for(int j = i*i;j<=maxN;j+=i){
                if(ar[j]== -1) ar[j] = i;
            }
        }
    }
}

// original sieve for factorization
int ar[(int)1e6+1];
void sieveFactorisation()
{
    int maxN = 1e6;
    for(int i = 1 ;i<=maxN;i++) ar[i] = -1;
    for(int i = 2; i<=maxN;i++){
        if(ar[i]==-1)
        {
            for(int j = i;j<=maxN;j+=i){
                if(a[j]== -1) a[j] = i;
            }
        }
    }
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
lli power(lli a ,lli n)
{
    lli res = 1;
    while (n) {
        if(n%2) res = res * a;
        n =n>>1;
        a = a*a;
    }
    return res;
}

// for finding whether the number is prime or not 
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
// prime factors
void primeFac(int N)
{
    for(int i =2;i*i<=N;i++)
    {
        int cnt = 0;
        while(N%i ==0)
        {
            cnt++;
            N/=i;
        }
        if(cnt>0) factors.push_back((i*cnt));
    }
    if(N>1) factors.push_back(N);
}
// gcd
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
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
// driver program 
int main()
{
    fast;
    /* code  */
    


    return 0;
}
