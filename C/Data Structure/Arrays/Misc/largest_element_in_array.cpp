#include<bits/stdc++.h>
using namespace std;
int max_element(int arr[], int n)
{
    int i, max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int arr1[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Largest element is " << max_element(arr, n) << endl;
    cout << max({10, 20, 30, 40, 50}, compare) << endl;
    cout << *max_element(arr1, arr1 + n) << endl;
    return 0;
}

