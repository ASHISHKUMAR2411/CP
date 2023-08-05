#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1000031;

int pr[N];
vector<int> primes;

__int128 gcd(__int128 a, __int128 b)
{
    while (a && b)
        a > b ? a %= b : b %= a;
    return a + b;
}

__int128 lcm(__int128 a, __int128 b)
{
    return a / gcd(a, b) * b;
}

vector<pair<long long, long long>> fact(long long x)
{
    vector<pair<long long, long long>> ret;
    for (int i = 0; 1ll * primes[i] * primes[i] <= x; i++)
    {
        if (x % primes[i])
            continue;
        int cnt = 0;
        while (x % primes[i] == 0)
        {
            cnt++;
            x /= primes[i];
        }
        ret.push_back(make_pair(primes[i], cnt));
    }
    if (x > 1)
        ret.push_back(make_pair(x, 1));
    return ret;
}

vector<vector<long long>> fib_matrix;
__int128 temp[2][2];

vector<vector<long long>> mult(vector<vector<long long>> a, vector<vector<long long>> b, long long mod)
{
    vector<vector<long long>> ret = a;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp[i][j] = 0;
        }
    }
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp[i][j] = (temp[i][j] + (__int128)a[i][k] * b[k][j]);
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ret[i][j] = temp[i][j] % mod;
        }
    }
    return ret;
}

vector<vector<long long>> pw(vector<vector<long long>> a, long long b, long long mod)
{
    if (b == 1)
        return a;
    if (b % 2)
        return mult(a, pw(a, b - 1, mod), mod);
    return pw(mult(a, a, mod), b / 2, mod);
}

long long get_fib(long long ps, long long mod)
{
    vector<vector<long long>> V = pw(fib_matrix, ps, mod);
    return V[0][1];
}

bool is_period(long long ps, long long mod)
{
    return get_fib(ps, mod) == 0 && get_fib(ps + 1, mod) == 1;
}

long long solver(long long x, long long mod)
{
    vector<pair<long long, long long>> factorization = fact(x);
    long long res = x;
    for (int i = 0; i < factorization.size(); i++)
    {
        while (x % factorization[i].first == 0 && is_period(x / factorization[i].first, mod))
            x /= factorization[i].first;
    }
    return x;
}

long long pisano_prime(long long val)
{

    if (val == 2)
        return 3;
    if (val == 5)
        return 20;
    if (val % 10 == 1 || val % 10 == 9)
    {
        return solver(val - 1, val);
    }
    return solver(2 * (val + 1), val);
}

__int128 solve(long long x)
{
    vector<pair<long long, long long>> factorization = fact(x);
    __int128 ans = 1;
    for (int i = 0; i < factorization.size(); i++)
    {
        __int128 here = pisano_prime(factorization[i].first);
        for (int j = 1; j < factorization[i].second; j++)
        {
            here *= factorization[i].first;
        }
        ans = lcm(ans, here);
    }
    return ans;
}

int tests;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", sttextdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    fib_matrix.resize(2);
    fib_matrix[0].push_back(1);
    fib_matrix[0].push_back(1);
    fib_matrix[1].push_back(1);
    fib_matrix[1].push_back(0);

    pr[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (pr[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                pr[j] = i;
            }
        }
    }

    for (int i = 2; i < N; i++)
    {
        if (pr[i] == i)
        {
            primes.push_back(i);
        }
    }

    cin >> tests;
    for (; tests; --tests)
    {

        long long n;
        cin >> n;

        vector<int> digits;
        __int128 res = solve(n);
        while (res)
        {
            digits.push_back(res % 10);
            res /= 10;
        }
        reverse(digits.begin(), digits.end());
        for (int i = 0; i < digits.size(); i++)
        {
            cout << digits[i];
        }
        cout << endl;
    }

    cin.get();
    cin.get();
    return 0;
}