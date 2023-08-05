#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        queue<pair<int,int>> que;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> matrix[i][j];
                if(matrix[i][j]) que.push({i, j});
            }
        }
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        int maxi = 0;
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if(!vis[x][y]){
                count++;
                vis[x][y] = true;
                
                queue<pair<int,int>> q;
                int c = 0;
                q.push({x, y});
                while(!q.empty()){
                    c++;
                    auto top = q.front();
                    q.pop();
                    for(int i = 0; i < 8; i++){
                        int x_ = top.first + dx[i];
                        int y_ =  top.second + dy[i];
                        if(x_ >= n or x_ < 0 or y_ < 0 or y_ >= m or matrix[x_][y_] == 0 or vis[x_][y_]) continue;
                        vis[x_][y_] = true;
                        q.push({x_, y_});
                    }
                }
                maxi = max(maxi, c); 
            }
        }
        cout << count << " " << maxi << "\n";
    }
    return 0;
}