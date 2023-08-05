#include<bits/stdc++.h>
using namespace std;

// delete element from array
void delete_ele(int arr[],int n,int ele)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            for(j=i;j<n-1;j++)
            {
                arr[j]=arr[j+1];
            }
            n--;
        }
    }
}

void delete_ele(int arr[], int n, int ele)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            break;
        }
    }
    for (j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    n--;
}

int main()
{
    // there are four types of fixed arrays initialisation in C++
    // 1. array name[size]
    // 2. array name[] = {value1, value2, value3, value4, value5}
    // 3. array *name = new int[size]
    // 4. array *name = new int[size] = {value1, value2, value3, value4, value5}
    int array1[5] = {1, 2, 3, 4, 5};
    int *array2 = new int[5];
    array2[0] = 1;
    array2[1] = 2;
    array2[2] = 3;
    array2[3] = 4;
    array2[4] = 5;
    int n , array3[n];
    int arr[] = {1, 3, 0, 2};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        cin >> array3[i];
    }
    cout << "The elements of array1 are: ";
    for(int i = 0; i < 5; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
    cout << "The elements of array2 are: ";
    for(int i = 0; i < 5; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
    cout << "The elements of array3 are: ";
    for(int i = 0; i < n; i++){
        cout << array3[i] << " ";
    }
    cout << endl;
    cout << "The elements of array4 are: ";
    // having trouble in print the array4
    for(int i = 0; i < n1; i++){
        cout << arr[i] << " ";
    }
    return 0;
}