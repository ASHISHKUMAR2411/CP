#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, int parent, vector<int> adj[], vector<int> &bus_terminal){
    if(bus_terminal[i]) return true;
    for(auto it : adj[i]){
        if(it != parent)
            if(dfs(it, i, adj, bus_terminal)) return true;
    }
    return false;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> adj[n+1];
    vector<int> bus_terminal(n+1, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < k; i++){
        int u;
        cin >> u;
        bus_terminal[u] = 1;
    }
    int crowded_city = k;
    for(int i = 1; i <= n; i++){
        if(bus_terminal[i]) continue;
        else{
            int count = 0;
            for(auto it : adj[i]){
                if(dfs(it, i, adj, bus_terminal)){
                    count++;
                }
            }
            if(count > 1) crowded_city++;
        }
    }
    cout << crowded_city << "\n";
}