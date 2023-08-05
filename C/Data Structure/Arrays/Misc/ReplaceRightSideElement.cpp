#include<bits/stdc++.h>
using namespace std;
// Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1

void replaceRightSideElement(int arr[], int n)
{
    if(n == 1)
    {
        arr[0] = -1;
        return;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            k = i;
    int max_element = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_element)
            max_element = arr[i];
        arr[i] = max_element;
    }
    arr[n - 2] = arr[n - 1];
    arr[n - 1] = -1;
}

int main()
{
    int arr[] = {17,2,4,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    replaceRightSideElement(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}