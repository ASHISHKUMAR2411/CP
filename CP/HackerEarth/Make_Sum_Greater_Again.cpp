#include<bits/sdtc++.h>
using namespace std;

int solve(){
    if(index >= n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        if(sum >= k) return count;
        else return 1e8;
    }
    int ntake = solve();
    int min1 = INT_MAX, min2 = INT_MAX;
    a[index] = -a[index];
    if(index > 0){
        a[index - 1] = -a[index - 1];
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k; 
        cin >> n >> k;
        vector<int> a(n);
        for(int i= 0; i < n; i++){
            cin >> a[i];
        }
        // condition 
        int abs_sum = 0, neg = 0, smallest = INT_MAX, actual_sum = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < 0) {
                neg++;
            }
            actual_sum += a[i];
            abs_sum += abs(a[i]);
            smallest = min(smallest , abs(a[i]));
        }
        if(abs_sum < k){
            cout << -1 << endl;
            continue;
        }
        if(neg%2 and (abs_sum - 2*smallest) < k){
            cout << -1 << endl;
            continue;
        }
        if(actual_sum >= k){
            cout << 0 << endl;
            continue;
        }


    }
}


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n, k; 
//         cin >> n >> k;
//         int a[n];
//         for(int i= 0; i < n; i++){
//             cin >> a[i];
//         }
//         // condition 
//         int abs_sum = 0, neg = 0, smallest = INT_MAX, actual_sum = 0;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for(int i = 0; i < n; i++){
//             if(a[i] < 0) {
//                 neg++;
//                 pq.push({a[i], i});
//             }
//             actual_sum += a[i];
//             abs_sum += abs(a[i]);
//             smallest = min(smallest , abs(a[i]));
//         }
//         if(abs_sum < k){
//             cout << -1 << endl;
//             continue;
//         }
//         if(neg%2 and (abs_sum - 2*smallest) < k){
//             cout << -1 << endl;
//             continue;
//         }
//         if(actual_sum >= k){
//             cout << 0 << endl;
//             continue;
//         }
//         int count = 0;
//         while(!pq.empty() and actual_sum < k){
//             auto top = pq.top();
//             pq.pop();
//             int val = top.first;
//             int index = top.second;
//             if(a[index] == val){
//                 count++;
//                 a[index] = -a[index];
//                 int min1 = INT_MAX, min2 = INT_MAX;
//                 if(index > 0){
//                     min1 = a[index - 1];
//                 }
//                 if(index < n-1){
//                     min2 = a[index + 1];
//                 }
//                 int mini = min(min1, min2);
//                 int curr_sum = actual_sum + 2 * a[index] - 2 * mini;
//                 if(actual_sum < curr_sum){
//                     actual_sum = curr_sum;
//                     if(mini == min1 and index > 0){
//                         a[index - 1] = -a[index - 1];
//                         if(a[index - 1] < 0)
//                             pq.push({a[index - 1], index - 1});
//                     }
//                     if(mini == min2 and index < n-1){
//                         a[index + 1] = -a[index + 1];
//                         if(a[index + 1] < 0)
//                             pq.push({a[index + 1], index + 1});
//                     }
//                 }
//             }
//         }
//         cout << count << "\n";

//     }
// }