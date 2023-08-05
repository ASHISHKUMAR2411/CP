// Repeating element is the element which appear in the array more than once 
#include<bits/stdc++.h>
using namespace std;

// if array contain element from 1 to n-1
int RepeatingElement(int arr[], int n){
    int slow = arr[0], fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    slow = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
// If array contains element from 0 to <=n-2
int RepeatingElement0(int arr[], int n){
    int slow = arr[0]+1, fast = arr[0]+1;
    do{
        slow = arr[slow]+1;
        fast = arr[arr[fast]+1]+1;
    }while(slow != fast);
    slow = arr[0]+1;
    while(slow != fast){
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }
    return slow - 1;
}
int main(){
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = RepeatingElement(arr, n);
    cout << "Repeating element is " << ele;
    return 0;
}

