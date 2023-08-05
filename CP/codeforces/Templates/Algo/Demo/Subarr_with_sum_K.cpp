#include<bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin >> n; 
    int a[n];

    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }

    // prefix sum
    for (int i = 1; i < n; i++){
        a[i] += a[i - 1];
    }

    map<int, int> mp;
    mp[0]++;

    // the sum we are looking for
    int sum;
    cin >> sum;
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += mp[a[i] - sum];
        mp[a[i]]++;
    }
    cout << ans << endl;
}