// Range of l[] , r[] , find the maximum number which comes in the range
#include<bits/stdc++.h>
using namespace std;
int ElementAppearMaximum(int l[], int r[], int n){
    vector<int> v(1000,0);
    for (int i = 0; i < n;i++){
        v[l[i]]++;
        v[r[i]+1]--;
    }
    int max = v[0], res = 0;
    for (int i = 0; i < 1000; i++){
        v[i] += v[i-1];
        if(max < v[i]){
            max = v[i];
            res = i;
        }
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    int l[n], r[n];
    for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }
    cout << ElementAppearMaximum(l,r,n);
    return 0;
}