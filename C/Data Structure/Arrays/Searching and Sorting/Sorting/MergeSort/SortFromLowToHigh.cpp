// Given an array where index from low to mid are sorted and index mid+1 to high is sorted 
// we have to sort array from low to high.
#include<bits/stdc++.h>
using namespace std;
// here n = high - low + 1

// O(n*n) time complexity
void SortTheSortedPart(int arr[], int low,int mid , int high){
    int i = low , j = mid + 1, k = low;
    while(i<j && j <= high){
        if(arr[i]<= arr[j]){
            k++;
            i++;
        }
        else{
            int temp = arr[j];
            for(int l = j; l > k; l--){
                arr[l] = arr[l-1];
            }
            arr[k] = temp;
            j++;
            i++;
            k++;
        }
    }
}
// O(nlogn) time complexity
void SortTheSortedPart2(int arr[], int low , int mid , int high){
    sort(arr + low, arr + high + 1);
}

// O(n) time complexity and O(n) space complexity
void SortTheSortedPart3(int arr[], int low, int mid, int high){
    int arr1[high-low + 1];
    int i = low, j = mid + 1, k = 0;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            arr1[k] = arr[i];
            i++;
        }
        else{
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        arr1[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        arr1[k] = arr[j];
        j++;
        k++;
    }
    for(int l = 0; l < high-low + 1; l++){
        arr[low+l] = arr1[l];
    }
}

int main(){
    int arr[] = {2,3,4,5,6,7,8,9,0, 1,1,1,1,1,1,1,1,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    SortTheSortedPart3(arr, 0, 7, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
