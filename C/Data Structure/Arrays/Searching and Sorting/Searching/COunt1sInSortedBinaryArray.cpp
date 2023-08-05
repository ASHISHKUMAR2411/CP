// TO count the number of ones in the sorted binary ones
#include<bits/stdc++.h>
using namespace std;
int FindFirstOccurrence(int arr[], int n, int ele){
    int low = 0, mid = 0, high = n - 1;
    while(low<=high){
        mid = high - (high - low)/2;
        if(arr[mid] == ele){
            if(mid == 0 || arr[mid-1] != ele)
                return mid;
            else
                high = mid - 1;
        }
        else if(arr[mid] > ele)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int Count1sOccurenece(int arr[], int n){
    int low = FindFirstOccurrence(arr,n,1);
    if(low == -1) return 0;
    else{
        return n - low;
    }
}
int main(){
    int arr[] = {0,0,0,0,0,1,1,1,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = Count1sOccurenece(arr,n);
    cout << "Count of 1s is " << count;
    return 0;
}