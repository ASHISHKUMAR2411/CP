#include <bits/stdc++.h>
using namespace std;

// The idea behind Meet in the Middle is that, we divide the problem into two parts and then we solve them separately and then while merging the solution we find some optimal way to merge it so that it doesn't effect the time complexity, check while merging we have to apply the cross product, if it out of bound of our time, then find some other way to merge it, like binary search on other and iteration on other. 



vector<int> solve_subset(vector<int> &arr, int n){
    vector<int> ans;
    for (int i = 0; i < (1 << n); i++){
        int sub_sum = 0;
        for (int j = 0; j < n; j++){
            if(i & ( 1 << j)){
                sub_sum += arr[j];
            }
        }
        ans.push_back(sub_sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}


void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n, 0), a, b;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if(i&1){
            a.push_back(arr[i]);
        }
        else{
            b.push_back(arr[i]);
        }
    }
    vector<int> a_ = solve_subset(a, n / 2);
    vector<int> b_ = solve_subset(b, n - n / 2);
    int count = 0;
    for(int i = 0; i < a_.size(); i++){
        count += upper_bound(b_.begin(), b_.end(), x - a_[i]) - b_.begin();
    }
    cout << count << endl;
}

// You are given an array a consisting of n integers, and additionally an integer m. You have to choose some sequence of indices b1, b2, ..., bk (1 ≤ b1 < b2 < ... < bk ≤ n) in such a way that the value of (a[b1] + a[b2] + ... + a[bk]) mod m is maximized. The chosen sequence can be empty.

// Print the maximum possible value of(a[b1] + a[b2] + ... + a[bk]) mod m
//  n and m (1 ≤ n ≤ 35, 1 ≤ m ≤ 109), a1, a2, ..., an (1 ≤ ai ≤ 109)

// Intuition is that we can use the meet in the middle
// We can divide the whole array into two halfs, we can find all the possible permutations of the first half and find the sum and of those halfs and store it in a map using the modulo x, now we know that, we have those sum total possible values are 0 to m-1, 


void solve(){
    int n, m;
    cin >> n >> m;
    ll a[n];
    // taking input
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // now base case 
    if(n==1){
        cout << a[0] % m << endl;
        return;
    }
    int middle = (n + 1) / 2;
    vector<ll> sums;
    for (ll i = 0; i < (1ll << middle); i++){
        ll sum = 0;
        for (ll j = 0; j < mid; j++){
            if((1ll << j) & i){
                sum = (sum + a[j]) % m;
            }
        }
        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());
    ll ans = 0;
    for (ll i = 0; i < (1ll << n); i+=(1ll << mid)){
        if(ans == m-1)
            break;
        ll sum = 0;
        for (ll j = mid; j < n; j++){
            if((1ll<<j)&i){
                sum = (sum + a[j]) % m;
            }
        }
        ll need = (m - sum - 1 + m) % m;
        ll pos = upper_bound(sums.begin(), sums.end(), need) - sums.begin() - 1;
        if(pos < 0){
            pos = sums.size() - 1;
        }
        ans = max(ans, ((sum + sums[pos]) % m));
    }
    cout << ans << endl;
}

// You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
// 1 ≤ n ≤ 1000
// 1 ≤ x, ai ≤ 10^9

// using meet in the middle
void solve(){
    ll n, x;
    cin >> n >> x;
    ll a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mid = (n + 1) / 2;
    set<int> sums;
    for (int i = 0; i < mid; i++){
        for (int j = i + 1; j < mid; j++){
            sums.push_back(arr[i] + arr[j]);
        }
    }
    bool flag = true;
    for (int i = mid; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(s.find((x - arr[i] - arr[j])) != s.end()){
                flag = false;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    if(!flag)
        cout << "YES\n";
    else{
        cout << "NO\n";
    }
}

