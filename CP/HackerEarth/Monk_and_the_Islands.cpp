#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> adj[n+1];
        for(int i =0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
        int x, y;
        x = 1;
        y = n;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {x, -1}});
        vector<int> dist(n+1, 1e9);
        dist[x] = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second.first;
            int parent = top.second.second;
            int d = top.first;
            for(auto it: adj[node]){
                int n0 = it.first;
                int dis = it.second;
                if(n0 == parent) continue;
                if(dist[n0] > (d + dis)){
                    dist[n0] = d + dis;
                    pq.push({dist[n0], {n0, node}});
                }
            }
        }
        cout << dist[y] << "\n";
    }
}