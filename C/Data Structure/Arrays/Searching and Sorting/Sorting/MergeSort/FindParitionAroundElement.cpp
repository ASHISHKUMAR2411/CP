// create the partition of the array around an element whose index is given 
#include<bits/stdc++.h>
using namespace std;
// Naive Solution O(nlog(n)) time complexity and O(1) auxiliary space complexity
// stability of element is not maintainable
void Partition(int arr[], int n, int index){
    sort(arr, arr + n);
}
// stability of element is not maintainable O(n) and O(1)
// void Partition(int arr[], int n, int index){
//     int i = 0, j = n-1;
//     while(i < j){
//         while(arr[i] < arr[index] && i < j){
//             i++;
//         }
//         while(arr[j] >= arr[index] && i < j){
//             j--;
//         }
//         if(i < j){
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[index], arr[j]);
// }
// O(n) time complexity and O(n) auxiliary space complexity
// With Stability of element
void Partition2(int arr[], int n, int index){
    vector<int> less, greater;
    for(int i = 0; i < n; i++){
        if(i !=index && arr[i] <= arr[index]){
            less.push_back(arr[i]);
        }
        else if(arr[i] > arr[index]){
            greater.push_back(arr[i]);
        }
    }
    less.push_back(arr[index]);
    for(int i = 0; i < less.size(); i++){
        arr[i] = less[i];
    }
    for(int i = 0; i < greater.size(); i++){
        arr[less.size() + i] = greater[i];
    }
}
// The O(n) time complexity and O(1) auxiliary space complexity
void LomutoPartition(int arr[], int n, int index)
{
    if (index != n - 1)
    {
        swap(arr[index], arr[n - 1]);
    }
    int i = -1, j = 0;
    while (j < n )
    {
        if (arr[j] < arr[n - 1])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[n - 1]);
}
// The O(n) time complexity and O(1) auxiliary space complexity
// Hoare Partition
// More likely than Lomuto partition but does not ensure the stability of the element and position of the pivot.
int HoarePartition(int arr[], int n){
    int i = -1 , j = n, pivot = arr[0];
    while(true){
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i >= j){
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
int main(){
    int arr[] = {1,20,13,40,6,15,6,0,6,2,3,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    LomutoPartition(arr, n, 6);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}