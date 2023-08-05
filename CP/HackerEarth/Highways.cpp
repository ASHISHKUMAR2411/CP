#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, s, e;
        cin >> n >> m >> s >> e;
        vector<pair<int,int>> adj[n+1];
        for(int i = 0; i < m; i++){
            int u, v, t;
            cin >> u >> v >> t;
            adj[u].push_back({v, t}); 
            adj[v].push_back({u, t}); 
        }
        vector<int> dis(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        dis[s] = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int time = top.first;
            for(auto it : adj[node]){
                int child = it.first;
                int t = it.second;
                if(dis[child] > (time + t)){
                    dis[child] = (time + t);
                    pq.push({dis[child], child});
                }
            }
        }
        if(dis[e] == INT_MAX) cout << "NONE\n";
        else cout << dis[e] << "\n";
    }
}