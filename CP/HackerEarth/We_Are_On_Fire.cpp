#include<bits/stdc++.h>
using namespace std;
#define fastIO \
ios_base::sync_with_stdio(false); \
cin.tie(NULL); \
cout.precision(12);
int main(){
    fastIO;
    int n, m , q;
    cin >> n >> m >> q;
    int total = 0;
    queue<pair<int, int>> que;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                que.push({i, j});
                total++;
            }
        }
    }
    int c = 0;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    map<pair<int, int>, int> mp;
    unordered_map<int, int> keepCount;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if(!vis[x][y]){
            vis[x][y] = true;
            c++;
            queue<pair<int,int>> q;
            mp[{x,y}] = c;
            keepCount[c]++;
            q.push({x, y});
            while(!q.empty()){
                auto t = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int x_ = t.first + dx[i];
                    int y_ = t.second + dy[i];
                    if(x_ >= n or y_ >= m or x_ < 0 or y_ < 0 or arr[x_][y_] == 0 or vis[x_][y_]) continue;
                    vis[x_][y_] = true;
                    mp[{x_, y_}] = c;
                    keepCount[c]++;
                    q.push({x_, y_});
                }
            }
        }
    }
    vector<bool> visited(c + 1, false);
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(arr[u][v] == 0){
            cout << total << "\n";
        }
        else{
            if(mp.find({u, v}) != mp.end()){
                int c_ = mp[{u,v}];
                if(!visited[c_]){
                    visited[c_] = true;
                    total -= keepCount[c_];
                }
            }
            cout << total << "\n";
            arr[u][v] = 0;
        }
    }
}