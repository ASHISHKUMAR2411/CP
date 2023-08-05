#include<bits/stdc++.h>
using namespace std;
int dfs(int node, vector<bool> &vis, vector<int> adj[]){
    vis[node] = true;
    int count = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            count += dfs(it, vis, adj);
        }
    }
    return count;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int mini = INT_MAX;
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= n; i++){
        vector<bool> vis(n + 1, false);
        ans[i] = dfs(i, vis, adj);
    }
    for(int i = 1; i <= n; i++){
        mini = min(mini, ans[i]);
    }
    cout << mini << endl;
}