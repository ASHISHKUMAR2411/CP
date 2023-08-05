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

bool check(ll a[], ll n)
{
    ll l = 0, r = n - 1;
    while (l >= r)
    {
        if (a[l] == a[r])
        {
            l++;
            r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool solve(ll n, ll &m)
{
    if (n == m)
        return true;
    if (m > n)
        return false;
    if (n % 3 != 0)
        return false;
    ll n1 = n / 3, n2 = 2 * (n / 3);
    return solve(n1, m) || solve(n2, m);
}
void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

// Function that returns nth Fibonacci number
int fib(int n)
{
    int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);

    return F[0][0];
}

// Optimized version of power() in method 4
void power(int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
ll findCnt(ll arr[], ll n, ll k)
{
    // Variable to store final answer
    ll ans = 0;

    // Loop to find prefix-sum
    for (ll i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
        if (arr[i] > k or arr[i] < -1 * k)
            ans++;
    }

    if (arr[0] > k || arr[0] < -1 * k)
        ans++;

    // Sorting prefix-sum array
    sort(arr, arr + n);

    // Loop to find upper_bound
    // for each element
    for (ll i = 0; i < n; i++)
        ans += n - (upper_bound(arr, arr + n, arr[i] + k) - arr);

    // Returning final answer
    return ans;
}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("Error.txt",
            "w", stderr);
#endif
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n,0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int mini = -1;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                mini = i;
            }
            if (a[i] == n)
            {
                maxi = i;
            }
        }
        int t1 = max(n - 1 - mini, maxi - 1);
        int t2 = max(mini, n - maxi - 1);
        int res = max(t1, t2);
        cout << res << endl;
        // cout  << n - maxi<< endl;
    }
    return 0;
}
