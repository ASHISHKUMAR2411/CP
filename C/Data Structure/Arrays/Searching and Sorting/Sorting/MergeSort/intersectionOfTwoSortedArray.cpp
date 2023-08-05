// Given two sorted array find the distinct intersection of the two array.
#include<bits/stdc++.h>
using namespace std;
void PrintIntersection(int arr1[], int arr2[], int n1, int n2){
    int i = 0, j = 0;
    while(i<n1 && j < n2){
        if(i>0 && arr1[i] == arr[i-1]) {
            i++;
            continue;
        }
        if( arr1[i] > arr2[j] )
            j++;
        else if(arr1[i] < arr2[j])
            i++;
        else{
            cout << arr1[i] << " ";
            i++;
            j++;
        }
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
        PrintIntersection(arr1, arr2, n1, n2);
    }
    return 0;
}