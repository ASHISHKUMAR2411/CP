#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, int &l, vector<vector<int>> &mat, vector<vector<bool>> &vis, vector<pair<int, int>> ans, vector<pair<int, int>> &answer){
    if(i <= 0 or j <= 0 or (i > mat.size() ) or (j > mat[0].size())){
        ans.pop_back();
        answer = ans;
        return;
    }
    vis[i][j] = true;
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(mat[x][y] > mat[i][j]) continue;
        if(mat[i][j] - mat[x][y] <= l and !vis[x][y]){
            ans.push_back({x,y});
            dfs(x, y, l, mat, vis, ans, answer);
            ans.pop_back();
        }
    }
    // vis[i][j] = false;
}
int main(){
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        int n, m;
        cin >> n >> m; 
        
        vector<vector<int>> mat(n + 2, vector<int>(m + 2, 0));
        vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> mat[i][j];
            }
        }
        int x, y, l;
        cin >> x >> y >> l;
        vector<pair<int, int>> ans;
        vector<pair<int, int>> answer;
        ans.push_back({x,y});
        dfs(x, y, l, mat, vis, ans, answer);
        if(answer.size()){
            cout << "YES\n";
            cout << answer.size() << "\n";
            for(auto it : answer){
                cout << it.first << " " << it.second << "\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
}