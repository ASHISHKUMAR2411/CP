#include<bits/stdc++.h>
using namespace std;
int dfs(int i, int j, int n, vector<vector<int>> &arr, vector<vector<bool>> &vis){
    if(i == n -1 and j == n-1){
        return 1;
    }
    int count = 0;
    vis[i][j] = true;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x < 0 or y < 0 or x >= n or y >= n or arr[x][y] or vis[x][y]) continue;
        count += dfs(x, y, n, arr, vis);
    }
    vis[i][j] = 0;
    return count;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        if(arr[n-1][n-1]){
            cout << 0 << "\n";
            continue;
        }
        int count = dfs(0, 0, n, arr, vis);
        cout << count << "\n";
    }
}