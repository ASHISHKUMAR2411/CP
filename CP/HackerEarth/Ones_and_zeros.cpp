#include<bits/stdc++.h>
using namespace std;
string find_multiple(int n){
    if(n == 1){
        return "1";
    }
    vector<string> dp(n);
    dp[1] = "1";
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int top = que.front();
        que.pop();
        if(top == 0){
            return dp[0];
        }
        for(auto it : {0, 1}){
            int new_d = (top * 10 + it)%n;
            if(dp[new_d].empty()){
                que.push(new_d);
                dp[new_d] = dp[top] + char('0' + it);
            }
        }
    }
    return "NOTPOSSIBLE";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        cout << find_multiple(n) << endl;
    }
    return 0;
}