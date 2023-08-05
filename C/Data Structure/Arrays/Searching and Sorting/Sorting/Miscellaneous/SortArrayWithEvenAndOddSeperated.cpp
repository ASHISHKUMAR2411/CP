// In this specific Problem we are given the array with random number we have to sort the array with even on one side and odds on the other side of the array
#include <bits/stdc++.h>
using namespace std;
// Using Hoare Algorithm
void PartitionOddEven(int arr[], int n){
    int i = -1, j = n;
    while(true){
        do{
            i++;
        } while (arr[i] % 2);
        do{
            j--;
        } while (arr[j] % 2 == 0);
        if(i>=j)
            return;
        swap(arr[i],arr[j]);
    }
}
int main() {
    int n = 25;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    PartitionOddEven(arr, n);
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}