// Union of Two Unsorted Array
#include <bits/stdc++.h>
using namespace std;
void FindUnionOfArray(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> set;
    for (auto i : arr1)
    {
        set.insert(i);
    }
    for (auto i : arr2)
    {
        set.insert(i);
    }
    cout << endl;
    for (auto i : set)
    {
        cout << " " << i;
    }
}
int main()
{
    srand(time(0));
    vector<int> arr1;
    int n = rand() % 250;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr1.push_back(rand() % 25);
    }
    for (int i : arr1)
    {
        cout << "->" << i;
    }
    cout << "\n";
    vector<int> arr2;
    n = rand() % 250;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr2.push_back(rand() % 25);
    }
    for (int i : arr2)
    {
        cout << "->" << i;
    }
    cout << "\n";
    FindUnionOfArray(arr1, arr2);
    return 0;
}