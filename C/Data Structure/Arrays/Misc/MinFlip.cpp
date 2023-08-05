#include<bits/stdc++.h>
using namespace std;

// to print the number of minimum flips required to make all the elements of the array equal
void printGroups(bool arr[], int n){
    for (int i = 1; i < n; i++){
        if(arr[i] != arr[i-1]){
            if(arr[i]!=arr[0]){
                cout << "From : " << i << " to ";
            }
            else cout<<i-1<<endl;
        }
    }
    if(arr[n-1]!=arr[0])
        cout  << n-1 <<endl;
}


int countMinSubArrayFlip(bool arr[], int n){
    // to count the number of minimum flips required
    int count0 = 0, count1 = 0, flag = 0;
    for (int i = 0; i < n;i++){
        if (arr[i] == 0)
        {
            count0++;
            while(i<n && arr[i] == 0)
            {
                i++;
                flag = 1;
            }
            i--;
        }
    }
    return count0;
}
int main(){
    bool arr[] = {0, 0,1 ,0, 0, 0,1, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countMinSubArrayFlip(arr, n);
    return 0;
}