#include<bits/stdc++.h>
using namespace std;
// Disjoint Set Class
class DSU{
    public:
        // Three arrays for keep track of parent node, their current component size or current rank
        vector<int> parent, size, rank;
        // Initialization where every node is parent of themselves size is 1
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1);
            rank.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        // finding parent of the node n
        int findParent(int n){
            if(n == parent[n]){
                return parent[n];
            }
            return parent[n] = findParent(parent[n]);
        }

        // combining the u, v nodes together just like adding a edge in between them if their parent is not same, i.e they do not belong to the same components
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
    // for faster input, very important as input is large enough
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // t test cases 
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        // for adjacency list, undirected because we can reach from node to another node just to keep track of the weight. 
        vector<pair<int,int>> adj[n + 1];
        for(int i = 0; i < m; i++){
            int u, v, wt;
            cin >> u >> v >> wt;
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // for calculating total weight
        int sum = 0;
        DSU ob(n);

        // pq  will always give us the edge with maximum weight, so that we choose greedily 
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0, {1, -1}});

        // applying bfs because we need to check all the nodes connected and then choose the maximum edge possible from it. 

        // then we have add the maximum edge nodes into the same component if they do not belong and add weight to the sum, as it will be part of the maximum spanning tree. 
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top.first;
            int u = top.second.first;
            int v = top.second.second;
            if(v != -1 and ob.findParent(u)!= ob.findParent(v)){
                ob.unionBySize(u, v);
                sum += d;
            }
            for(auto it : adj[u]){
                int nd = it.first;
                int dis = it.second;
                if(ob.findParent(u)!= ob.findParent(nd)){
                    pq.push({dis, {nd, u}});
                }
            }
        }
        cout << sum << endl;
    }
}