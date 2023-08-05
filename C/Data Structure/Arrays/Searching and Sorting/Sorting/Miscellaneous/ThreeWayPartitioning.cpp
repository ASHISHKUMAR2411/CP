// Using Dutch National Flag Algorithm to partition the array into three section where element equal to pivot are going to together and smaller on left of them and larger right of them order doesn't matter
#include <bits/stdc++.h>
using namespace std;
void PartitionIntoThree(int arr[], int n, int pivot){
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high && low <= high) {
        if(arr[mid] < pivot){
            swap(arr[mid], arr[low]);
            low++;
        }
        else if(arr[mid] > pivot){
            swap(arr[mid], arr[high]);
            high--;
        }
        else{
            mid++;
        }
    }
}
int main() {
    int arr[] = {1, 3, 2, 4, 5, 6, 7, 5, 4, 5, 5, 7, 8, 76, 6, 5, 45, 8, 9, 0, 5, 6, 4, 3, 56, 45, 6, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivot = 5;
    PartitionIntoThree(arr, n, pivot);
    for (int i = 0; i< n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}