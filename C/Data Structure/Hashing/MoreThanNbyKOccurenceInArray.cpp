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
    cout << "\n\n" << k;
    FindOccurrence(arr, k);
    return 0;
}