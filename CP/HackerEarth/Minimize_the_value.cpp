#include<bits/stdc++.h>
using namespace std;
long long dfs(long long node, long long parent, vector<long long> &ans, vector<long long> adj[], vector<long long> &value){
    long long count = 0;
    for(auto it : adj[node]){
        if(it == parent) continue;
        count += dfs(it, node, ans, adj, value);
    }
    count += value[node];
    return ans[node] = count;
}
int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> value(n + 1, 0);
    for(long long i = 1; i <= n; i++){
        cin >> value[i];
    }
    // value[n+1] = x;
    vector<long long> adj[n+1];
    for(long long i = 0; i < n - 1; i++){
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // We have the adjacency list 
    queue<pair<long long,long long>> q;
    q.push({1, -1});
    bool flag = true;
    int level = 0;
    while(!q.empty()){
        long long size = q.size();
        if(size != pow(2, level)){
            break;
        }
        else{
            level++;
            for(long long i = 0; i < size; i++){
                auto top = q.front();
                long long node = top.first;
                long long parent = top.second;
                q.pop();
                for(auto it : adj[node]){
                    if(it == parent) continue;
                    q.push({it, node});
                }
            }
        }
    }
    level++;
    vector<long long> ans(n + 1, 0);
    dfs(1, -1, ans, adj, value);
    long long a = 0;
    for(auto it: ans){
        a += it;
    }
    a += (x * level);
    cout << a << "\n";
}