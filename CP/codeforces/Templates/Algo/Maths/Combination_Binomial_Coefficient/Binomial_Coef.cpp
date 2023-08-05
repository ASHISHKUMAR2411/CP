#include <bits/stdc++.h>
using namespace std;

// In Binomial Coefficient - nCr = n! / (n-r)! r!
// To solve such questions we have three mathods
// 1. Factorial Method - where n <= 10^6
// In this Method we store the values of all the factorials pre-computation in a look up array taking modulo some prime p,
// Code for the above solution also takes O(logn) when we use binary exponentiation otherwise if store values of binary exponentiation also then it takes O(1) solution

long long fact[1000100];
long long inv[1000100];
long long mod = 1e9 + 7;

// for finding a^b % p
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void find_fact()
{
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

void find_inv()
{
    for (int i = 0; i <= 1000000; i++)
    {
        inv[i] = binpow(fact[i], mod - 2, mod);
    }
}

long long binomialCoef(long long n, long long k)
{
    return (((fact[n] * inv[n - k]) % mod) * inv[k]) % mod;
}

// 2. Pascal Method -
// n <= 4000, using the concept if nCr = (n - 1)Cr + (n-1)C(r-1)
// Here mod can be any prime, or any composite values because we don't have t calculate the inverse in this method.

int bino[4010][4010];

void fill_bino()
{
    bino[0][0] = 1;
    for (int i = 1; i <= 4000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i - 1 >= 0)
            {
                bino[i][j] = (bino[i][j] + bino[i - 1][j]) % mod;
            }
            if (i - 1 >= 0 and j - 1 >= 0)
            {
                bino[i][j] += (bino[i][j] + bino[i - 1][j - 1]) % mod;
            }
        }
    }
}

long long binomial_coeff(long long n, long long r)
{
    return bino[n][r];
}

// 3. Multiplication Method - O(r log p)
// In this method n <= 10^18 and r <= 10^6, and we need to find the nCr = n!/(n-r)!r!, where it is represented by - product of (n - i)/ (i + 1) where i is from 0 to r, and the product of this would be the answer. where modulo p is prime, a special case is when r is large, then n-r will work, till n-r we have to product.

void solve_mul(long long n, long long r)
{
    int sum = 1;
    if (r < (n - r))
    {
        for (int i = 0; i <= r; i++)
        {
            sum = (sum * (n - i)) % mod * inv[i + 1]
        }
    }
}

// catalan number
// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// A Binomial coefficient based function to
// find nth catalan number in O(n) time
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2 * n, n);

    // return 2nCn/(n+1)
    return c / (n + 1);
}

int main()
{
    find_fact();
    find_inv();
    fill_bino();
}