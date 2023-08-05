// Find the median of the two sorted array and the combined array is also sorted.
#include <bits/stdc++.h>
using namespace std;

// O(n) time complexity
double FindMedianOfTwoSortedCombinedArray(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0, k = 0;
    int arr[n1 + n2];
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while (i < n1)
        arr[k++] = arr1[i++];
    while (j < n2)
        arr[k++] = arr2[j++];
    if (n1 + n2 % 2 == 0)
        return (double)(arr[n1 + n2 / 2 - 1] + arr[n1 + n2 / 2]) / 2.0;
    else
        return (double)(arr[n1 + n2 / 2]);
}

// In O(log(n1+n2)) time complexity
// Make sure that n1<=n2
double FindMedianOfTwoSortedCombinedArray2(int arr1[], int n1, int arr2[], int n2)
{
    int begin = 0, end = n1, i1, i2, max1, max2, min1, min2;
    while (begin <= end)
    {
        i1 = (begin + end) / 2;
        i2 = (n1 + n2 + 1) / 2 - i1;
        max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
        min1 = (i1 == n1) ? INT_MAX : arr1[i1];
        max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];
        min2 = (i2 == n2) ? INT_MAX : arr2[i2];
        if (max1 <= min2 && max2 <= min1)
            if (n1 + n2 % 2 == 0)
                return (double)(max(max1, max2) + min(min1, min2)) / 2.0;
            else
                return (double)(max(max1, max2));
        else if (max1 > min2)
            end = i1 - 1;
        else
            begin = i1 + 1;
    }
    return -1.0;
}
int main()
{
    int arr1 = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int arr2 = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    double median = 0.0;
    if (n1 > n2)
    {
        median = FindMedianOfTwoSortedCombinedArray2(arr2, n2, arr1, n1);
    }
    else
    {
        median = FindMedianOfTwoSortedCombinedArray2(arr1, n1, arr2, n2);
    }
    if (median == -1.0)
    {
        cout << "No median";
    }
    else
    {
        cout << "Median is " << median;
    }
    return 0;
}
