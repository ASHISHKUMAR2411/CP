// HerPrefix array sum
#include<bits/stdc++.h>
using namespace std;
int* prefixArraySum(int arr[], int n){
    int arrrSum[n];
    for(int i = 1; i<n;i++){
        arr[i] += arr[i - 1];
    }
    return arrSum;
}
int getsum(int arr[], int n, int l, int r){
    if(l==0) return arr[r];
    return arr[r] - arr[l-1];
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *arrSum = prefixArraySum(arr, n);
    cout<<getsum(arrSum, n, 2, 5);
    return 0;
}