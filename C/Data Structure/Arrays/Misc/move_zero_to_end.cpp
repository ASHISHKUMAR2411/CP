// Moving zeroes to the end of the array
#include<bits/stdc++.h>
using namespace std;
void Move_Zeroes(int arr[], int n){
    // O(n*n) time complexity
    for (int i = 0; i < n;i++){
        if(arr[i] == 0){
            for (int j = i; j < n-1; j++){
                arr[j] = arr[j+1];
            }
            arr[n-1] = 0;
        }
    }
}

void Move_Zeroes_2(int arr[], int n){
    // O(n*n) time complexity
    for(int i = 0; i < n-1; i++){
        if(arr[i] == 0){
            for (int j = i + 1; j< n; j++){
                if(arr[j] != 0){
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
}

void Move_Zeroes_3(int arr[], int n){
    // using O(n) time complexity and O(n) extra space
    int temp[n] , res = 0;
    for (int i = 0; i < n;i++){
        if(arr[i] != 0){
            temp[res++] = arr[i];
        }
    }
    while(res<n){
        temp[res++] = 0;
    }
    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

void Move_Zeroes_4(int arr[], int n){
    // using O(n) time complexity and O(1) extra space
    int i = 0, j = 0;
    while(j < n){
        if(arr[j] != 0){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}
int main(){
    int arr[] = {0,1,0,3,0,0,0,0,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    Move_Zeroes_2(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}