#include<bits/stdc++.h>
using namespace std;
long long mod = (pow(10,9)+7);
long long factorial(long long n){
    if(n ==0|| n ==1){
        return 1;
    }
    long long smallOutput =factorial(n-1);
    long long output = n*smallOutput;
    return (output%mod);
}
void dfs(vector<vector<int>> &chess, vector<vector<bool>> &visited, int x, int y,vector<pair<int,int>>& component, int n, int m){
        int dir[8][2]={{-2,1},{2,-1},{-1,-2},{-1,2},{1,2},{1,-2},{-2,-1},{2,1}};
        component.push_back(make_pair(x, y));
        visited[x][y]=true;
        for(int k =0; k <8; k++){
            int nextX =(x + dir[k][0]);
            int nextY =(y + dir[k][1]);
            if(nextX >=1 && nextX <= n && nextY >=1 && nextY <= m && visited[nextX][nextY] == false && chess[nextX][nextY] == 1){
                dfs(chess, visited, nextX, nextY, component, n, m);
            }
        }
}
int main(){
    int t;
    cin >> t;
    while(t--){
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> chess(n + 1, vector<int>(m + 1, 0));
    for(int i =0; i < q; i++){
        int x, y;
        cin >> x >> y;
        chess[x][y]=1;
    }
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    long long finalAns =1;
    for(int i =1; i <= n; i++){
        for(int j =1; j <= m; j++){
            if(chess[i][j]==1&&visited[i][j]==false){
                vector<pair<int,int>> component;
                dfs(chess, visited, i, j, component, n, m);
                long long ans = factorial(component.size());
                finalAns  =(((finalAns%mod)*(ans%mod))%mod);
            }
        }
    }
    cout << finalAns << endl;
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// class dsu{
//     public: 
//         vector<int> parent; vector<int> size; vector<int> rank;
//         dsu(int n){
//             n = n+ 1;
//             parent.resize(n);
//             size.resize(n, 1);
//             rank.resize(n);
//             for(int i = 0; i < n; i++){
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
//         int findParent(int n){
//             if(n == parent[n]) return n;
//             return parent[n] = findParent(parent[n]);
//         }
//         void unionBySize(int u, int v){
//             int pu = findParent(u);
//             int pv = findParent(v);
//             if(pu == pv) return;
//             if(size[pv] > size[pu]){
//                 parent[pu] = pv;
//                 size[pv] += size[pu];
//             }
//             else{
//                 parent[pv] = pu;
//                 size[pu] += size[pv];
//             }
//         }
// };
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n, m, q;
//         cin >> n >> m >> q;
//         map<pair<int,int>, int> mp;
//         queue<pair<int, int>> que;
//         set<pair<int,int>> s;
//         for(int i = 1; i <= q; i++){
//             int u, v;
//             cin >> u >> v;
//             que.push({u, v});
//             mp[{u, v}] = i;
//         }
//         dsu ob(q);
//         // intdir[8][2]={{-2,1},{2,-1},{-1,-2},{-1,2},{1,2},{1,-2},{-2,-1},{2,1}};
//         int dx[] = {-1, -1, -2, -2, 2, 2, 1, 1};
//         int dy[] = {-2, 2, 1, -1, 1, -1, -2, 2};
//         while(!que.empty()){
//             auto top = que.front();
//             que.pop();
//             if(s.find(top) == s.end()){
//                 s.insert(top);
//                 queue<pair<int,int>> temp;
//                 temp.push(top);
//                 while(!temp.empty()){
//                     auto t = temp.front();
//                     temp.pop();
//                     for(int i = 0; i < 8; i++){
//                         int x = t.first + dx[i];
//                         int y = t.second + dy[i];
//                         if(x < 1 or y < 1 or x > n or y > m) continue;
//                         if(mp.find({x, y}) != mp.end() and ob.parent[mp[{x,y}]] != ob.parent[mp[t]]){
//                             ob.unionBySize(mp[{x,y}], mp[t]);
//                             temp.push({x,y});
//                             s.insert({x, y});
//                         }
//                     }
//                 }
//             }
//         }
//         // for(auto it : ob.parent){
//         //     cout << it << " ";
//         // }
//         // cout << endl;
//         int ans = 1; 
//         int mod = 1e9 + 7;
//         for(int i = 1; i < ob.parent.size(); i++){
//             if(ob.parent[i] == i){
//                 int count = ob.size[i];
//                 while(count){
//                     ans = (ans%mod * count%mod)%mod;
//                     count--;
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
// }