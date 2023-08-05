// CheckIfGivenArrayDividedIntoThreeSubArrayWithEqualSum
#include<bits/stdc++.h>
using namespace std;
bool CheckArrayDividedIntoThreeSubArrayWithEqualSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 3 != 0)
        return false;
    int target = sum / 3;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum == target)
            curr_sum = 0;
    }
    if (curr_sum == 0)
        return true;
    return false;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (CheckArrayDividedIntoThreeSubArrayWithEqualSum(arr, n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}