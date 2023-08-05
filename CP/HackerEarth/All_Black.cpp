#include<bits/stdc++.h>
using namespace std;
int solve(int node, int parent, vector<int> adj[], vector<int> &operation){
    for(auto it : adj[node]){
        if(it != parent){
            operation[node] += solve(it, node, adj, operation); 
        }
    }
    return operation[node];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int color[n];
        // Color of Node
        for(int i = 0; i < n; i++){
            cin >> color[i];
        }
        vector<int> adj[n];
        // edges;
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // M operation 
        vector<int> operation(n, 0);
        for(int i = 0; i < m; i++){
            int u;
            cin >> u;
            operation[u]++;
        }

        for(int i = 0; i < n; i++){
            operation[i] = operation[i]%2;
        }

        // Next we want to find the 
        solve(0, -1, adj, operation);


        for(int i = 0; i < n; i++){
            operation[i] = operation[i]%2;
        }

        for(int i = 0; i < n; i++){
            if(operation[i]){
                color[i] = !color[i];
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(color[i]) count++;
        }

        cout << count << endl;

    }
}