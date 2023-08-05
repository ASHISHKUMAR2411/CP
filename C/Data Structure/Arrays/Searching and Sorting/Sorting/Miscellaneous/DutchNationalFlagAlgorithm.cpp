// Dutch National Flag Algorithm which is a variation of Hoare Algorithm  
#include<bits/stdc++.h>
using namespace std;
// solving a standard problem for this algorithm that is sorting the 0s together 1s together 2s together

void DutchNationalFlagAlgorithm(int arr[], int n){
    int low = 0, mid = 0, high = n - 1;
    int pivot = 1;
    while (mid <= high && low <= high)
    {
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
        }
        else if(arr[mid] == 2){
            swap(arr[high], arr[mid]);
            high--;
        }
        else{
            mid++;
        }
    }
}
int main(){
    int n = 25;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    DutchNationalFlagAlgorithm(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
