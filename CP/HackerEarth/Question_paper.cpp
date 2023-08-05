#include<bits/stdc++.h>
using namespace std;
void solve(int n, int a, int b, set<int> &ans, int sum){
    if(n == 0){
        ans.insert(sum);
        return;
    }
    if(ans.find(sum) != ans.end()){
        return;
    }
    solve(n - 1, a, b, ans, sum + a);
    solve(n - 1, a, b, ans, sum - b);
    solve(n - 1, a, b, ans, sum + 0);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        queue<pair<int,int>> que;
        int size = n * (a + b) + 4;
        vector<int> total(size , 0);
        int res = 1;
        int leastPossible = n * b + 1;
        que.push({0,0});
        total[leastPossible] = 1;
        while(!que.empty()){
            int q_no = que.front().first;
            int val = que.front().second;
            que.pop();
            if(q_no >= n) continue;
            int v1 = val + a;
            int v2 = val - b;
            if(total[leastPossible + v1]==0){
                res++;
                total[leastPossible + v1] = 1;
                que.push({q_no + 1, v1});
            }
            if(total[leastPossible + v2]==0){
                res++;
                total[leastPossible + v2] = 1;
                que.push({q_no + 1, v2});
            }
        }
        cout << res << "\n";
    }
}