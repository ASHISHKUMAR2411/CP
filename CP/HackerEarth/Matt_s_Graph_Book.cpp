// Approach 2
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int timer;
void dfs(int node, int parent, vector<int> adj[], vector<int> &time, vector<int> &low, vector<bool> &vis, set<int> &bridges){
    time[node] = low[node] = timer++;
    vis[node] = true;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(vis[it]){
            low[node] = min(low[node], time[it]);
        }
        else{
            dfs(it, node, adj, time, low, vis, bridges);
            if (low[it] > time[node])
                bridges.insert(node);
            low[node] = min(low[node], low[it]);
        }
    }
}
int main(){
    fast;
    int n, k;
    cin >> n >> k;
    timer = 0;
    vector<int> time(n, 0), low(n, 1e9);
    vector<bool> vis(n, false);
    vector<int> adj[n];
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x;
    cin >> x;
    set<int> bridges;
    dfs(0, -1, adj, time, low, vis, bridges);
    bool flag = false;
    for(auto it : bridges){
        cout << it << endl;
        if(it == x){
            flag = true;
            break;
        }
    }
    if(flag) cout << "Not Connected\n";
    else cout << "Connected\n";

}



// #include <bits/stdc++.h>

// using namespace std;

// #define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define endl "\n"
// #define pb push_back
// #define ppb pop_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define PI 3.141592653589793238462
// #define set_bits __builtin_popcountll
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// // typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

// #ifndef ONLINE_JUDGE
// #define debug(x)       \
//     cerr << #x << " "; \
//     _print(x);         \
//     cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(ll t)
// {
//     cerr << t;
// }
// void _print(int t)
// {
//     cerr << t;
// }
// void _print(string t)
// {
//     cerr << t;
// }
// void _print(char t)
// {
//     cerr << t;
// }
// void _print(lld t)
// {
//     cerr << t;
// }
// void _print(double t)
// {
//     cerr << t;
// }
// void _print(ull t)
// {
//     cerr << t;
// }

// template <class T, class V>
// void _print(pair<T, V> p);

// template <class T>
// void _print(vector<T> v);

// template <class T>
// void _print(set<T> v);

// template <class T, class V>
// void _print(map<T, V> v);

// template <class T>
// void _print(multiset<T> v);

// template <class T, class V>
// void _print(pair<T, V> p){
//     cerr << "{";
//     _print(p.ff);
//     cerr << ",";
//     _print(p.ss);
//     cerr << "}";
// }

// template <class T>
// void _print(vector<T> v){
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }

// template <class T>
// void _print(set<T> v){
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }

// template <class T>
// void _print(multiset<T> v){
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }

// template <class T, class V>
// void _print(map<T, V> v){
//     cerr << "[ ";
//     for (auto i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }

// bool is_prime(int n){
//     // Assumes that n is a positive natural number
//     // We know 1 is not a prime number
//     if (n == 1)
//     {
//         return false;
//     }

//     int i = 2;
//     // This will loop from 2 to int(sqrt(x))
//     while (i * i <= n)
//     {
//         // Check if i divides x without leaving a remainder
//         if (n % i == 0)
//         {
//             // This means that n has a factor in between 2 and sqrt(n)
//             // So it is not a prime number
//             return false;
//         }
//         i += 1;
//     }
//     // If we did not find any factor in the above loop,
//     // then n is a prime number
//     return true;
// }

// ll binomialCoeff(ll n, ll k){
//     ll res = 1;

//     // Since C(n, k) = C(n, n-k)
//     if (k > n - k)
//         k = n - k;

//     // Calculate value of
//     // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
//     for (ll i = 0; i < k; ++i)
//     {
//         res *= (n - i);
//         res /= (i + 1);
//     }

//     return res;
// }

// bool check(vector<vector<int>> a, int mid){
//     int n = a.size(), m = a[0].size();
//     vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (a[i][j] >= mid)
//             {
//                 a[i][j] = 1;
//             }
//             else
//             {
//                 a[i][j] = 0;
//             }
//             prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + a[i][j];
//         }
//     }
//     for (int i = mid; i < n + 1; i++)
//     {
//         for (int j = mid; j < m + 1; j++)
//         {
//             int sum = prefix_sum[i][j] - prefix_sum[i - mid][j] - prefix_sum[i][j - mid] + prefix_sum[i - mid][j - mid];
//             if (sum == (mid * mid))
//                 return true;
//         }
//     }
//     return false;
// }


// // bool dfs(int i, int col, vector<int> &color, vector<vector<int>> &graph){
// //         color[i] = col;
// //         col = 1 - col;
// //         for(auto it : graph[i]){
// //             if(color[it] == -1){
// //                 if(!dfs(it, col, color, graph)){
// //                     return false;
// //                 }
// //             }
// //             else{
// //                 if(color[it] == color[i]){
// //                     return false;
// //                 }
// //             }
// //         }
// //         return true;
        
// //     }
// // bool isBipartite(vector<vector<int>>& graph) {
// //     int n = graph.size();
// //     vector<int> color(n, -1);
// //     for(int i =0; i < n; i++){
// //         if(color[i] == -1){
// //             if(!dfs(i,0,color,graph)){
// //                 return false;
// //             }
// //         }
// //     }
// //     return true;
// // }
// class DSU{
//     public:
//         vector<ll> parent, size, rank;
//         DSU(int n){
//             parent.resize(n+1);
//             size.resize(n+1);
//             rank.resize(n+1);
//             for(int i = 0; i <= n; i++){
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
//         int findParent(int n){
//             if(n == parent[n]){
//                 return parent[n];
//             }
//             return parent[n] = findParent(parent[n]);
//         }
//         void unionBySize(int u, int v){
//             int pv = findParent(v);
//             int pu = findParent(u);
//             if(pu == pv) return;
//             if(size[pv] > size[pu]){
//                 parent[pu] = pv;
//                 size[pv] += size[pu];
//             }
//             else{
//                 parent[pv] = pu;
//                 size[pu] += size[pv]; 
//             }
//         }
//         void unionByRank(int u, int v){
//             int pv = findParent(v);
//             int pu = findParent(u);
//             if(pu == pv) return;
//             if(rank[pv] > rank[pu]){
//                 parent[pu] = pv;
//             }
//             else if(rank[pu] > rank[pv]){
//                 parent[pv] = pu;
//             }
//             else{
//                 parent[pv] = pu;
//                 rank[pu] = rank[pv] + 1; 
//             }
//         }
// };
// void dfs(int i, vector<bool> &vis, vector<int> adj[], int x){
//     vis[i] = true;
//     for(auto it : adj[i]){
//         if(it == x) continue;
//         if(!vis[it]){
//             dfs(it, vis, adj, x);
//         }
//     }
// }
// int main()
// {
//     fast;
// #ifndef ONLINE_JUDGE
//     freopen("Error.txt",
//             "w", stderr);
// #endif
//     // Code Here
//     ll t;
//     // cin >> t;
//     t = 1;
//     while(t--){
//         ll n, k, x;
//         cin >> n >> k;
//         vector<int> adj[n];
//         for(int i = 0; i < k; i++){
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         cin >> x;
//         vector<bool> vis(n, false);
//         if(x == 0)
//             dfs(1, vis, adj, x);
//         else dfs(x-1, vis, adj, x);
//         bool flag = false;
//         for(int i = 0; i < n; i++){
//             if(i != x and !vis[i]){
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag) cout << "Not Connected\n";
//         else cout << "Connected\n";
//     }
// }
