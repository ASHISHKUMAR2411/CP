// In this array we are going to print the two array in sorted form 
#include<bits/stdc++.h>
using namespace std;
void printTwoSortedArray(int arr1[], int arr2[], int n1, int n2){
    int i = 0, j = 0;
    while(i<n1 && j < n2){
        if(arr1[i] < arr2[j]){
            cout << arr1[i] << " ";
            i++;
        }
        else{
            cout << arr2[j] << " ";
            j++;
        }
    }
    while(i < n1){
        cout << arr1[i] << " ";
        i++;
    }
    while(j < n2){
        cout << arr2[j] << " ";
        j++;
    }
}
int main(){
    int t, n1, n2;
    cin >> t;
    while(t--){
        cin >> n1 >> n2;
        int arr1[n1], arr2[n2];
        for(int i = 0; i < n1; i++){
            cin >> arr1[i];
        }
        for(int i = 0; i < n2; i++){
            cin >> arr2[i];
        }
        sort(arr1, arr1+n1);
        sort(arr2, arr2+n2);
        printTwoSortedArray(arr1, arr2, n1, n2);
    }
    return 0;
}