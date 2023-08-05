// Find the occurrence of the element which have element more then n/k.
#include <bits/stdc++.h>
using namespace std;
// This solution is good when we have Comparable n and k values
void FindOccurrence(vector<int> &arr, int k)
{
    unordered_map<int, int> map;
    for (int i : arr)
    {
        map[i]++;
    }
    cout << "\n"
         << k << "\n";
    for (auto i : map)
    {
        if (i.second > arr.size() / k)
        {
            cout << " " << i.first;
        }
    }
}
// Now finding the solution of the problem when k << n
// it takes O(n*k) time complexity and space complexity is O(k)
void FindOccurrence2(vector<int> &arr, int k)
{
    unordered_map<int, int> map;
    for (int i : arr)
    {
        if (map.find(i) != map.end() || map.size() < k - 1)
        {
            map[i]++;
        }
        else
        {
            for (auto j : map)
            {
                map[j.first]--;
                if (map[j.first] == 0)
                {
                    map.erase(j.first);
                }
            }
        }
    }
    cout << k << "\n";
    cout << " \n";
    for (auto i : map)
    {
        int count = 0;
        for (int j : arr)
        {
            if (i.first == j)
                count++;
        }
        if (count > arr.size() / k)
        {
            cout << " " << i.first;
        }
    }
}

int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand();
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << " " << arr[i];
    // }
    int k = rand();
    if (k > n)
        k = k % n;
    cout << "\n\n"
         << k;
    if (k < 20)
    {
        FindOccurrence2(arr, k);
    }
    else
        FindOccurrence(arr, k);
    return 0;
}