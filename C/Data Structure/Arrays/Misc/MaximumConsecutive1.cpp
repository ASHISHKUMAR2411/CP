#include<bits/stdc++.h>
using namespace std;

int maxCons1(bool arr[], int n){
    int count = 0;
    int maxCount = 0;
    for(int i = 0; i < n; i++){
        while( i < n && arr[i] == 1){
            count++;
            i++;
        }
        maxCount = max(maxCount, count);
        count = 0;
    }
    return maxCount;
}
int main(){
    bool arr[] = {1, 1, 0, 1, 1, 1,1,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxCons1(arr, n);
    return 0;
}