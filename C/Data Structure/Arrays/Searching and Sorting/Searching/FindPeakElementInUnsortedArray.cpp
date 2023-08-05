// Every Independent array has a peak element
// using binary search to find the peak element in the array
#include <bits/stdc++.h>
using namespace std;
int FindPeakElement(int arr[], int n)
{
    int low = 0, high = n - 1, mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            return mid;
        else if (mid > 0 && arr[mid] < arr[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pos = FindPeakElement(arr, n);
    if (pos == -1)
        cout << "Peak element not found";
    else
        cout << "Peak element found at position " << pos;
    return 0;
}