#include<bits/stdc++.h>
using namespace std;
// FIrst find the length of the diameters, 
// Then find the edges nodes 
// Traverse the edge nodes and mark them visited onces they are part of the diameter
// Now after traversing all the edge nodes, we have to check the visited node, if it is equal to N, that means all are part of the diameter so answer would be ceil(S/Edges) 
// Else 0 would be our answer




int main(){
    int t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> adj[n+1];
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> edges;
        int len = diameter(1, adj);

    }
}