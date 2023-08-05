#include<bits/stdc++.h>
using namespace std;

void _bubble_sort(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        int flag = 0; 
        for (int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag){
            break;
        }
    }
}

void _print(vector<int> &arr){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl; 
}

int main(){
    vector<int> arr = {1, 5, 2, 6, 3, 7, 9, 10, 23, 12, 11, 0 };
    _print(arr);
    _bubble_sort(arr);
    _print(arr);
    return 0;
}