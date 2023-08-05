#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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

// prime factors only
vector<ll> findFactors(ll val){
    vector<ll> primeFactors;
    for (int i = 2; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            primeFactors.push_back(i);
            while (val % i == 0)
                val /= i;
        }
    }
    if (val > 1)
        primeFactors.push_back(val);
    return primeFactors;
}

ll RemoveFactors(ll &m, ll a1, ll a2){
    vector<ll> factors = findFactors(a1 / a2);
    ll totalFactors = m / a2;
    ll res = totalFactors;
    ll size = factors.size();
    for (int i = 1; i < (1ll << size); i++){
        int curr = 1;
        for (int j = 0; j < size; j++){
            if(i >> j & 1){
                curr *= factors[j];
            }
        }
        int lastBit = __builtin_popcount(i) & 1;
        if(lastBit){
            res -= totalFactors/curr;
        }
        else{
            res += totalFactors/curr;
        }
    }
    return res;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("Error.txt",
            "w", stderr);
#endif
    // Code Here
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll arr[n];
        for (ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        bool flag = true;
        for (ll i = 1; i < n; i++){
            if(arr[i-1] % arr[i]){
                flag = false;
            }
        }
        if(!flag){
            cout << 0 << endl;
            continue;
        }
        ll count = 1;
        for (ll i = 1; i < n; i++){
            if(arr[i-1] == arr[i]){
                count *= (m / arr[i]);
                count %= MOD1;
            }
            else{
                count *= RemoveFactors(m, arr[i - 1], arr[i]);
                count %= MOD1;
            }
        }
        cout << count << endl;
    }
    return 0;
}