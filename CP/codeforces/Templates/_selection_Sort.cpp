#include <bits/stdc++.h>
using namespace std;

void _selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++){
            if(arr[min] > arr[j]){
                min 
            }
        }
    }
}

void _print(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 5, 2, 6, 3, 7, 9, 10, 23, 12, 11, 0};
    _print(arr);
    _selection_sort(arr);
    _print(arr);
    return 0;
}