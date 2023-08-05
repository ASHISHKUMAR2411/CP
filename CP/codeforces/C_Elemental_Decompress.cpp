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
        ll n;
        cin >> n;
        ll a[n];
        ll repeat = 0;
        vector<ll> b(n + 1, 0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            b[a[i]]++;
            if(b[a[i]] > 1){
                repeat = a[i];
            }
        }
        ll count = 0;
        for (int i = 0; i < n + 1; i++){
            if(b[i]){
                count++;
            }
        }
        if (repeat == 1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(count == n){
            for (int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else if(repeat == n){
            ll cou = 1;
            for (int i = 0; i < n; i++){
                if(a[i] == repeat and cou == 2){
                    cout << 1 << " ";
                }
                else{
                    cout << a[i] << " ";
                    if(a[i] == n){
                        cou++;
                    }
                }
            }
            cout << endl;
            cou = 1;
            for (int i = 0; i < n; i++)
            {
                if (cou == 2 and a[i] == repeat)
                {
                    cout << a[i] << " ";
                }
                else
                {
                    cout << a[i] - 1 << " ";
                    if (a[i] == n)
                    {
                        cou++;
                    }
                }
            }
            cout << endl;
        }
        else{
            ll cou = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == repeat and cou == 2)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << a[i] << " ";
                    if (a[i] == n)
                    {
                        cou++;
                    }
                }
            }
            cout << endl;
            cou = 1;
            for (int i = 0; i < n; i++)
            {
                if (cou == 2 and a[i] == repeat)
                {
                    cout << a[i] << " ";
                }
                else
                {
                    if (a[i] == n)
                    {
                        cout << a[i] << " ";
                    }
                    else{
                        cout << a[i] - 1 << " ";
                    }
                }
            }
            cout << endl;
        }
        // cin >> n;
        // vector<int> v(n);
        // vector<int> a(n + 1, 0);
        // for (int &i : v)
        // {
        //     cin >> i;
        //     a[i]++;
        // }
        // bool ans = true;
        // vector<int> dp(n + 1);
        // stack<int> s;
        // vector<int> a1[2];
        // for (int i = 1; i <= n; i++)
        // {
        //     if (a[i] == 0)
        //         s.push(i);
        //     else if (a[i] == 1)
        //         dp[i] = i;
        //     else if (a[i] == 2 && !s.empty())
        //     {
        //         dp[i] = s.top();
        //         s.pop();
        //     }
        //     else
        //     {
        //         ans = false;
        //         break;
        //     }
        // }
        // if (ans)
        // {
        //     cout << "YES" << endl;
        //     for (int &i : v)
        //     {
        //         if (a[i] & 1)
        //             cout << dp[i] << " ";
        //         else
        //             cout << i << " ";
        //         a[i]--;
        //     }
        //     cout << endl;
        //     for (int &i : v)
        //     {
        //         if ((a[i] - 1) & 1)
        //             cout << dp[i] << " ";
        //         else
        //             cout << i << " ";
        //         a[i]--;
        //     }
        //     cout << endl;
        // }
        // else
        //     cout << "NO" << endl;
    }
    return 0;
}
