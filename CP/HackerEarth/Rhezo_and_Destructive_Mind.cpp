#include<bits/stdc++.h>
using namespace std;
vector<int> ap, disc, low;
int t = 0;
int dfs(int u, int parent, vector<int> adj[]){
    int child = 0;
    low[u] = disc[u] = ++t;
    for(auto v : adj[u]){
        if(v == parent) continue;
        if(!disc[v]){
            child++;
            dfs(v, u, adj);
            if(disc[u] <= low[v]){
                ap[u] = 1;
            }
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], disc[v]);
        }
    }
    return child;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    t = 0;
    ap = disc = low = vector<int>(n + 1);
    for(int i = 1; i <= n; i++){
        if(!disc[i]){
            ap[i] = dfs(i, -1, adj) > 1;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        if(ap[x] == 1){
            cout << "Satisfied" << " " << adj[x].size() << "\n";
        }
        else{
            cout << "Not Satisfied\n";
        }
    }
}