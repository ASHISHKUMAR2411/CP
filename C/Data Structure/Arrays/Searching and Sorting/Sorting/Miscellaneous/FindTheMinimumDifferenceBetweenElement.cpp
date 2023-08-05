// Find the minimum difference between the element of the array
#include <bits/stdc++.h>
using namespace std;
int MinimumDifference(int arr[], int n)
{
    int res = INT_MAX;
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        res = min(res, abs(arr[i] - arr[i - 1]));
    }
    return res;
}
int main()
{
    int n = 25;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << MinimumDifference(arr, n);
    return 0;
}