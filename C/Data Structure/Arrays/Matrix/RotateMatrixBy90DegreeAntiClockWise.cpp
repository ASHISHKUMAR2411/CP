// Rotating the matrix by 90 degree anti clockwise
#include <bits/stdc++.h>
using namespace std;
void RotateMatrixBy90Anti(vector<vector<int>> &arr)
{
    // transpose
    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr[i].size(); j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    // swap column
    for(int i = 0; i < arr.size()/2; i++){
        for(int j = 0; j < arr[i].size(); j++){
            swap(arr[i][j], arr[arr.size() - 1 - i][j]);
        }
    }
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
    int n = 5, m = n;
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
    RotateMatrixBy90Anti(arr);
    print(arr);
    return 0;
}