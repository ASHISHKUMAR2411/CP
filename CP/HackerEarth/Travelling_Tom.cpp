#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
        vector<int> parent, size, rank;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1);
            rank.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findParent(int n){
            if(n == parent[n]){
                return parent[n];
            }
            return parent[n] = findParent(parent[n]);
        }
        void unionBySize(int u, int v){
            int pv = findParent(v);
            int pu = findParent(u);
            if(pu == pv) return;
            if(size[pv] > size[pu]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv]; 
            }
        }
        void unionByRank(int u, int v){
            int pv = findParent(v);
            int pu = findParent(u);
            if(pu == pv) return;
            if(rank[pv] > rank[pu]){
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            }
            else{
                parent[pv] = pu;
                rank[pu] = rank[pv] + 1; 
            }
        }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cost(k + 1, 0);
    for(int i = 1; i <= k; i++){
        cin >> cost[i];
    }

    // Node collection 
    vector<pair<int, vector<int>>> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v, size;
        cin >> u >> v >> size;
        vector<int> indexes(size, 0);
        for(int i = 0; i < size; i++){
            cin >> indexes[i];
        }
        adj[u].push_back({v, indexes});
        adj[v].push_back({u, indexes});
    }
    // for(int i = 1; i <= n; i++){
    //     cout << i << " : ";
    //     for(auto it : adj[i]){
    //         cout << it.first << " [";
    //         for(auto j : it.second){
    //             cout << " " << j;
    //         }
    //         cout << "]\n";
    //     }
    // }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 1, -1});
    vector<int> ans(n + 1, INT_MAX);
    vector<int> s[n + 1];
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if(top[2] != -1){
            int sum = 0;
            vector<int> sus;
            for(auto it : adj[top[1]]){
                if(it.first == top[2]){
                    for(auto u : it.second){
                        sum += cost[u];
                        sus.push_back(u);
                    }
                    break;
                }
            }
            if(ans[top[1]] >= sum){
                ans[top[1]] = sum;
                s[top[1]] = sus;
            }
        }
        for(auto it : adj[top[1]]){
            if(it.first == top[2]) continue;
            int sum = 0;
            for(auto i : it.second){
                sum += cost[i];
            }
            if(sum < ans[it.first]){
                pq.push({sum, it.first, top[1]});
            }
        }
    }
    int answer = 0;
    set<int> par;
    for(int i = 1; i <= n; i++){
        // cout << i << ": ";
        for(int j = 0; j < s[i].size(); j++){
            // cout << s[i][j] << " ";
            par.insert(s[i][j]);
        }
        // cout << endl;
    }
    for(auto it : par){
        // cout << it << " ";
        answer += cost[it];
    }
    cout << answer << endl;

    

}