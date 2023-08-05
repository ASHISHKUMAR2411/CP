#include <bits/stdc++.h>
using namespace std;

int _partition(vector<int> &arr, int start, int end){
    int pivot = arr[start];
    int i = start;
    for (int j = i + 1; j <= end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[start]);
    return i;
}

void __quick_sort(vector<int> &arr, int start, int end){
    if(start >= end)
        return;
    int k = _partition(arr, start, end);
    __quick_sort(arr, start, k - 1);
    __quick_sort(arr, k + 1, end);
}

void _quick_sort(vector<int> &arr)
{
    __quick_sort(arr, 0, arr.size() - 1);
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
    _quick_sort(arr);
    _print(arr);
    return 0;
}