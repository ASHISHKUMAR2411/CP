#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define N  1000001 
long long k;
vector<long long> adj[N];
unordered_map<long long, vector<long long>> mp;
vector<long long> ans(N);
vector<long long> color(N);
void dfs(long long node, long long parent){
    for(auto it : adj[node]){
        if(it == parent){
            continue;
        }
        long long size = mp[color[it]].size();
        if(size >= k){
            ans[it] = mp[color[it]][size - k];
        }
        else{
            ans[it] = -1;
        }
        mp[color[it]].push_back(it);
        dfs(it, node);
        mp[color[it]].pop_back();
    }
}
int main(){
    fast;
    long long n;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++){
        cin >> color[i];
    }
    for(long long i = 0; i < n-1; i++){
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mp[color[1]].push_back(1);
    ans[1] = -1;
    dfs(1, -1);
    for(long long i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}