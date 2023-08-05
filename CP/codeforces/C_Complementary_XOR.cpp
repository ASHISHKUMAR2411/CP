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

int main()
{
    // fast;
#ifndef ONLINE_JUDGE
    freopen("Error.txt",
            "w", stderr);
#endif
    // Code Here
    ll t;
    cin >> t;
    while(t--){
        // temp:
        ll n;
        cin >> n;
        string s1 = "", s2 = "";
        cin >> s1 >> s2;
        int same = 0;
        if(n == 1){
            if(s2 == "1"){
                cout << "NO\n";
                continue;
            }
        }
        for (int i = 0; i < n; i++){
            if(s1[i] == s2[i]){
                same++;
            }
        }
        if (same > 0 && same < n)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<pair<int, int>> vp = {};
        int count = 0;
        for (int i = 0; i < n; i++){
            if(s1[i] == '1'){
                count++;
                int first = i, second = 0;
                while(i < n and s1[i] == '1'){
                    i++;
                }
                second = i - 1;
                i--;
                vp.push_back({first, second});
            }
        }
        debug(vp);
        // cout << count << endl;
        int m = vp.size();
        if(same == n and m%2 == 1){
            count += 2;
            vp.push_back({0, n - 1});
            vp.push_back({0, 0});
            if(n-1 >= 1)
                vp.push_back({1, n - 1}), count++;

            cout << count << endl;
            for (int i = 0; i < vp.size(); i++)
            {
                cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
            }
        }
        else if(same == 0 and m%2 == 0){
            if (n - 1 >= 0)
            {
                vp.push_back({0, n - 1});
                count++;
            }
            count++;
            vp.push_back({0, 0});
            if (n - 1 > 0)
            {
                count++;
                vp.push_back({1, n - 1});
            }
            cout << count << endl;
            for (int i = 0; i < vp.size(); i++)
            {
                cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
            }
        }
        else{
            cout << count << endl;
            for (int i = 0; i < vp.size(); i++)
            {
                cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
            }
        }
    }
    return 0;
}