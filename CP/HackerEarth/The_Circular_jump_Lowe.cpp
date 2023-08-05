#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            int u;
            cin >> u;
            u = u%n;
            int left = (i - u + n)%(n);
            int right = (i + u)%(n);
            adj[i].push_back(left);
            adj[i].push_back(right);
        }
        // for(int i = 0; i < n; i++){
        //     cout << i << ": ";
        //     for(auto it : adj[i]){
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }
        x--;
        y--;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, x});
        vector<int> ans(n, 1e7);
        ans[x] = 0;
        while(!pq.empty()){
            auto top = pq.top();
            int node = top.second;
            int dis = top.first;
            pq.pop();
            for(auto it : adj[node]){
                if(ans[it] > dis + 1){
                    ans[it] = dis + 1;
                    pq.push({ans[it], it});
                }
            }
        }
        if(ans[y] == 1e7)
        ans[y] = -1;
        cout << ans[y] << endl;
    }
}