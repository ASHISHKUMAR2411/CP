#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isSorted(arr, n))
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";
    return 0;
}