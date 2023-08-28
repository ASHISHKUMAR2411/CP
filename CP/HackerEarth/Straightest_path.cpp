#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    int sx, sy;
    int ax, ay;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 'V') sx = i, sy = j;
            if(matrix[i][j] == 'H') ax = i, ay = j;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << sx << " " << sy << endl;
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> > pq;
    pq.push({0, sx, sy, -1, -1});
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    int ans = -1;
    vector<vector<int>> change(n, vector<int>(m, INT_MAX));
    change[sx][sy] = 0;
    // int check = 0;
    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        // check++;
        cout << tp[0] << ":" << tp[1] << " "<< tp[2] << "\n";
        // if(check >= 1e4) break;
        int dir = tp[0];
        int u = tp[1], v = tp[2], pu = tp[3], pv = tp[4];
        for(int i = 0; i < 4; i++ ){
            int x = u + dx[i];
            int y = v + dy[i];
            if(x < 0 or y < 0 or x >= n or y >= m or matrix[x][y] == '*') continue;
            if(pu == x and pv == y) continue;
            if(pu != -1 and pv != -1){
                if(pu == x or pv == y){
                    if(change[x][y] > dir){
                        change[x][y] = dir;
                        pq.push({dir, x, y, u, v});
                    }
                }
                else{
                    if(change[x][y] >= dir + 1){
                        change[x][y] = dir + 1;
                        pq.push({dir + 1, x, y, u, v});
                    }
                }
            }
            else{
                if(change[x][y] > dir){
                    change[x][y] = dir;
                    pq.push({dir, x, y, u, v});
                }
            }
        }
    }
    if(change[ax][ay] == INT_MAX) cout << -1 << "\n";
    else cout << change[ax][ay] << "\n";
}
