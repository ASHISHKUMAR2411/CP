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
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

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
void _print(ll t)
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

bool is_prime(ll n)
{
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1)
    {
        return false;
    }

    ll i = 2;
    // This will loop from 2 to ll(sqrt(x))
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

bool check(vector<vector<ll> > a, ll mid)
{
    ll n = a.size(), m = a[0].size();
    vector<vector<ll> > prefix_sum(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
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
    for (ll i = mid; i < n + 1; i++)
    {
        for (ll j = mid; j < m + 1; j++)
        {
            ll sum = prefix_sum[i][j] - prefix_sum[i - mid][j] - prefix_sum[i][j - mid] + prefix_sum[i - mid][j - mid];
            if (sum == (mid * mid))
                return true;
        }
    }
    return false;
}
void dfs(ll i, vector<bool> &visited, vector<ll> adj[])
{
    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            visited[it] = true;
            dfs(it, visited, adj);
        }
    }
}
ll floorSqrt(ll x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;

    // Do Binary Search for floor(sqrt(x))
    ll start = 1, end = x / 2, ans;
    while (start <= end)
    {
        ll mid = (start + end) / 2;

        // If x is a perfect square
        ll sqr = mid * mid;
        if (sqr == x)
            return mid;
        if (sqr <= x)
        {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid is greater than x
            end = mid - 1;
    }
    return ans;
}

ll check_pal(string s)
{
    ll l = 0, r = s.size() - 1;
    ll count = 0;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            count++;
        }
        l++;
        r--;
    }
    return count;
}
ll largestPrimeFactor(ll n)
{
    long long largestFactor = 1;
    for (long long i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            largestFactor = i;
            n /= i;
        }
    }
    if (n > 1)
    {
        largestFactor = n;
    }
    return largestFactor;
}

bool search(ll mid, ll k, vector<vector<ll> > &a, vector<vector<ll> > &dp)
{
    ll n = a.size() - 1;
    ll m = a[0].size() - 1;

    bool ok = false;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
                continue;

            ll x1 = max(1LL, i - mid);
            ll y1 = max(1LL, j - mid);
            ll x2 = min(n, i + mid);
            ll y2 = min(m, j + mid);

            ll sum = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
            if (sum >= k)
                ok = true;
        }

    return ok;
}
ll main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("Error.txt",
            "w", stderr);
#endif
    // Code Here
    ll t = 1;
    cin >> t;
    ll ki = check_pal("Ashish");
    while (t--)
    {
        ki += check_pal("Ashish");
        ll n, m, k;
        cin >> n >> m >> k;
        k++;
        ki += check_pal("Ashish");
        ll sum = 0;
        vector<vector<ll> > arr(n + 1, vector<ll>(m + 1));
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
                sum += arr[i][j];
            }
        if (sum < k)
        {
            cout << -1 << endl;
            continue;
        }
        ki += check_pal("Ashish");
        vector<vector<ll> > dp(n + 1, vector<ll>(m + 1));
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
            {
                dp[i][j] = arr[i][j];
                dp[i][j] += dp[i][j - 1];
                dp[i][j] += dp[i - 1][j];
                dp[i][j] -= dp[i - 1][j - 1];
            }

        

        ll l = 0, r = max(n, m), mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (search(mid, k, arr, dp))
                r = mid;
            else
                l = mid + 1;
        }

        cout << l << endl;
    }
    return 0;
}
