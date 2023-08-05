#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> ans(n + 1, 1e9);
    // vector<bool> selfLoop(n + 1, false);
    ans[1] = 0;
    set<int> adj[n+1];
    int u, v;
    for(int i = 0; i < m; i++){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            if(ans[x] != 1e9)
                cout << ans[x] << endl;
            else{
                cout << -1 << endl;
            }
        }
        else{
            cin >> u >> v;
            if(u == v){ continue;}
            adj[u].insert(v);
            if(ans[u] + 1 < ans[v]){
                ans[v] = ans[u] + 1;
                queue<int> q;
                q.push(v);
                q.push(u);
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    for(auto it : adj[top]){
                        if(ans[it] > ans[top] + 1){
                            ans[it] = ans[top] + 1;
                            q.push(it);
                        }
                    }
                }
            }
            else if(ans[u] > ans[v] + 1){
                ans[u] = ans[v] + 1;
                queue<int> q;
                q.push(u);
                while(!q.empty()){
                    int top = q.front();
                    q.pop();
                    for(auto it : adj[top]){
                        if(ans[it] > ans[top] + 1){
                            ans[it] = ans[top] + 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
    }
}