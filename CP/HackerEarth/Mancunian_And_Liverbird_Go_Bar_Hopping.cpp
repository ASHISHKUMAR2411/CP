#include<bits/stdc++.h>
using namespace std;
int dfs(int node, vector<int> &arr, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    int count = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            count += dfs(it, arr, adj, vis);
        }
        else count += arr[it];
    }
    arr[node] = count + 1;
    return arr[node];
}
int main(){
    int n;
    cin >> n;
    vector<int> adj[n+1], r_adj[n+1];
    for(int i = 1; i <= n - 1; i++){
        int u;
        cin >> u;
        if(u == 1){
            adj[i].push_back(i+1);
            r_adj[i+1].push_back(i);
        }
        else{
            adj[i+1].push_back(i);
            r_adj[i].push_back(i+1);
        }
    }
    vector<int> arr(n+1, 0), r_arr(n+1, 0);
    vector<int> vis(n+1, 0), r_vis(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, arr, adj, vis);
        }
    }
    for(int i = 1; i <= n; i++){
        if(!r_vis[i]){
            dfs(i, r_arr, r_adj, r_vis);
        }
    }
    // for(auto it : r_arr){
    //     cout << it <<  " ";
    // }
    // cout << endl;
    int q;
    cin >> q;
    bool flag = true;
    for(int i = 0; i < q; i++){
        char c;
        int node;
        cin >> c;
        if(c == 'U'){
            flag = !flag;
        }
        else{
            cin >> node;
            if(flag){
                cout << arr[node] << "\n";
            }
            else{
                cout << r_arr[node] << "\n";
            }
        }
    }



}