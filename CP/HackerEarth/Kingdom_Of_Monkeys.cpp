#include<bits/stdc++.h>
using namespace std;
void dfs(long long node, vector<bool> &vis, vector<long long> adj[], long long &sum, vector<long long> &banana)
{
    sum += banana[node];
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, sum, banana);
        }
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<long long> adj[n + 1];
        for(long long i = 0; i < m; i++){
            long long u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // banana
        vector<long long> banana(n + 1, 0); 
        for(long long i = 1; i <= n; i++){
            cin >> banana[i];
        }
        long long maxi = 0;
        vector<bool> vis(n + 1, false);
        for(long long i = 1; i <= n; i++){
            if(!vis[i]){
                long long sum = 0;
                dfs(i, vis, adj, sum, banana);
                if(sum > maxi){
                    maxi = sum;
                }
            }
        }
        cout << maxi << endl;
    }
}