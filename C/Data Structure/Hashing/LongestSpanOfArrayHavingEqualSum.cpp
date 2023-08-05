// We are given binary array find the longest subarray which lies on the same span of both the array and have equal sum
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
int LongestSpanOfEqualSumInTwoBinaryArray(vector<int> &arr1, vector<int> &arr2){
    int sum = 0;
    // if you can modify the given array then we can do that otherwise create an temp array which contain the difference between the array
    // as both the array have the same size

    for (int i = 0; i < arr1.size(); i++){
        arr1[i] = arr1[i] - arr2[i];
    }

    // It a simple question of finding the longest subarray with given sum as zero
    return LongestSubArrayWithGivenSum(arr1, 0);
}

int main(){
    srand(time(0));
    int n = rand() % 100;
    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++){
        arr1.push_back(rand() % 2);
        arr2.push_back(rand() % 2);
    }
    cout << n << "\n";
    for(int i : arr1){
        cout << "->" << i;
    }
    cout << "\n";
    for(int i : arr2){
        cout << "->" << i;
    }
    cout << "\n";
    cout << "The Longest sum is : " << LongestSpanOfEqualSumInTwoBinaryArray(arr1, arr2);
}