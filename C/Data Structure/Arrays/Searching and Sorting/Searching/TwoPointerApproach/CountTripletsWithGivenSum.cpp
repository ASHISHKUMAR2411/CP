// Finding the triplets with given sum with O(n^2) time doesn't matter whether array is sorted
#include <bits/stdc++.h>
using namespace std;
int CountPairWithGivenSum(int arr[], int low, int high, int sum)
{
    int  sumPair = 0, count = 0;
    while (low < high)
    {
        sumPair = arr[low] + arr[high];
        if (sumPair == sum)
            count++;
        else if (sumPair < sum)
            low++;
        else
            high--;
    }
    return count;
}
int CountTripletsWithGivenSum(int arr[], int n , int sum){
    int count = 0;
    for (int i = 0; i < n; i++){
        count += CountPairWithGivenSum(arr, i+1, n-1, sum - arr[i]);
    }
    return count;
}
int main(){
    // if array is not sorted sort the array first
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n);
    int sum = 10;
    cout << "Count of triplets with given sum is " << CountTripletsWithGivenSum(arr, n, sum);
    return 0;
}
