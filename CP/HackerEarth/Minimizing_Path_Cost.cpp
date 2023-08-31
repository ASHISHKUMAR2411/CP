#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp[s] = i;
    }
    vector<vector<int>> dis(n, vector<int>(n, 1e9));
    for(int i = 0; i < m; i++){
        string s1, s2;
        int d;
        cin >> s1 >> s2  >> d;
        dis[mp[s1]][mp[s2]] = d;
        dis[mp[s2]][mp[s1]] = d;
    }
    for(int i = 0; i < n; i++){
        dis[i][i] = 0;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dis[i][j] > (dis[i][k] + dis[k][j])){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        string s1, s2;
        cin >> s1 >> s2;
        cout << dis[mp[s1]][mp[s2]] << endl;
    }

}