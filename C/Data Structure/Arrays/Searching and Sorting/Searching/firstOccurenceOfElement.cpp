// for finding the first occurrence of an element in a sorted array
#include<bits/stdc++.h>
using namespace std;
int FindFirstOccurrence(int arr[], int n, int ele)
{
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
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = 3;
    int index = FindFirstOccurrence(arr, n, ele);
    if(index == -1)
        cout << "Element not found";
    else
        cout << "First occurrence of " << ele << " is at index " << index;
    return 0;
}