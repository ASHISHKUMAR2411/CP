#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<char>> &arr, int &n,vector<vector<bool>> &vis, int count, int &mn){
    if(arr[i][j] == 'E'){
        // cout << count << endl;
        mn = min(mn, count);
        return;
    }
    vis[i][j] = true;
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= n or y >= n or x < 0 or y < 0 or arr[x][y] == 'T' or vis[x][y]) continue;
        dfs(x, y, arr, n, vis, count + 1, mn);
    }
    vis[i][j] = false;
}
int main(){
    int n;
    cin >> n; 
    vector<vector<char>> arr(n, vector<char>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int x = -1, y = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'S'){
                x = i; y= j;
            }
        }
    }
    int count = INT_MAX;
    dfs(x, y, arr, n, vis, 0, count);
    cout << count << endl;
}