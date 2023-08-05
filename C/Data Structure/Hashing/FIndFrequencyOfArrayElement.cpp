// Find the frequency of array elements
#include <bits/stdc++.h>
using namespace std;
void FindFrequencyOfDistinctElement(vector<int> &arr)
{
    unordered_map<int, int> map;
    for (int i : arr)
    {
        map[i]++;
    }
    for (auto i : map)
    {
        cout << "(" << i.first << "," << i.second << ")" << endl;
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
        arr.push_back(rand() % 25);
    }
    for (int i : arr)
    {
        cout << "->" << i;
    }
    cout << "\n";
    FindFrequencyOfDistinctElement(arr);
    return 0;
}