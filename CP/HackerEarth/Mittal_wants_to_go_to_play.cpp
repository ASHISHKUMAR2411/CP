#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj[n + 1];
        for(int i = 0; i < m; i++){
            int u, v, dis;
            cin >> u >> v >> dis;
            adj[u].push_back({v, dis});
            adj[v].push_back({u, dis});
        }
        vector<int> dis(n + 1, 1e9);
        dis[1] = 0;
        // min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            for(auto it : adj[top.second]){
                int node = it[0];
                int distance = it[1];
                if(dis[node] > (dis[top.second] + distance)){
                    dis[node] = (dis[top.second] + distance);
                    pq.push({dis[node], node});
                }
            }
        }
        int q;
        cin >> q;
        int time = 0;
        for(int i = 0; i < q; i++){
            int a, k;
            cin >> a >> k;
            k -= 2*dis[a];
            time = k > 0 ? k : 0;
            cout << time << endl;
        }
        
    }
}