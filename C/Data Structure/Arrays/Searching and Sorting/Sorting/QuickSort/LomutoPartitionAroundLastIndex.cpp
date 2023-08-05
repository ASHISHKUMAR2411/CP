// Lomuto Partition Around Last Index
#include<bits/stdc++.h>
using namespace std;
// O(n) time complexity and O(1) space complexity
void LomutoPartition(int arr[], int n, int index)
{
    if(index!= n - 1){
        swap(arr[index], arr[n - 1]);
    }
    int i = -1, j = 0;
    while(j < n - 1){
        if(arr[j] < arr[n - 1]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[n - 1]);
}
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        LomutoPartition(arr, n, n - 1);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
