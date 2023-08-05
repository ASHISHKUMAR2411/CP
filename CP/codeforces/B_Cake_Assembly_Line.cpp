#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
// #define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

// priority queue to remove particular element
template <typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
public:
    bool remove(const T &value)
    {
        auto it = std::find(this->c.begin(), this->c.end(), value);

        if (it == this->c.end())
        {
            return false;
        }
        if (it == this->c.begin())
        {
            // deque the top element
            this->pop();
        }
        else
        {
            // remove element and re-heap
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
        }
        return true;
    }
};

void _print(ll t)
{
    cerr << t;
}
void _print(int t)
{
    cerr << t;
}
void _print(string t)
{
    cerr << t;
}
void _print(char t)
{
    cerr << t;
}
void _print(lld t)
{
    cerr << t;
}
void _print(double t)
{
    cerr << t;
}
void _print(ull t)
{
    cerr << t;
}

template <class T, class V>
void _print(pair<T, V> p);

template <class T>
void _print(vector<T> v);

template <class T>
void _print(set<T> v);

template <class T, class V>
void _print(map<T, V> v);

template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}

template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

ll nCr[100001];
void find_nCr(ll n, ll r, ll mod)
{
    nCr[0] = 1;
    for (ll i = 1; i <= 100000; i++)
    {
        nCr[i] = (i * nCr[i - 1]) % mod;
    }
}

// for binary exponention a^b mod c, b is large
ll b_exp(ll a, ll b, ll c)
{
    ll exp = 1;
    while (b)
    {
        if (b & 1)
        {
            exp = ((exp % c) * (a % c)) % c;
        }
        a = ((a % c) * (a % c)) % c;
        b >>= 1;
    }
    return exp;
}

// for prime
bool is_prime(int n)
{
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1)
    {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i * i <= n)
    {
        // Check if i divides x without leaving a remainder
        if (n % i == 0)
        {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}

ll binomialCoeff(ll n, ll k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ll i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// for power of 2
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("Error.txt",
            "w", stderr);
#endif
    // Code Here
    ll t;
    cin >> t;
    string s = "codeforces";
    while (t--)
    {
        ll n, w, h;
        cin >> n >> w >> h;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++){
            cin >> b[i];
        }
    }
    return 0;
}