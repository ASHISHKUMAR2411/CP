// To find the subarray with given sum
// Using hashing O(n) time and O(n) space complexity
#include <bits/stdc++.h>
using namespace std;
bool FindSubArrayWithGivenArray(vector<int> &arr, int sum)
{
    unordered_set<int> set;
    int pre_sum = 0;
    for (int i : arr)
    {
        pre_sum += i;
        if (pre_sum == sum)
        {
            return true;
        }
        if (set.find(pre_sum - sum) != set.end())
        {
            return true;
        }
        else
        {
            set.insert(pre_sum);
        }
    }
    return false;
}
int main()
{
    vector<int> arr{5, 8, 6, 13, 3, -1};
    if (FindSubArrayWithGivenArray(arr, 22))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}