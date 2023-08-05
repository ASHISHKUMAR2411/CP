#include<bits/stdc++.h> 
using namespace std;
int main(){
    int t = 1;
    int n; 
    while(cin >> n){
        if(n == 0) break;
        int adj[n][n];
        int cost[n] = {0};
        int total = 0, red = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> adj[i][j];
                total += adj[i][j];
                cost[j] += adj[i][j];
                cost[i] -= adj[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            if(cost[i] > 0){
                red += cost[i];
            }
        }
        cout << t << ". " << total << " " << red << "\n";
        t++;
    }
}