#include<bits/stdc++.h>
using namespace std;
class DSU{
    public: 
        vector<int> parent, rank, size;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            rank.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }

        int find_parent(int x){
            if(x == parent[x]) return x;
            else return parent[x] = find_parent(parent[x]);
        }

        void unionBySize(int u, int v){
            int pu = find_parent(u);
            int pv = find_parent(v);
            if(pu == pv) return;
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu]; 
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv]; 
            }
        }

        void unionByRank(int u, int v){
            int pu = find_parent(u);
            int pv = find_parent(v);
            if(pu == pv) return;
            if(rank[pu] < rank[pv]){
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
    DSU ob(n);
    int extra = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(ob.find_parent(u) == ob.find_parent(v)) extra++;
        else{
            ob.unionByRank(u, v);
        }
    }
    int components = 0;
    for(int i = 1; i <= n; i++){
        if(ob.parent[i] == i) components++;
    }
    if(components > k){
        cout << -1 << "\n";
    }
    else if(components == k){
        cout << extra << "\n";
    }
    else{
        int imp = m - extra;
        int components_wanted = k - components;
        if(components_wanted > imp){
            cout << - 1 << "\n";
        }
        else{
            cout << extra + components_wanted << "\n";
        }
    }
}