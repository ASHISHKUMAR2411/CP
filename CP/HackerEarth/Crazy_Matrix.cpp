#include<bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, 1, -1, -1, 1};
bool dfs(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &vis, int find){
    int n = mat.size();
    if(mat[x][y] == 1 and find == 1 and x == (n - 1)){
        return true;
    }
    if(find == 2 and mat[x][y] == 2 and  y == (n - 1)){
        return true;
    }
    vis[x][y] = true;
    bool f = false;
    for(int i = 0; i < 8; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X < 0 or Y < 0 or X >= n or Y >= n or mat[X][Y] != find or vis[X][Y]) continue;
        f |= dfs(X, Y, mat, vis, find);
    }
    // vis[x][y] = false;
    return f;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    queue<pair<int,int>> qr, qc;
    for(int i = 0; i < n; i++){
        if(mat[0][i] == 1){
            qr.push({0,i});
        }
        if(mat[i][0] == 2){
            qc.push({i, 0});
        }
    }
    
    bool r1 = false, c2 = false;
    while(!qr.empty()){
        auto top = qr.front();
        qr.pop();
        int x = top.first;
        int y = top.second;
        r1 = dfs(x, y, mat, vis, 1);
        if(r1) break;
    }
    while(!qc.empty()){
        auto top = qc.front();
        qr.pop();
        int x = top.first;
        int y = top.second;
        c2 = dfs(x, y, mat, vis, 2);
        if(c2) break;
    }
    if(r1 and c2){
        cout << "AMBIGUOUS\n";
    }
    else if(r1){
        cout << 1 << "\n";
    }
    else if(c2){
        cout << 2 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}