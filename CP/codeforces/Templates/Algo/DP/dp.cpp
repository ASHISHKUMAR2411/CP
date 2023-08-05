#include<bits/stdc++.h>
using namespace std;

// Partition Number
// Given N, find all natural number combinations whose sum is equal to N, don't consider permutation of the numbers whose sum is n, just count them as 1, like 2+1 or 1+2 is same, don't consider it different

void solve_dp_n(vector<int> &v, int i, int &count, int sum, int curr_sum){
    if(i >= v.size())
        return;
    if(curr_sum == sum){
        count++;
        return;
    }
    else if(curr_sum > sum){
        return;
    }
    solve_dp_n(v, i, count, sum, (curr_sum + v[i]));
    solve_dp_n(v, i + 1, count, sum, curr_sum);
}

void solve_sum_n(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++){
        v[i] = i + 1;
    }
    int count = 0; 
    solve_dp_n(v, 0, count, n, 0);
    cout << count << endl;
}


// Finding Maximum Sum Subsequence

vector<int> ans;
void solve_re_max(vector<int> &a, int index, int &sum, int curr_sum, vector<int> &arr){
    if(index >= a.size())
        return;
    solve_re_max(a, index + 1, sum, curr_sum, arr);
    if(sum <=( curr_sum + a[index])){
        ans = arr;
    }
    sum = max(sum, curr_sum + a[index]);
    arr.push_back(a[index]);
    solve_re_max(a, index + 1, sum, curr_sum + a[index], arr);
    arr.pop_back();
}
void solve_max(){
    vector<int> arr;
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = INT_MIN;
    solve_re_max(a, 0, sum, 0, arr);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Maximum Array Subarray

int solve_sub_max(vector<int> &a, int index, int &sum){
    if(index < 0)
        return 0;
    int curr_sum = a[index] + max(0, solve_sub_max(a, index - 1, sum));
    sum = max(curr_sum, sum);
    return curr_sum;
}

void solve_subarray()
{
    int n;
    cin >> n; 
    vector<int> a(n,0);
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    int sum = INT_MIN, curr_sum;
    solve_sub_max(a, n - 1, sum);
    cout << sum << endl;
}

int main(){
    solve_subarray();
    return 0;
}