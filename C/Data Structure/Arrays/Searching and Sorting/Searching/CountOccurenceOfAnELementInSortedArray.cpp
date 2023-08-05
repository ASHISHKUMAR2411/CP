// Count occurrence of an element in the sorted array
#include<bits/stdc++.h>
using namespace std;
int FindLastOccurrence(int arr[], int n, int ele){
    int low = 0, mid = 0, high = n - 1;
    while(low<=high){
        mid = low + (high - low)/2;
        if(arr[mid] == ele){
            if(mid == n-1 || arr[mid+1] != ele)
                return mid;
            else
                low = mid + 1;
        }
        else if(arr[mid] > ele)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int FindFirstOccurrence(int arr[], int n, int ele){
    int low = 0, mid = 0, high = n - 1;
    while(low<=high){
        mid = high - (high - low)/2;
        if(arr[mid] == ele){
            if(mid == 0 || arr[mid-1] != ele)
                return mid;
            else
                high = mid - 1;
        }
        else if(arr[mid] > ele)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int FindCountOfOccurrence(int arr[], int n, int ele){
    int first = FindFirstOccurrence(arr, n, ele);
    if(first == -1)
        return 0;
    int last = FindLastOccurrence(arr, n, ele);
    return last - first + 1;
}
int main() {
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = 3;
    int count = FindCountOfOccurrence(arr, n, ele);
    cout << "Count of " << ele << " is " << count;
    return 0;
}