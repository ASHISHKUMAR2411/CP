// equilibriumPoint
#include <iostream>
using namespace std;
bool isEquilibriumPoint(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int leftSum = 0;
    for(int i = 0; i < n; i++){
        if(leftSum == sum - arr[i]){
            return true;
        }
        leftSum += arr[i];
        sum -= arr[i];
    }
    return false;
}

int hasEquilibriumPoint(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int leftSum = 0;
    for(int i = 0; i < n; i++){
        if(leftSum == sum - arr[i]){
            return i;
        }
        leftSum += arr[i];
        sum -= arr[i];
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isEquilibriumPoint(arr, n)){
        cout << "Equilibrium point exists" << endl;
    }
    else{
        cout << "Equilibrium point does not exist" << endl;
    }
    int index = hasEquilibriumPoint(arr, n);
    if(index != -1){
        cout << "Equilibrium point exists at index " << index << endl;
    }
    else{
        cout << "Equilibrium point does not exist" << endl;
    }
    return 0;
}