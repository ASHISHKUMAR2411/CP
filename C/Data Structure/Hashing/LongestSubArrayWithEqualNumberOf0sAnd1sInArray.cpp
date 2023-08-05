// Longest Subarray with equal 0s and 1s
#include <bits/stdc++.h>
using namespace std;

// This question can be solved as array with given sum if we suppose the 0 -> -1 then the sum of the subarray with zeroes and ones equal then the sum is 0

// So keeping that in mind if we can can modify the original array then we can modify otherwise we can make it look like that

int LongestArrayWithEqualZeroesAndOnes(vector<int> &arr)
{
    int sum = 0, prefix_sum = 0, res = 0;
    unordered_map<int, int> map;

    // this step is optional
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == sum)
        {
            res = max(res, i + 1);
        }
        if (map.find(prefix_sum) == map.end())
        {
            map.insert({prefix_sum, i});
        }
        if (map.find(prefix_sum - sum) != map.end())
            res = max(res, i - map[prefix_sum - sum]);
    }
    return res;
}

int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand() % 25;
    cout << n <<"\n";
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 2);
    }
    for (int i : arr)
    {
        cout << "->" << i;
    }
    cout << "\n";
    cout << "Longest Size Subarray is " << LongestArrayWithEqualZeroesAndOnes(arr) << "\n";
    return 0;
}
