#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        vector<pair<int, int>> adj[v + 1];
        for(int i = 0; i < e; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
        }
        int a, b;
        cin >> a >> b;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(v+1, INT_MAX);

        pq.push({a, 0});
        ans[a] = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top.second;
            int node = top.first;
            for(auto it : adj[node]){
                int cur_dist = d + it.second;
                if(ans[it.first] > cur_dist){
                    ans[it.first] = cur_dist;
                    pq.push(make_pair(it.first, cur_dist));
                }
            }
        }
        if(ans[b] == INT_MAX){
            cout << "NO" << "\n";
        }
        else{
            cout << ans[b] << "\n";
        }
    }
    return 0;
}