#include<bits/stdc++.h>
using namespace std;
int main(){
    int r, c, ci, cj;
    cin >> r >> c >> ci >> cj;
    int arr[r][c];
    memset(arr, -1, sizeof(arr));
    queue<pair<int, pair<int,int>>> q;
    q.push({0, {ci, cj}});
    // -1,-1 -1,0 -1,1
    // 0,-1  0, 0  0, 1
    // 1, -1 1, 0, 1, 1
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    arr[ci][cj] = 0;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int d = top.first;
            int x = top.second.first + dx[i];
            int y = top.second.second + dy[i];
            if(x < 0 or y < 0 or x >= r or y >= c or arr[x][y] != -1) continue;
            arr[x][y] = d + 1;
            q.push({d + 1, {x, y}});
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}