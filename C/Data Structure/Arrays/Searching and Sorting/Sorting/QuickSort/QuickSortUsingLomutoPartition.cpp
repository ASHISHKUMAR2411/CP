// Quick sort using lomuto Partition
#include<bits/stdc++.h>
using namespace std;
// O(n) time complexity and O(1) space complexity
int LomutoPartition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void QuickSort(int arr[], int low, int high){
    if(low < high){
        int index = LomutoPartition(arr, low, high);
        QuickSort(arr, low, index - 1);
        QuickSort(arr, index + 1, high);
    }
}
int main(){
    int t, n;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while(t--){
        cout<<"Enter the number of elements of the array : ";
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        QuickSort(arr, 0, n - 1);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}