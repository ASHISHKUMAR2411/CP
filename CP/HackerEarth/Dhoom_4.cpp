#include<bits/stdc++.h>
using namespace std;
int mod = 100000;
int solve(int index, int ini, int target, int arr[], int m){
    if(ini == target) return 0;
    if(index > m) return 1e7;
    int ntake = min(solve(index + 1, ini, target, arr, m), solve(index, ini, target, arr, m));
    ini = (ini%mod * arr[index]%mod)%mod;
    int take = 1 + min(solve(index + 1, ini, target, arr, m), solve(index, ini, target, arr, m));
    return min(take, ntake);
}
int main(){
    int ini , target;
    cin >> ini >> target;
    queue<pair<int,int>> que;
    int m;
    cin >> m;
    int arr[m+1];
    for(int i = 1; i <= m; i++){
        cin >> arr[i];
    }
    cout << solve(1, ini, target, arr, m) << endl;
    
    // int count = INT_MAX;
    // que.push({3, 0});
    // int index = 1;
    // while(!que.empty() and index <= m){
    //     int size = que.size();
    //     for(int i = 0; i < size; i++){
    //         auto top = que.front();
    //         que.pop();
    //         int val = top.first;
    //         int chances = top.second;
    //         if(val == target){
    //             count = min(count, chances);
    //         }
    //         int take = (val%mod * arr[index]%mod)%mod;
    //         int ntake = val;
    //         que.push({take, chances + 1});
    //         que.push({ntake, chances});
    //     }
    //     index++;
    // }
    // if(count == INT_MAX) cout << -1 << endl;
    // else
    // cout << count << endl;
    return 0;
}