#include <bits/stdc++.h>
using namespace std;

void _insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i  < n; i++){
        int temp = arr[i];
        int j = i - 1; 
        while(j >= 0 and arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; 
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
    _insertion_sort(arr);
    _print(arr);
    return 0;
}