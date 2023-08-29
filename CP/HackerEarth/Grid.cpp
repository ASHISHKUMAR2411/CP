// #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// //#define USE_INPUT_FILE 1

// typedef pair<int, int> POS;

// char WALL = '*';
// char EMPTY = 'O';

// char G[1001][1001];
// vector<vector<int>> costs;
// vector<vector<bool>> visited;

// int R, C, Q;

// POS SP, EP;

// // struct Cell {
// //     POS pos;
// //     int cost;
// //     Cell() {}
// //     Cell(POS _pos, int _cost) : pos(_pos), cost(_cost) {}
// // }

// int dr[4] = {1, -1, 0, 0};
// int dc[4] = {0, 0, 1, -1};
 
// void calculatedCost()
// {
//     queue<POS> q;
 
//     costs[SP.first][SP.second] = 0;
//     q.push(SP);
 
//     // POS cPos;
 
//     while (!q.empty())
//     {
//         queue<POS> temp;
 
//         while (!q.empty())
//         {
//             POS cPos = q.front();
//             q.pop();
 
//             // if (visited[cPos.first][cPos.second])
//             //     continue;
//             visited[cPos.first][cPos.second] = true;
 
//             for (int i = 0; i < 4; i++)
//             {
//                 int nr = dr[i] + cPos.first;
//                 int nc = dc[i] + cPos.second;
 
//                 if (nr < 0 || nc < 0 || nr >= R || nc >= C)
//                 {
//                     continue;
//                 }
 
//                 if (visited[nr][nc])
//                 {
//                     continue;
//                 }
 
//                 visited[nr][nc] = true;
 
//                 if (G[nr][nc] == WALL)
//                 {
//                     costs[nr][nc] = -1;
//                     continue;
//                 }
 
//                 costs[nr][nc] = costs[cPos.first][cPos.second] + 1;
 
//                 temp.push(POS(nr, nc));
//             }
//         }
 
//         q = temp;
//         temp = queue<POS>();
//     }
// }
 
// void solution()
// {
//     cin >> R >> C >> Q;
//     for (int r = 0; r < R; r++)
//     {
//         costs.push_back(vector<int>(C, -1));
//         visited.push_back(vector<bool>(C, false));
//         cin >> G[r];
//     }
 
//     int vr, vc;
//     cin >> vr >> vc;
//     SP = POS(vr - 1, vc - 1);
 
//     calculatedCost();
 
//     while (Q-- > 0)
//     {
//         cin >> vr >> vc;
//         EP = POS(vr - 1, vc - 1);
//         cout << costs[EP.first][EP.second] << "\n";
//     }
// }
 
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
// #ifdef USE_INPUT_FILE
//     freopen("input.txt", "r", stdin);
// #endif
 
//     solution();
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '*') dist[i][j] = -1;
        }
    }
    int si, sj;
    cin >> si >> sj;
    si--;
    sj--;
    dist[si][sj] = 0;
    queue<vector<int>> pq;
    pq.push({si, sj});
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    vis[si][sj] = true;
    while(!pq.empty()){
        int size = pq.size();
        for(int k = 0; k < size; k++){
            auto top = pq.front();
            pq.pop();
            for(int i = 0; i < 4; i++){
                int x = top[0] + dx[i];
                int y = top[1] + dy[i];
                if(x < 0 or y < 0 or x >= n or y >= m or mat[x][y] == '*' or dist[x][y] < (top[0] + 1) or vis[x][y]) continue;
                vis[x][y] = true;
                dist[x][y] = top[0] + 1;
                pq.push({dist[x][y], x, y});
            }
        }
    }
    for(int i = 0; i < q; i++){
        int di, dj;
        cin >> di >> dj;
        di--;
        dj--;
        dist[di][dj] = dist[di][dj] == 1e9 ? -1 : dist[di][dj];
        cout << dist[di][dj] << "\n";
    }
}