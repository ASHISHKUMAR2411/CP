#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int max_ = 1e7;
        int graph[n+1][n+1], dis[n+1][n+1];
        for(int i = 0; i <= n; i++){
            for(int j= 0; j <= n; j++){
                dis[i][j] = 1e7;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int ele;
                cin >> ele;
                graph[i][j] = ele;
            }
        }

        for(int i = 0; i <= n; i++){
            dis[i][i] = 0;
        }

        for(int k = 1; k  <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(graph[i][j] > (graph[i][k] + graph[k][j])){
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         // if(dis[i][j] < (dis[i][k] + dis[k][j])){
        //         //     dis[i][j] = dis[i][k] + dis[k][j];
        //         // }
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        set<pair<int,int>> st;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i!=j){
                int flag = false;
                for(int k = 1; k <= n; k++){
                    if(k != i and k != j)
                    if(graph[i][j] == (graph[i][k] + graph[k][j])){
                        flag = true;
                        break;
                    }
                }
                if(flag == false){
                    if(i < j){
                        st.insert({i, j});
                    }
                    else if(j < i){
                        st.insert({j, i});
                    }
                }
                }
            }
        }

        for(auto it : st){
            cout << it.first << " " << it.second << "\n";
        }




    }
}