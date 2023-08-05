#include<bits/stdc++.h>
using namespace std;
void NbonacciNumberUptoM(int n, int m){
    int arr[m],sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        arr[i] = 0;
    }
    arr[n-1] = 1;
    sum = 1;
    for(int i = n; i < m; i++){
        arr[i] = sum;
        sum += arr[i] - arr[i - n];
    }
    for(int i = 0; i < m; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    NbonacciNumberUptoM(n,m);
    return 0;
}