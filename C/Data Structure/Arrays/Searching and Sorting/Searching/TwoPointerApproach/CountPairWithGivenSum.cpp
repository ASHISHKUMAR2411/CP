// For finding the count of the pair of elements with given sum
#include <bits/stdc++.h>
using namespace std;
// if array is sorted then only Two Pointer approach 
int CountPairWithGivenSum(int arr[], int n, int sum)
{
    int low = 0, high = n-1 , sumPair = 0, count = 0;
    while(low<high){
        sumPair = arr[low]+arr[high];
        if(sumPair == sum)
            count++;
        else if(sumPair < sum)
            low++;
        else
            high--;
    }
    return count;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    cout << "Count of pair with given sum is " << CountPairWithGivenSum(arr, n, sum);
    return 0;
}