#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const long long int N = 1e5 + 5;
long long int n, m, k;
vector<pair<int, int>> ar[N];
 
struct state {
    long long int distance;
    long long int city;
    long long int offer;
};
 
struct comp {
    bool operator () (const state &s1, const state &s2) {
        return s1.distance > s2.distance;
    }
};
 
int main() {
    fast;
    long long int i, j;
    cin >> n >> m >> k;
    while (m--) {
        long long int a, b, w;
        cin >> a >> b >> w;
        ar[a].emplace_back(b, w); ar[b].emplace_back(a, w);
    }
 
    auto dijkstra = [&](long long int src) -> vector<long long int> {
        vector<vector<long long int>> dis(n + 1, vector<long long int>(20, 1e15));
 
        priority_queue<state, vector<state>, comp> pq;
        dis[src][0] = 0;
        pq.push({0, src, 0});
 
        while (!pq.empty()) {
            auto [d, c, o] = pq.top(); pq.pop();
            // Above state represents that we reach city 'c' with distance 'd' and used 'o' offers
            if (dis[c][o] < d) continue;
 
            for (const auto &[x, w] : ar[c]) {
                if (o + 1 <= k) {
                    if (d < dis[x][o + 1]) { // using offer 
                        dis[x][o + 1] = d;
                        pq.push({dis[x][o + 1], x, o + 1});
                    }
                }
 
                if (d + w < dis[x][o]) { // not using offer
                    dis[x][o] = d + w;
                    pq.push({dis[x][o], x, o});
                }
            }
        }
        vector<long long int> res;
        for (long long int node = 1; node <= n; node++) {
            long long int mn = 1e15;
            for (long long int offer = 0; offer <= k; offer++) {
                mn = min(mn, dis[node][offer]);
            }
            res.emplace_back(mn);
        }
        return res;
    };
 
    vector<long long int> ans = dijkstra(1);
    for (auto &x : ans) {
        cout << x << " ";
    }
}
// #include<bits/stdc++.h>
// using namespace std;
// void dfs(int node, vector<vector<int>> adj[], vector<int> &dist, priority_queue<int, vector<int>, greater<int>> pq, int &k, int sum){
//     for(auto it : adj[node]){
//         int cost = sum;
//         cost += it[1];
//         int child = it[0];
//         priority_queue<int, vector<int>, greater<int>> dummy = pq;
//         dummy.push(it[1]);
//         while(dummy.size() > k){
//             dummy.pop();
//         }
//         while(!dummy.empty()){
//             cost -= dummy.top();
//             dummy.pop();
//         }
//         if(dist[child] > cost){
//             dist[child]  = cost;
//             priority_queue<int, vector<int>, greater<int>> d1 = pq;
//             d1.push(it[1]);
//             dfs(child, adj, dist, d1, k, sum + it[1]);
//         }
//     }
// }
// int main(){
//     int n, m,k;
//     cin >> n >> m >> k;
//     vector<vector<int>> adj[n + 1];
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }
//     vector<int> dist(n + 1, 1e9);
//     priority_queue<int, vector<int>, greater<int>> pq;
//     dist[1] = 0;
//     dfs(1, adj, dist, pq, k, 0);
//     for(int i = 1; i <= n; i++){
//         cout << dist[i] << " ";
//     }
//     cout << endl;
// }