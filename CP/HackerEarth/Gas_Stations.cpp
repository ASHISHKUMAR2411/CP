#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0){
            arr[i] += arr[i-1];
        }
    }
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    cout << pos + 1<< endl;

}