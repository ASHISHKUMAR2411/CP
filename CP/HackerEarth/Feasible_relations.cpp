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
void _print(pair<T, V> p){
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}

template <class T>
void _print(vector<T> v){
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v){
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v){
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v){
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

bool is_prime(int n){
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

ll binomialCoeff(ll n, ll k){
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

bool check(vector<vector<int>> a, int mid){
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


bool dfs(int i, int col, vector<int> &color, vector<vector<int>> &graph){
        color[i] = col;
        col = 1 - col;
        for(auto it : graph[i]){
            if(color[it] == -1){
                if(!dfs(it, col, color, graph)){
                    return false;
                }
            }
            else{
                if(color[it] == color[i]){
                    return false;
                }
            }
        }
        return true;
        
    }
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for(int i =0; i < n; i++){
        if(color[i] == -1){
            if(!dfs(i,0,color,graph)){
                return false;
            }
        }
    }
    return true;
}
class DSU{
    public:
        vector<ll> parent, size, rank;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1);
            rank.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findParent(int n){
            if(n == parent[n]){
                return parent[n];
            }
            return parent[n] = findParent(parent[n]);
        }
        void unionBySize(int u, int v){
            int pv = findParent(v);
            int pu = findParent(u);
            if(pu == pv) return;
            if(size[pv] > size[pu]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv]; 
            }
        }
        void unionByRank(int u, int v){
            int pv = findParent(v);
            int pu = findParent(u);
            if(pu == pv) return;
            if(rank[pv] > rank[pu]){
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            }
            else{
                parent[pv] = pu;
                rank[pu] = rank[pv] + 1; 
            }
        }
};
bool cmp(const pair<string, pair<int, int>> p1, const pair<string, pair<int, int>> p2){
    return p1.first.size() < p2.first.size();
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
    while(t--){
        ll n, k;
        cin >> n >> k;
        DSU ob(n);
        vector<pair<string, pair<int,int>>> vp;
        for(int i = 0; i < k; i++){
            int x1, x2;
            string s;
            cin >> x1 >> s >> x2;
            vp.push_back({s, {x1, x2}});
        }
        for(auto it : vp){
            string x = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(x == "="){
                ob.unionBySize(u, v);
            }
        }
        bool flag = true;
        for(auto it : vp){
            string x = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(x == "!="){
                if(ob.findParent(u) == ob.findParent(v)){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}
