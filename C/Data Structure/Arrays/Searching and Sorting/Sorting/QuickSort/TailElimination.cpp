// quick sort with tail elimination
#include<bits/stdc++.h>
using namespace std;
int Partition(int arr[], int low , int high){
    int pivot = arr[0];
    int i = -1, high = n;
    while(true){
        do{
            i++;
        } while (arr[i] < pivot);
        do{
            j--;
        } while (arr[j] > pivot);
        if(i>=j){
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
void QuickSort(int arr[], int low , int high){
    Here:
    if(low < high){
        int index = Partition(arr, low, high);
        QuickSort(arr, low, index);
        low = index + 1;
        goto Here;
    }
}