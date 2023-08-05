// given two sorted array find the union of the two array.
#include<bits/stdc++.h>
using namespace std;
// O(m+n) time complexity
void PrintUnion(int arr1[], int arr2[], int n1, int n2){
    int i = 0, j = 0;
    while(i<n1 && j < n2){
        if(i>0 && arr1[i] == arr1[i-1]) {
            i++;
            continue;
        }
        if( arr1[i] > arr2[j] ){
            cout << arr2[j] << " ";
            j++;
        }
        else if(arr1[i] < arr2[j]){
            cout << arr1[i] << " ";
            i++;
        }
        else{
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    while(i < n1){
        if(i>0 && arr1[i] == arr1[i-1]) {
            i++;
            continue;
        }
        cout << arr1[i] << " ";
        i++;
    }
    while(j < n2){
        if(j>0 && arr2[j] == arr2[j-1]) {
            j++;
            continue;
        }
        cout << arr2[j] << " ";
        j++;
    }
    cout << "\n";
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
        PrintUnion(arr1, arr2, n1, n2);
    }
    return 0;
}