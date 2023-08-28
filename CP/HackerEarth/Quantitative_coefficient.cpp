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
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        for(int i = 0; i < m; i++){
            int a,b,c;
            cin >> a >> b >> c;
            pq.push({c, a, b});
        }
        int ans = 1, mod = 1e9 + 7;
        DSU ob(n);
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int u = tp[1];
            int v = tp[2];
            int pu = ob.findParent(u);
            int pv = ob.findParent(v);
            if(pu != pv){
                ans = (ans%mod *1ll* tp[0]%mod)%mod;
                ob.unionByRank(pu, pv);
            }
        }
        cout << ans << endl;
    }
}