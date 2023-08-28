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
    int t;
    t = 1;
    // cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        DSU obM(n), obF(n);
        priority_queue<vector<int>> pq;
        for(int i = 0; i < m; i++){
            int u, v, type;
            cin >> u >> v >> type;
            pq.push({type, u, v});
        }
        int count = 0;
        while(!pq.empty()){
            auto tp = pq.top();
            // cout << tp[0] << " \n";
            // for(auto it : tp){
            //     cout << it << " ";
            // }
            // cout << endl;
            pq.pop();
            if(tp[0] == 3){
                int pv1 = obM.findParent(tp[1]);
                int pu1 = obM.findParent(tp[2]);
                int pv2 = obF.findParent(tp[1]);
                int pu2 = obF.findParent(tp[2]); 
                if(pv1 == pu1 and pv2 == pu2){
                    count++;
                }
                else{
                    obM.unionByRank(pv1, pu1);
                    obF.unionByRank(pv2, pu2);
                }
            }
            else if(tp[0] == 1){
                int pv1 = obM.findParent(tp[1]);
                int pu1 = obM.findParent(tp[2]);
                if(pv1 == pu1){
                    count++;
                }
                else{
                    obM.unionByRank(pv1, pu1);
                }
            }
            else if(tp[0] == 2){
                int pv1 = obF.findParent(tp[1]);
                int pu1 = obF.findParent(tp[2]);
                if(pv1 == pu1){
                    count++;
                }
                else{
                    obF.unionByRank(pv1, pu1);
                }
            }
        }
        int c = 0;
        for(int i = 1; i <= n; i++){
            if(obM.parent[i] == i){
                c++;
            }
            if(obF.parent[i] == i){
                c++;
            }
        }
        if(c > 2) cout << -1 << endl;
        else
        cout << count << endl;
    }
}