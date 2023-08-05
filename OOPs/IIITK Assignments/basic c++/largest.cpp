#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void smallestLargest(int arr[], int n)
{
    int i, j, min = arr[0],max = arr[0];
    for (i = 1; i < n ; i++)
    {
        if(arr[i]<min)
            min = arr[i];
        else if(arr[i]>max)
            max = arr[i];
    }
    cout << "Smallest " << min << " and Largest " << max;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr,n);
    smallestLargest(arr,n);
    return 0;
}