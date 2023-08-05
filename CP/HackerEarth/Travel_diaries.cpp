#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
    // queue<pair<int, pair<int, int>>> que;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                que.push({0, {i, j}});
            } 
        }
    }
    int count = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            int x = que.top().second.first; 
            int y = que.top().second.second;
            int dis = que.top().first;
            que.pop();
            count = dis;
            for(int i = 0; i < 4; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ >= n or y_ >= m or x_ < 0 or y_ < 0 or arr[x_][y_] == 0 or arr[x_][y_] == 2) continue;
                arr[x_][y_] = 2;
                que.push({dis + 1, {x_, y_}});
            }
        }
    }
    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                count = -1;
                flag = false;
                break;
            }
        }
        if(flag == false)break;
    }
    cout << count << endl;
}