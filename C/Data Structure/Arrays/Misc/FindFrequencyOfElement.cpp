#include<bits/stdc++.h>
using namespace std;
void FrequencyElement(int arr[], int n){
    int A[50];
    for(int i=0;i<50;i++)
        A[i]=0;
    for(int i=0;i<n;i++)
        A[arr[i]]++;
    for(int i=0;i<50;i++){
        if(A[i]!=0){
            cout<<"Element "<<i<<" occurs "<<A[i]<<" times"<<endl;
        }
    }
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 3, 4, 2, 3, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);
    FrequencyElement(arr, n);
    return 0;
}