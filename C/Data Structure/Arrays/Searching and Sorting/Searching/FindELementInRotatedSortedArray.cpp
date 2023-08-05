// Find element in the rotated sorted array
#include<bits/stdc++.h>
using namespace std;
int FindElementInSortedAndRotatedArray(int arr[], int n, int ele){
    int low = 0, high = n-1, mid = 0;
    while(low<=high){
        mid = low + (high - low) / 2;
        if(arr[mid] == ele)
            return mid;
        else if(arr[low] < arr[mid]){
            if(ele >= arr[low] && ele < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(ele > arr[mid] && ele <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {100, 200, 300, 400, 500, 10, 20, 30, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = 10;
    int index = FindElementInSortedAndRotatedArray(arr, n, ele);
    if(index == -1)
        cout << ele << " is not present in the array";
    else
        cout << ele << " is present at index " << index;
    return 0;
}