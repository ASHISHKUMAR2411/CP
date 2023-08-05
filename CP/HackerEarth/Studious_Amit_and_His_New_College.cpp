#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<bool> &vis, vector<bool> &check, vector<int> adj[]){
    vis[node] = true;
    check[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it, vis, check, adj)){
                return true;
            }
        }
        else if(check[it]){
            return true;
        }
    }
    check[node] = false;
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[v].push_back(u);
        }
        vector<bool> vis(n + 1, false), check(n + 1, false);
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                if(dfs(i, vis, check, adj)){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
}