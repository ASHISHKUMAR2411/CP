#include <bits/stdc++.h>
using namespace std;
void remove_duplicates(int arr[], int &n)
{
    // for unsorted array
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;
                j--;
            }
        }
    }
}

void remove_duplicates_2(int arr[] , int &n){
    // for sorted array with O(n) time and O(n) auxiliary space
    int temp[n], res = 0;
    temp[0] = arr[0];
    res++;
    for(int i = 1; i < n; i++){
        if(arr[i] != temp[res-1]){
            temp[res] = arr[i];
            res++;
        }
    }
    for(int i = 0; i < res; i++){
        arr[i] = temp[i];
    }
    n = res;
}

void remove_duplicates_3(int arr[], int &n){
    // for sorted array with O(n) time and O(1) auxiliary space
    int res = 1;
    for (int i = 1; i < n;i++){
        if(arr[i]!=arr[res-1]){
            arr[res] = arr[i];
            res++;
        }
    }
    n = res;
} 

int main()
{
    int arr[] = {1, 1, 2, 2, 3  , 4, 4, 4, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    remove_duplicates_3(arr, n);
    cout << "After removing duplicates: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
