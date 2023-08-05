// Find Distinct ELement in Every Window
// Return the count
#include <bits/stdc++.h>
using namespace std;

// Using HashTable
void FindDistinctElement(vector<int> &arr, int k)
{
    if (k > arr.size())
        k = k % arr.size();
    cout << "\n"
         << k;
    int i = 0;
    unordered_map<int, int> set;
    for (int i = 0; i < k; i++)
    {
        set[arr[i]]++;
    }
    cout << "\n"
         << set.size();
    for (int i = k; i < arr.size(); i++)
    {
        set[arr[i - k]]--;
        if (set[arr[i - k]] == 0)
        {
            set.erase(arr[i - k]);
        }
        set[arr[i]]++;
        cout << " " << set.size();
    }
}

int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand() % 250;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100);
    }
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    int k = rand() % 100;
    cout << "\n\n"
         << k;
    FindDistinctElement(arr, k);
    return 0;
}