#include<bits/stdc++.h>
using namespace std;
int MaxSumKConsecutive(int arr[], int n, int k){
    // for O(n*k) time complexity
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < i + k && j < n; j++)
            curr_sum += arr[j];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}
int MaxSumKConsecutive2(int arr[], int n, int k){
    // for O(n) time complexity
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < k; i++){
        curr_sum += arr[i];
    }
    for(int i = k; i < n; i++){
        curr_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << "Maximum sum of " << k << " consecutive elements in array is "<< MaxSumKConsecutive(arr, n, k) << endl;
    cout << "Maximum sum of " << k << " consecutive elements in array is "<< MaxSumKConsecutive2(arr, n, k) << endl;
    return 0;
}