#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans(n, INT_MAX);
    queue<pair<int,int>> que;
    que.push({0, 0});
    ans[0] = 0;
    while(!que.empty()){
        auto top = que.front();
        que.pop();
        int x = top.second;
        int l = top.first;
        for(auto it : adj[x]){
            if(ans[it] > l + 1){
                ans[it] = l + 1;
                que.push({ans[it], it});
            }
        }
    }
    for(int i = 1; i < n; i++){
        cout << ans[i] << "\n";
    }
}