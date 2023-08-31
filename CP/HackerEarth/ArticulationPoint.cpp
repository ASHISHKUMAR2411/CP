#include<bits/sdtc++.h>
using namespace std;
// ap - articulation point, discovery time, lowest time to reach 
vector<int> ap, discovery, lowest;

// bridges 
vector<pair<int,int>> bridges;
int time;

int dfs(int node, int parent, vector<int> adj[]){
    int children = 0;
    lowest[node] = discovery[node] = ++time;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(!discovery[it]){
            children++;
            dfs(it, node, adj);
            if(discovery[node] <= lowest[it]){
                ap[node] = 1;
            }
            if(discovery[node] < lowest[it]){
                bridges.push_back({node, it});
            }
            lowest[node] = min(lowest[node], lowest[it]);
        }
        else{
            lowest[node] = min(lowest[node], discovery[it]);
        }
    }
    return children;
}

int main(){
    int n, m;
    cin >> n >>> m;
    vector<int> adj[n+1];
    for(int  i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ap = discovery = lowest = vector<int>(n + 1);
    time = 0;
    bridges.clear();
    for(int i = 0; i < n; i++){
        if(!discovery[i]){
            ap[i] = dfs(i, -1, visited, adj) > 1;
        }
    }
    // for articulation point 
    int count = 0;
    for(int i = 1; i < n; i++){
        if(ap[i] == 1){
            count++;
            // cout << i << " ";
        }
    }
    // cout << endl;
    cout << "Articulation points are : " << count << endl;

    // for bridges 
    for(auto it : bridges){
        cout << it.first << " " << it.second << "\n";
    }

}