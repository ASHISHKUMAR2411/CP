#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// Question is : To find the maximum possible rectangle possible which is unattacked if we keep k brooks on a chess board of NXM grid, N, M <= 10^4 and K <= 10^5 
void solve(){
    long long n, m;
    cin >> n >> m;
    long long k;
    cin >> k;
    vector<long long> x(k + 1, 0), y(k + 1, 0);
    for (int i = 0; i < k; i++){
        long long xi, yi;
        cin >> xi >> yi;
        x[i + 1] = xi;
        y[i + 1] = yi;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 1; i <= k; i++){
        x[i] = abs(x[i] - x[i - 1] - 1);
        y[i] = abs(y[i] - y[i - 1] - 1);
    }
    long long x_ = *max_element(x.begin(), x.end());
    long long y_ = *max_element(y.begin(), y.end());
    // this is the maximum rectangle possible... 
    cout << (x_ * y_) << endl;
}

// There are k person in N X M grid, we need to find the minimum time needed to bring all person at one point, N,M,K <= 10^5, in one operation it takes one sec we can move one person one unit in all the direction,
// Always Remember : if  ⅀|x - xi| over n, then x will be median for sure, and if  ⅀|x - xi|^2 over n, then x will be average,

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> x_, y_;
    for (int i = 0; i < k; i++){
        ll x, y;
        cin >> x >> y;
        x_.push_back(x);
        y_.push_back(y);
    }
    sort(x_.begin(), x_.end());
    sort(y_.begin(), y_.end());

    ll median_x = x_[(x_.size() + 1) / 2];
    ll median_y = y_[(y_.size() + 1) / 2];

    ll sum_x = 0, sum_y = 0;
    for (int i = 0; i < x_.size(); i++){
        sum_x += abs(median_x - x_[i]);
        sum_y += abs(median_y - y_[i]);
    }
    cout << sum_x + sum_y << endl;

    // for (int i = 0; i < x_.size(); i++)
    // {
    //     x_[i] += x_[i - 1];
    //     y_[i] += y_[i - 1];
    // }
    // // before median
    // ll pos = (((x_.size() + 1) / 2));
    // ll before_median_x = pos * median_x - x_[pos];
    // ll before_median_y = pos * median_y - y_[pos];
    // // after median
    // ll after_median_x = x_[x_.size() - 1] - (x_.size() - pos + 1) * median_x;
    // ll after_median_y = y_[y_.size() - 1] - (y_.size() - pos + 1) * median_y;
    // cout << before_median_x + before_median_y + after_median_x + after_median_y << endl;
}

// Suppose We have given Q queries with different value of x and need to find  ⅀|x - xi| for all queries, 

void solve_(){
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 1; i < n; i++){
        a[i] += a[i - 1];
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++){
        ll x;
        cin >> x;
        // log n
        ll pos = lower_bound(b, b + n, x) - b;
        if(x != b[pos]){
            pos--;
        }
        // less value
        ll sum = (pos)*x - a[pos];
        // more value
        ll sum += (a[n - 1] - a[pos]) - x * pos;
        cout << sum << endl;
    }
}

// Given an binary array of n integers and k be the length of the continuous subarray you can flip and you have to find the minimum number of flips required to make it all 0, if not possible -1, 

void solutio(){
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> b(n, 0);
    int count = 0;
    for (int i = 0; i < n - k; i++){
        if(i){
            b[i] += b[i - 1];
            if(b[i]%2 and a[i] == 0){
                count++;
                if(i + 1 < n)
                    b[i + 1] += 1;
                if((i + k) < n)
                    b[i + k] -= 1;
            }
            if(b[i]%2 == 0 and a[i] == 1){
                count++;
                if (i + 1 < n)
                    b[i + 1] += 1;
                if ((i + k) < n)
                    b[i + k] -= 1;
            }
        }
        else{
            if(a[i] == 1){
                count++;
                b[i + 1] += 1;
                b[i + k] -= 1;
            }
        }
        for (int i = n - k; i < n; i++){
            b[i] += b[i - 1];
            if (b[i] % 2 and a[i] == 0)
            {
                cout << -1 << endl;
                continue;
            }
            if (b[i] % 2 == 0 and a[i] == 1)
            {
                cout << -1 << endl;
                continue;
            }
        }
        cout << count << endl;
    }
}




