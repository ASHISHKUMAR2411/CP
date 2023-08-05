// For finding the leader of the array
#include <bits/stdc++.h>
using namespace std;

void LeaderOfArray(int arr[], int n){
    // O(n*n) time complexity
    int j = 0;
    for(int i = 0 ; i < n ; i++){
        j = i+1;
        while(j<n){
            if(arr[i] > arr[j]){
                j++;
            }
            else{
                break;
            }
        }
        if(j == n){
            cout<<arr[i]<<" ";
        }
    }
}

void LeaderOfArray2(int arr[], int n){
    // In O(n) time complexity in ans in reverse order
    int j = n-1 ;
    cout<<arr[j]<<" ";
    for (int i = n - 2; i >= 0; i--)
    {
        if(arr[i] > arr[j]){
            j = i;
            cout<<arr[j]<<" ";
        }
    }
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 8 , 1, 2 , 5 ,6 ,4 , 3, 7, 8, 2, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    LeaderOfArray2(arr,n);
    return 0;
}