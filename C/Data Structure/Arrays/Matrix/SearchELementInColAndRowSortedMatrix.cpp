// Finding the element's position with respect to the matrix considering it start from (0,0) and finding relative position of the element if found otherwise return (-1,-1) the invalid index Which is not possible

// Given Matrix is sorted RowWise and ColumnWise which means that every A(i,j) ≤ A(i+1,j) ∈ i+1 < No. of rows , And ColumnWise sorted  i.e A(i,j) ≤ A(i,j+1) ∈ j+1 < No. of columns,

#include <bits/stdc++.h>
using namespace std;

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

pair<int, int> FindElementPosition(vector<vector<int>> &arr, int ele)
{
    int i = 0, j = arr[0].size()-1;
    while(i < arr.size() && j >= 0){
        if(arr[i][j] == ele)
            return {i, j};
        else if(arr[i][j] > ele)
            j--;
        else
            i++;
    }
    return {-1, -1};
}
int main()
{
    srand(time(0));
    vector<vector<int>> arr{{10, 20, 30, 40}, {15, 25, 35, 45}, {19, 29, 39, 49}, {27, 37, 47, 57}};
    print(arr);
    int ele = 29;
    cout << "Element is " << ele << endl;
    pair<int, int> pos = FindElementPosition(arr, ele);
    if (pos.first == -1)
        cout << "ELement Not Found" << endl;
    else
        cout << "Element found at (" << pos.first << " , " << pos.second <<")"<< endl;
    return 0;
}