#include<bits/stdc++.h>
using namespace std;

void reverse_Array(int arr[],int n){
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    }
}

int main()
{
    int n, i, j, temp;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "The array after reversing is: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}