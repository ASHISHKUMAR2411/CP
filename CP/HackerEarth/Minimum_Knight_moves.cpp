#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b ;
        cin >> a >> b;
        int spx = a[0] - 'a' + 1, spy = a[1] - '0';
        int epx = b[0] - 'a' + 1, epy = b[1] - '0';
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {spx, spy}});
        int count = -1;
        int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
        vector<vector<bool>> vis(9, vector<bool>(9, false));
        vis[spx][spy] = true;
        // 8 X 8 Matrix
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x = top.second.first;
            int y = top.second.second;
            if(epx == x and epy == y){
                count = top.first;
                break;
            }
            for(int i = 0; i < 8; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ >= 9 or x_ < 1 or y_ >= 9 or y_ < 1 or vis[x_][y_]) continue;
                vis[x_][y_] = true;
                q.push({top.first + 1, {x_, y_}});
            }
        }
        cout << count << endl;
    }
    return 0;
}