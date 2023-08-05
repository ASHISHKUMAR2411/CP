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
void dfs(int i, vector<bool> &visited, vector<int> adj[])
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
        ll n, m;
        cin >> n >> m;
        ll l1 = 0, r1 = 0, l = 0, r = 0;
        ll maxii = INT_MAX;
        ll digit = 0;
        if (m - n < 11)
        {
            l = n, r = m;
            if (l && r)
            {
                for (int i = l; i <= r; i++)
                {
                    vector<int> digits;
                    ll k = i;
                    while (k)
                    {
                        digits.push_back(k % 10);
                        k /= 10;
                    }
                    sort(digits.begin(), digits.end());
                    ll mini = *min_element(digits.begin(), digits.end());
                    ll maxi = *max_element(digits.begin(), digits.end());
                    ll diff = maxi - mini;
                    if (maxii > diff)
                    {
                        digit = i;
                    }
                    maxii = min(maxii, diff);
                    if (maxii == 0)
                    {
                        break;
                    }
                }
            }
            cout << digit << endl;
        }
        else
        {
            if(m < 1e9){
                l1 = n, r1 = n + 11;
                l = m - 11, r = m;
            }
            else{
                l1 = n, r1 = n + 11;
                l = m - 11, r = m;
            }
            else
        }
        
        if (l1 && r1)
        {
            for (int i = l1; i <= r1; i++)
            {
                vector<int> digits;
                ll k = i;
                while (k)
                {
                    digits.push_back(k % 10);
                    k /= 10;
                }
                sort(digits.begin(), digits.end());
                ll mini = *min_element(digits.begin(), digits.end());
                ll maxi = *max_element(digits.begin(), digits.end());
                ll diff = maxi - mini;
                if (maxii > diff)
                {
                    digit = i;
                }
                maxii = min(maxii, diff);
                if (maxii == 0)
                {
                    break;
                }
            }
        }
        if (maxii == 0)
        {
            cout << digit << endl;
            continue;
        }
        
    }

    return 0;
}

// image is too blur
//     take this this is c

// #include <bits/stdc++.h>

// #define int long long
//     using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n), b(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i] >> b[i];
//     }
//     int res = 1;
//     int gc = 0, l = 1;
//     for (int i = 0; i < n; ++i)
//     {
//         gc = gcd(gc, a[i] * b[i]);
//         int d = b[i] / gcd(l, b[i]);
//         if (d > gc / l)
//         {
//             res++;
//             gc = a[i] * b[i];
//             l = b[i];
//         }
//         else
//         {
//             l = d;
//             if (gc % l != 0)
//             {
//                 res++;
//                 gc = a[i] b[i];
//                 l = b[i];
//             }
//         }
//     }
//     cout << res << '\n';
// }

// signed main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
// }