// In this given unsorted array with positive element, check if there is a subarray with given sum.

#include<bits/stdc++.h>
using namespace std;
bool CheckSubArrayWithSum(int arr[], int n , int sum)
{
    // O(n*n) time complexity
    int cur_sum = 0;
    for (int i = 0; i< n; i++){
        cur_sum = 0;
        for(int j = i; j < n; j++){
            cur_sum += arr[j];
            if(cur_sum == sum){
                return true;
            }
        }
    }
    return false;
}

bool CheckSubArrayWithSum2(int arr[], int n , int sum)
{
    // O(n) time complexity
    int cur_sum = 0, start = 0;
    for (int i = 0; i< n; i++){
        cur_sum += arr[i];
        while(cur_sum > sum && start < i){
            cur_sum -= arr[start];
            start++;
        }
        if(cur_sum == sum){
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 33;
    if(CheckSubArrayWithSum(arr, n, sum)){
        cout << "Sum found";
    }
    else{
        cout << "Sum not found";
    }
    return 0;
}