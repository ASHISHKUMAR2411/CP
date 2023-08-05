#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
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

bool check(vector<vector<int>> a, int mid)
{
    int n = a.size(), m = a[0].size();
    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] >= mid)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
            prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + a[i][j];
        }
    }
    for (int i = mid; i < n + 1; i++)
    {
        for (int j = mid; j < m + 1; j++)
        {
            int sum = prefix_sum[i][j] - prefix_sum[i - mid][j] - prefix_sum[i][j - mid] + prefix_sum[i - mid][j - mid];
            if (sum == (mid * mid))
                return true;
        }
    }
    return false;
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
    while (t--)
    {
        ll k;
        cin >> k;
        cout << k - 1 << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;

// typedef long long int ll;
// typedef long double ld;
// #define ff first
// #define ss second
// #define pb push_back
// #define rep(i, a, b) for (ll i = a; i < b; i++)
// #define rev(i, a, b) for (ll i = a; i >= b; i--)
// #define vpii vector<pair<int, int>>
// #define vpll vector<pair<ll, ll>>
// #define vi vector<int>
// #define vll vector<ll>
// #define all(x) (x).begin(), (x).end()
// #define mod 998244353
// #define endl "\n"
// #define pi 3.14159265358979323846
// #define SET(n) cout << fixed << setprecision(n)
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// ll bin_exp(ll a, ll n)
// {
//     ll res = 1;
//     while (n)
//     {
//         if (n % 2)
//         {
//             res = (res * a);
//             n--;
//         }
//         else
//         {
//             a = (a * a);
//             n /= 2;
//         }
//     }
//     return res;
// }

// int power(long long x, unsigned int y, int p)
// {
//     int res = 1;

//     x = x % p;

//     if (x == 0)
//         return 0;

//     while (y > 0)
//     {
//         if (y & 1)
//             res = (res * x) % p;

//         y = y >> 1;
//         x = (x * x) % p;
//     }
//     return res;
// }

// string decimalToBinary(ll n)
// {

//     string s = bitset<64>(n).to_string();

//     const auto loc1 = s.find('1');

//     if (loc1 != string::npos)
//         return s.substr(loc1);

//     return "0";
// }

// void anant_jain_01()
// {
//     ll n;
//     cin >> n;
//     ll a[n], b[n];
//     rep(i, 0, n) cin >> a[i];
//     rep(i, 0, n) cin >> b[i];

//     ll m;
//     cin >> m;
//     vi v(m);
//     map<ll, ll> mp;
//     unordered_map<ll, vll> ump;
//     rep(i, 0, m)
//     {
//         cin >> v[i];
//         mp[v[i]]++;
//     }
//     sort(all(v));

//     rep(i, 0, n)
//     {
//         if (a[i] < b[i])
//         {
//             cout << "NO" << endl;
//             return;
//         }
//         if (a[i] > b[i] && mp[b[i]] == 0)
//         {
//             cout << "NO" << endl;
//             return;
//         }
//     }

//     rep(i, 0, n)
//     {
//         if (a[i] != b[i])
//         {
//             ump[b[i]].pb(i);
//         }
//     }
//     ll maxi[n];
//     maxi[0] = 0;
//     rep(i, 1, n)
//     {
//         if (b[i] >= b[maxi[i - 1]])
//         {
//             maxi[i] = i;
//         }
//         else
//         {
//             maxi[i] = maxi[i - 1];
//         }
//     }

//     for (auto x : mp)
//     {
//         vll t = ump[x.ff];
//         if (t.empty())
//             continue;
//         int cnt = 1;
//         if (a[t[0]] < b[t[0]])
//         {
//             cout << "NO" << endl;
//             return;
//         }
//         ll l = 0, r = 0;
//         // cout<<t.size()<<endl;
//         rep(i, 1, t.size())
//         {
//             if (a[t[i]] < b[t[i]])
//             {
//                 cout << "NO" << endl;
//                 return;
//             }
//             if (b[maxi[t[i]]] > x.ff && maxi[t[i]] != maxi[t[l]])
//             {
//                 // cout<<i<<" ";
//                 cnt++;
//                 l = i;
//                 r = i;
//             }
//             else
//             {
//                 r = i;
//             }
//         }
//         // cout<<endl<<cnt<<endl;
//         if (cnt > x.ss)
//         {
//             cout << "NO" << endl;
//             return;
//         }
//     }
//     cout << "YES" << endl;
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     int t = 1, i = 1;
//     cin >> t;
//     while (t--)
//     {
//         anant_jain_01();
//     }
//     return 0;
// }
