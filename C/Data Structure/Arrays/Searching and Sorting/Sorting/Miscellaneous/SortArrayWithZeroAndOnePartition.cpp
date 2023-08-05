// Partition array with zeroes and ones 
#include<bits/stdc++.h>
using namespace std;
void PartitionZeroesOnes(int arr[], int n){
    int i = -1, j = n;
    while(true){
        do
        {
            /* code */
            i++;
        } while (arr[i] == 0);
        do
        {
            /* code */
            j--;
        } while (arr[j]);
        if(i>=j)
            return;
        swap(arr[i], arr[j]);
    }
}
int main(){
    int n = 25;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%2;
        cout << arr[i] << " ";
    }
    cout << endl;
    PartitionZeroesOnes(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}