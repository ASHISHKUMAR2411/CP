#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> cost(10, 0), actualCost(10, 1e9);
        for(int i = 0; i < 10; i++){
            cin >> cost[i];
        }
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag = true;
        // while(flag){
        //     flag = false;
            for(int i = 0; i <= 9; i++){
                for(int j = i; j <= 9; j++){
                    int num = (i + j)%10;
                    if(cost[num] > (cost[i] + cost[j])){
                        cost[num] = cost[i] + cost[j];
                        flag = true;
                    }
                }
            }
        // }
        // for(auto it : cost){
        //     cout << it << " ";
        // }
        // cout << endl;
        int ans = 0;
        for(int i= 0; i < n; i++){
            ans += cost[s[i] - '0'];
        }
        cout << ans << endl;
    }
}