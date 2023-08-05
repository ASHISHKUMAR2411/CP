#include<bits/stdc++.h>
using namespace std;
int MaximumDifferenceInArray(int arr[] , int n){
    // O(n*n) time complexity
    int max_diff = INT_MIN , diff;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n;j++){
            diff = arr[j] - arr[i];
            if(diff > max_diff)
                max_diff = diff;
        }
    }
    return max_diff;
}
// maximum difference in array where j>i arr[j] - arr[i] is maximum
int MaximumDifferenceInArray2(int arr[] , int n){
    int res = arr[1] - arr[0] , minVal = arr[0];
    for (int i = 1; i < n; i++){
        res = max(res , arr[i] - minVal);
        minVal = min(minVal, arr[i]);
    }
    return res;
}



int main()
{
    int arr[] = {1,2,3,4,5 , 10 , 4, 1 , 4 , -1 , -20 , 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum difference is " << MaximumDifferenceInArray(arr, n);
    return 0;
}