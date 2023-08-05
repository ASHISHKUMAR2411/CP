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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m+1,0);
        ll l = 1, r = m;
        priority_queue<ll> pq1;
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] == -1){
                if(pq2.empty()){
                    b[m] = 1;
                    pq2.push(m);
                }
                else{
                    int ind = pq2.top();
                    if(ind >= 0){
                        b[ind ] = 1;
                        pq2.push(ind);
                    }
                }
            }
            else if(a[i] == -2){
                if (pq1.empty())
                {
                    b[1] = 1;
                    pq1.push(1);
                }
                else
                {
                    int ind = pq1.top();
                    if (ind + 1 <= m)
                    {
                        b[ind + 1] = 1;
                        pq1.push(ind + 1);
                    }
                }
            }
            else{
                if(b[a[i]] == 0){
                    b[a[i]] = 1;
                    pq1.push(a[i]);
                    pq2.push(a[i]);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++){
            if(b[i] == 1)count++; 
        }
        cout << count << endl;
    }
    return 0;
}