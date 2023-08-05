#include<bits/stdc++.h>
using namespace std;
void LeftRotateArray1(int arr[], int n){
    int temp = arr[0];
    for(int i=0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void LeftRotateArray2(int arr[], int n, int d){
    // for O(n*d) time complexity
    d = d % n;
    for(int i=0; i<d; i++){
        LeftRotateArray1(arr, n);
    }
}

void LeftRotateArray3(int arr[], int n , int d){
    // for O(n) time complexity with O(n) space complexity
    d = d % n;
    int temp[n];
    for(int i = 0; i<n; i++){
        temp[(n - d + i)%n] = arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}

void LeftRotateArray4(int arr[], int n , int d){
    // for O(n) time complexity with O(d) space complexity
    d = d % n;
    int temp[d];
    for(int i = 0; i<d; i++){
        temp[i] = arr[i];
    }
    for(int i=d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i=0; i<d; i++){
        arr[n-d+i] = temp[i];
    }
}

void reverse(int a[] , int low , int high){
    while(low < high){
        swap(a[low] , a[high]);
        low++;
        high--;
    }
}

void LeftRotateArray5(int arr[], int n , int d){
    // for O(n) time complexity with O(1) space complexity
    d = d % n;
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}



int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    LeftRotateArray5(arr, n , 6 );
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
void LeftRotateArray6(int arr[], int n , int d){
    d = d % n;
    int temp[n];
    for(int i = 0; i<n; i++){
        // right rotation
        temp[(i + d)%n] = arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}