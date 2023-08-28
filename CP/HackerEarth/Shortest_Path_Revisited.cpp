#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<pair<int,int>> adj[], priority_queue<int, vector<int>, greater<int>> &pq, int &k, vector<int> &dist, int curr_dist){
    if(pq.top() == 0){
        pq.pop();
    }

    int di = curr_dist;
    if(pq.size() > k){
        int top = pq.top();
        pq.pop();
        di += top;
    }
    if(dist[node] > di){
        dist[node] = di;
        for(auto it : adj[node]){
            int n = it.first;
            int d = it.second;
            
        }
    }
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> adj[n + 1];
    vector<int> dist(n + 1,INT_MAX);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    dfs(1, -1, adj, pq, k, dist, 0);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}

long distinctCategoryCount(vector<int>&v){
    long ans=0,temp=0;
    map<int,int>mp;
    for(int i=0;i<(int)(v.size());i++){
        if(mp.count(v[i]))temp+=(i-mp[v[i]]);
        else temp+=(i+1);
        mp[v[i]]=i;
        ans+=temp;
    }
    return ans;
}
