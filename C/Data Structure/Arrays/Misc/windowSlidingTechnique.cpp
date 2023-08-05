int MaxSumKConsecutive2(int arr[], int n, int k)
{
    // for O(n) time complexity
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
    {
        curr_sum += arr[i];
    }
    for (int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}