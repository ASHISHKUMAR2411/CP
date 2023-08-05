// finding the element in the infinite array 
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low , int high){
    int mid = 0;
    while(low<=high){
        mid = low + (high - low)/2;
        if(arr[mid] == ele)
            return mid;
        else if(arr[i]>ele)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int FindPositionOfTheElementInInfiniteArray(int arr[], int ele){
    if(arr[0] == ele) return 0;
    int i = 1;
    while(true){
        i = i * i;
        if(arr[i] == ele)
            return i;
        else if(arr[i]> ele)
            break;
        i++;
    }
    return binarySearch(arr, i / 2 + 1, i - 1);
}
int main(){
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = 3;
    int pos = FindPositionOfTheElementInInfiniteArray(arr, ele);
    if(pos == -1)
        cout << "Element not found";
    else
        cout << "Element found at position " << pos;
    // cout << "Position of " << ele << " is " << pos;
    return 0;
}