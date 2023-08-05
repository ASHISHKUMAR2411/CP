#include <bits/stdc++.h>
using namespace std;
#define N 100002
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define deb(x) cout << #x << '=' << x << endl;
#define deb2(x, y) cout << #x << '=' << x << ', ' << #y << '=' << y << endl;
#define fastIO \
ios_base::sync_with_stdio(false); \
cin.tie(NULL); \
cout.precision(12);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
const double PI = 3.1415926535897932384626;
const ll oo = 1e18;
ll n, m, u, v, timer;
vll adj[N], tin(N, -1), low(N, -1), bridges;
vb vis(N, 0);
ll inverse(ll a)
{
    ll res = 1, pw = MOD - 2;
    while (pw)
    {
        if (pw & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        pw >>= 1;
    }
    return res;
}
ll dfs(ll node, ll par)
{
    ll sz = 1;
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (ll &to : adj[node])
    {
        if (to == par)
            continue;
        if (vis[to])
            low[node] = min(low[node], tin[to]);
        else
        {
            ll tmp = dfs(to, node);
            if (low[to] > tin[node])
                bridges.pb(tmp);
            low[node] = min(low[node], low[to]);
            sz += tmp;
        }
    }

    return sz;

}
void solution()
{
    timer = 0;
    cin >> n >> m;
    fo(i, 0, m)
    {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    }
    dfs(1, -1);
    ll eve = 0, tot = bridges.size();
    fo(i, 0, bridges.size())
    {
        if (bridges[i] % 2 == 0 && (n - bridges[i]) % 2 == 0)
            eve++;
    }
    ll den = inverse(tot);
    cout << (eve * den) % MOD << " " << ((tot - eve) * den) % MOD;
}


signed main()
{
    fastIO;
    long t = 1;
    // cin >> t;
    while (t--)
        solution();
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int dfs(int node, int parent, int &timer, vector<int> &time, vector<int> &low, vector<int> &bridges, vector<bool> &visited, vector<int> adj[]){
//     visited[node] = true;
//     int size = 1;
//     time[node] = low[node] = timer++;
//     for(auto it : adj[node]){
//         if(parent == it) continue;
//         if(visited[it]){
//             low[node] = min(low[node], time[it]);
//         }
//         else{
//             int temp = dfs(it, node, timer, time, low, bridges, visited, adj);
//             low[node] = min(low[node], low[it]);
//             if(low[it] > time[node]){
//                 bridges.push_back(temp);
//             }
//             size += temp;
//         }
//     }
//     return size;
// }
// int inv(int a, int mod){
//     int res = 1, power = mod - 2;
//     while(power){
//         if(power & 1){
//             res = (res%mod * a%mod)%mod;
//         }
//         a = (a%mod * a%mod)%mod;
//         power = power >> 1;
//     }
//     return res;
// }
// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> adj[n+1];
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     // Now we will find the bridges and along with that we will find the number of the size of the descendent of that bridge, if we have descendant and we can find ancestors from it. 
//     // to find the bridges we will use the dfs 
//     vector<int> bridges;
//     vector<int> time(n+1, 0);
//     vector<int> low(n+1, 1e6);
//     int timer = 0;
//     vector<bool> visited(n+1, false);
//     // dfs(node, parent, timer, time, low, bridges)
//     dfs(1, -1, timer, time, low, bridges, visited, adj);
//     int total = bridges.size();
//     int winA = 0;
//     for(int i = 0; i < bridges.size(); i++){
//         if(bridges[i]%2 == 0 && (n - bridges[i])%2 == 0) winA++;
//     }
//     int mod = 1e9 + 7;
//     int inverse = inv(total, mod);
//     int pA = (winA%mod * inverse%mod)%mod;
//     int pB = ((total - winA + mod)%mod * inverse%mod)%mod;
//     cout << pA << " " << pB; 
// }