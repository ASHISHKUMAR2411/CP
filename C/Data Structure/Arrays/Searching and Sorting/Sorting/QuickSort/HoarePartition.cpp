// Hoare partition algorithm
#include<bits/stdc++.h>
using namespace std;
// Uses O(n) time and O(1) space.
// Unstable Partition
// It does not fix the pivot position and by default the pivot element is 1st element.
int HoarePartition(int arr[], int n){
    int i = -1 , j = n, pivot = arr[0];
    while(true){
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i >= j){
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
int main() {
    int arr[] = {11, 2, 13, 4, 5, 16, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = HoarePartition(arr, n);
    cout << "The index of the pivot element is " << index << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}