#include <bits/stdc++.h>
using namespace std;
void PrintBoundaryELement(vector<vector<int>> arr)
{
    int i = 0, j = 0;
    cout << "\n";
    for (i = 0; i < arr[0].size(); i++)
    {
        cout << arr[j][i] << " ";
    }
    for (j = 1, i -= 1; j < arr.size(); j++)
    {
        cout << arr[j][i] << " ";
    }
    if (arr.size() > 1 && arr[0].size() > 1)
    {

        for (j = arr[0].size() - 2, i = arr.size() - 1; j >= 0; j--)
        {
            cout << arr[i][j] << " ";
        }
        for (j = 0, i = arr.size() - 2; i > 0; i--)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
}

void print(vector<vector<int>> &arr)
{
    // this is not much cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    srand(time(0));
    vector<vector<int>> arr;
    int n = rand() % 10, m = 2;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(rand());
        }
        arr.push_back(v);
    }
    print(arr);
    PrintBoundaryELement(arr);
    return 0;
}