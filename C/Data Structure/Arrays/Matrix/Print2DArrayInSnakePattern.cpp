#include <bits/stdc++.h>
using namespace std;
void printSnakePattern(vector<vector<int>> &arr)
{
    cout << "\n"
         << "------------------------------"
         << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2)
        {
            for (int j = arr[i].size() - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        else
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
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
    int n = rand() % 10, m = rand() % 10;
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
    printSnakePattern(arr);
    return 0;
}