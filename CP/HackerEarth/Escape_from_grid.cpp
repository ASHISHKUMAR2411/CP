#include<bits/stdc++.h>

using namespace std;

int escape_from_grid(vector<vector<int> > grid) {
    // Write your code here
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    int n = grid.size();
    int m = grid[0].size();
    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                pq.push({0, {i, j}});
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int count = INT_MAX;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++){
            int x = t.second.first + dx[i];
            int y = t.second.second + dy[i];
            if(x >= n or y >= m or y < 0 or x < 0){
                count = min(count, t.first);
                continue;
            }
            else if(grid[x][y] == 0 and dist[x][y] > t.first + 1){
                dist[x][y] = t.first + 1;
                pq.push({dist[x][y], {x, y}});
                vis[x][y] = true;
            }
        }
    }
    if(count == INT_MAX) return -1;
    return count;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int grid_x;
    cin >> grid_x;
    int grid_y;
    cin >> grid_y;
    vector<vector<int> > grid(grid_x, vector<int>(grid_y));
    for (int i_grid = 0; i_grid < grid_x; i_grid++) {
        for (int j_grid = 0; j_grid < grid_y; j_grid++) {
            cin >> grid[i_grid][j_grid];
        }
    }

    int out_;
    out_ = escape_from_grid(grid);
    cout << out_;
}