#include<bits/stdc++.h>
using namespace std;
// int solve(int node, int end,int parent, vector<int> adj[], vector<int> &a, int &mn, int &s){
//     if(node == end) return 0;
//     int maxi = INT_MIN;
//     for(auto it : adj[node]){
//         if(it == parent) continue;
//         int t = solve(it, end, node, adj, a, mn, s);
//         int doff = abs(a[node] - a[it]);
//         maxi = max(t, doff);
//         if(node == s){
//             mn = min(mn, maxi);
//         }
//     }
//     return maxi;
// }
int main(){
    int n, m;
    cin >> n >> m;
    int s, e;
    cin >> s >> e;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // value 
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({0, s});
    vector<int>dist(n + 1, 1e9);
    dist[s] = 0;
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        int node = v[1];
        int d = v[0];
        if (node == e){
            dist[e] = d;
            break;
        }
        if (dist[node] < d)continue;
        for (auto child : adj[node]) {
            if (dist[child] > max((int)abs(a[child] - a[node]), d)) {
                dist[child] = max((int)abs(a[child] - a[node]), d);
                pq.push({dist[child], child});
            }
        }
    }
    cout << dist[e] << "\n";

}