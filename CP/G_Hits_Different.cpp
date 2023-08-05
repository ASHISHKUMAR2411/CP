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

typedef long long int ll;
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
int main(){
    fast;
#ifndef ONLINE_JUDGE
    freopen("Error.txt",
            "w", stderr);
#endif
    vector<ll> dp(1000001, 0);
    dp[1] = 1, dp[2] = 5, dp[3] = 10;
    ll row = 3;
    ll column = 0;
    for (int i = 4; i <= 1000000; i++)
    {
        column++;
        // int R = row - 1;
        // ll prevR = row - 1; 
        ll f = (row - 1) *1ll* (row) / 2 + 1;
        ll d = i - f;
        if (d == 0)
        {
            ll p = (row - 2) *1ll* (row - 1) / 2 + 1;
            dp[i] = i *1ll* i + dp[p];
        }
        else if (d == row - 1)
        {
            dp[i] = i *1ll* i + dp[f - 1];
        }
        else
        {
            ll p = ((row - 2) *1ll* (row - 1)) / 2 + 1;
            ll pf = ((row - 3) *1ll* (row - 2)) / 2 + 1;
            dp[i] = i *1ll* i + dp[p + d] + dp[p + d - 1] - dp[pf + d - 1];
        }
        if (column == row)
        {
            row++;
            column = 0;
        }
    }

    ll t = 1;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << dp[n] << endl;
    }
}