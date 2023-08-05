#include<bits/stdc++.h>
using namespace std;
int MaxSumSubArray(int arr[], int n){
    int res = arr[0];
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += arr[j];
            res = max(res, sum);
        }
    }
    return res;
}

int MaxSumSubArray2(int arr[] , int n){
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++){
        maxEnding = max(arr[i], maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum contiguous sum is " << MaxSumSubArray(arr, n);
    return 0;
}