#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> adj[n+1];
        for(int i = 1; i <= n; i++){
            int u;
            cin >> u;
            if(u + 1 <= n){
                adj[i].push_back({u + 1, 1});
            }
            if(u - 1 >= 1){
                adj[i].push_back({u-1, 1});
            }
            adj[i].push_back({u, 0});
        }
        vector<int> dist(n+1, INT_MAX);
        deque<int> q;
        q.push_back(1);
        dist[1]=0;
        while(!q.empty())
        {
            int v=q.front();
            q.pop_front();
            for(auto x : adj[v])
            {
                if(dist[x.first] > dist[v]+x.second)
                {
                    dist[x.first]=dist[v]+x.second;
                    if(x.second==0)
                        q.push_front(x.first);
                    else
                        q.push_back(x.first);
                }
            }
        }
        cout<<dist[n]<<"\n";
    }

    return 0;
}