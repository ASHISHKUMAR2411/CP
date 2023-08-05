#include<bits/stdc++.h>
using namespace std;
bool CheckSumKConsecutive(int arr[], int n, int k, int sum)
{
    int curr_sum = 0;
    for(int i = 0; i < k; i++)
        curr_sum += arr[i];
    if(curr_sum == sum)
        return true;
    for(int i = k; i < n; i++)
    {
        curr_sum = curr_sum + arr[i] - arr[i - k];
        if(curr_sum == sum)
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 20, -3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int sum = 27;
    if(CheckSumKConsecutive(arr, n, k, sum))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
