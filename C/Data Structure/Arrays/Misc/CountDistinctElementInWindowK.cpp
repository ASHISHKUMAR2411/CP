#include<bits/stdc++.h>
using namespace std;
void countDistinctElementInWindowK(int arr[], int n, int k)
{
    // Uses O(n) time complexity and O(n) extra space
    vector<int> v;
    int i, j, count = 0;
    unordered_map<int, int> m;
    for (i = 0; i < k; i++)
    {
        if (m.find(arr[i]) == m.end())
            m[arr[i]] = 1;
        else
            m[arr[i]]++;
    }
    count = m.size();
    v.push_back(count);
    cout << count << " ";
    for (i = k; i < n; i++)
    {
        if (m.find(arr[i]) == m.end())
            m[arr[i]] = 1;
        else
            m[arr[i]]++;
        if (m.find(arr[i - k]) != m.end())
        {
            if (m[arr[i - k]] == 1)
                m.erase(arr[i - k]);
            else
                m[arr[i - k]]--;
        }
        count = m.size();
        v.push_back(count);
        cout << count << " ";
    }
}

int main()
{
    int arr[] = { 1, 2, 1, 3, 4, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    countDistinctElementInWindowK(arr, n, k);
    return 0;
}