#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, m, f;
    cin >> n >> m >> f;
    vector<long long> cap(n + 1, 0);
    for(long long i = 1; i <= n; i++){
        cin >> cap[i];
    }
    vector<vector<long long>> adj[n + 1];
    for(long long i = 0; i< m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    long long k;
    cin >> k;
    vector<long long> dist(n + 1, 2000000000);
    vector<bool> vis(n + 1, false);
    vector<long long> costOfVehicle(k + 1);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if(vis[top.second]) continue;
        vis[top.second] = true;
        for(auto it : adj[top.second]){
            long long node = it[0];
            long long d = it[1];
            if(dist[node] > (d + dist[top.second])){
                dist[node] = (d + dist[top.second]);
                pq.push({dist[node], node});
            }
        }
    } 
    map<long long, vector<long long>> mp;
    for(long long i = 1; i <= n; i++){
        if(dist[i] != 2000000000)
            mp[dist[i]].push_back(i);
    }
    long long i = 1;
    for(auto it : mp){
        long long reachingCost = it.first;
        for(auto ele : it.second){
            long long capacity = cap[ele];
            while(capacity and i <= k){
                long long costPerVehicle = reachingCost + f;
                costOfVehicle[i] = (costPerVehicle);
                capacity--;
                i++;
            }
        }
    }
    while(i <= k){
        costOfVehicle[i] = -1;
        i++;
    }
    for(long long i = 1; i <= k; i++){
        cout << costOfVehicle[i] << " ";
    }
    cout << endl;
}