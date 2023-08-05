// Quick Sort Using Hoare's algorithm 
#include<bits/stdc++.h>
using namespace std;
// O(n) time complexity and O(1) space complexity
int HoarePartition(int arr[], int low , int high){
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while(true){
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        } while (arr[j] > pivot);
        if(i>=j){
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
void QuickSort(int arr[], int low, int high){
    if(low < high){
        int index = HoarePartition(arr, low, high);
        QuickSort(arr, low, index);
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