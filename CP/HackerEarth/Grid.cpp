#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, q;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '*') dist[i][j] = -1;
        }
    }
    int si, sj;
    cin >> si >> sj;
    priority_queue<vector<int>> pq;
    pq.push({0, si, sj});
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    while(!pq.empty()){
        
    }
}