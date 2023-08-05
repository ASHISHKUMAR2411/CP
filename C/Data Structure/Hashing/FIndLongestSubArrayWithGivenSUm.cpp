// Longest Subarray with given sum.
#include <bits/stdc++.h>
using namespace std;
int LongestSubArrayWithGivenSum(vector<int> &arr, int sum)
{
    unordered_map<int, int> set;
    int prefix_sum = 0, res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == sum)
        {
            res = max(res, i + 1);
        }
        if (set.find(prefix_sum) == set.end())
        {
            set.insert({prefix_sum, i});
        }
        if (set.find(prefix_sum - sum) != set.end())
            res = max(res, i - set[prefix_sum - sum]);
    }
    return res;
}
int main()
{
    // vector<int> arr{5,8,-4,-4,9, -2,-2}; sum = 0
    // vector<int> arr{3, 1, 0, 1, 8, 2, 3, 6}; sum = 5
    vector<int> arr{8, 3, 7};
    cout << " Longes subarray of size is : " << LongestSubArrayWithGivenSum(arr, 15);
    return 0;
}