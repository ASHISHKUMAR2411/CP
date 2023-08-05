// Print the spiral form of the a matrix
#include <bits/stdc++.h>
using namespace std;
void PrintSpiralForm(vector<vector<int>> &arr)
{
    int top = 0, bottom = arr.size() - 1, right = arr[0].size() - 1, left = 0;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;
        if(top<=bottom){
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }
        if(left<=right){
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
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
    PrintSpiralForm(arr);
    return 0;
}