#include<bits/stdc++.h>
using namespace std;
int solve(int index, int &x, int arr[], int n, unordered_map<string, int> &dp){
    if(index >= n){
        int ans = 0;
        for(int i  = 1; i < n; i++){
            ans += abs(arr[i] - arr[i-1]);
        }
        return ans;
    }
    string s = to_string(index) + " ";
    for(int i = 0; i < n; i++){
        s += to_string(arr[i]) + " ";
    }
    if(dp.find(s) != dp.end()) return dp[s];
    int ntake = solve(index + 1, x, arr, n, dp);
    arr[index] = arr[index] ^ x;
    int take = solve(index + 1, x, arr, n, dp);
    return dp[s] = max(take, ntake);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        unordered_map<string, int > dp;
        int ans = solve(0, x, arr, n, dp);
        cout << ans << "\n";

        // for(int i = 1; i < n; i++){
        //     if(arr[i] == x){
        //         arr[i] ^= x;
        //         if(arr[i-1] < x){
        //             arr[i-1] ^= x;
        //         }
        //         if(i + 1 < n and arr[i+1] < x){
        //             arr[i+1] ^= x;
        //         }
        //         i+=2;
        //     }
        // }
        // int ans = 0;
        // for(int i = 1; i < n; i++){
        //     ans += abs(arr[i] - arr[i-1]);
        // }
        // cout << ans << "\n";
    }
}