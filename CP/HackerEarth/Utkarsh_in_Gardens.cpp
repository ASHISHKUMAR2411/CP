#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n+1][n+1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            int cnt = 0;
            cnt = (a[i] & a[j]).count();
            // for (int k = 0; k < n; k++) 
            //     if (a[i][k]==1 && a[k][j]==1) cnt++;
            ans += cnt*(cnt-1)/2;
        }
    cout << (ans/2) << "\n";
}
// #include<bits/stdc++.h>
// using namespace std;
// void dfs(int node, int start, int parent, int counter, vector<int> adj[], set<vector<int>> &ans, vector<int> curr){
//     // if(counter > 4) return;
//     if(counter == 4){
//         if(node == start){
//             curr.pop_back();
//             sort(curr.begin(), curr.end());
//             // if(ans.find(curr) == ans.end())
//                 ans.insert(curr);
//         }
//         return;
//     }
//     for(auto it : adj[node]){
//         if(it == parent) continue;
//         curr.push_back(it);
//         dfs(it, start, node, counter + 1, adj, ans, curr);
//         curr.pop_back();
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> adj[n+1];
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             int t;
//             cin >> t;
//             if(t == 1){
//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//             }
//         }
//     }
//     set<vector<int>> ans;
//     vector<int> curr;
//     for(int i = 1; i <= n; i++){
//         curr.push_back(i);
//         dfs(i,i,-1, 0, adj, ans, curr);
//         curr.pop_back();
//     }
//     cout << ans.size() << endl;
// }