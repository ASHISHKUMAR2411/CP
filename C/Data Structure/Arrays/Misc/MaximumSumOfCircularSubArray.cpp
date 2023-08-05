#include <bits/stdc++.h>
using namespace std;
int SumCircularSubArray(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int max_sum = arr[i];
        int curr_sum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int k = (i + j) % n;
            curr_sum += arr[k];
            max_sum = max(max_sum, curr_sum);
        }
        res = max(res, max_sum);
    }
    return res;
}

int MaxSumSubArray2(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxEnding = max(arr[i], maxEnding + arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int SumCircularSubArray2(int arr[], int n)
{
    int max_normal = MaxSumSubArray2(arr, n);
    if(max_normal < 0)
        return max_normal;
    int arr_sum = 0;
    for (int i = 0; i < n;i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + MaxSumSubArray2(arr, n);
    return max(max_normal, max_circular);
}

int main()
{
    int arr[] = {1, -2, 3, -4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << SumCircularSubArray(arr, n);
    return 0;
}