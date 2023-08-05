// ? In binary Insertion sorting we first search the location a nd then only we insert it converts
//! O(i) for the ith sort to O(log(i)) which is a good thing but the thing is that it also takes O(n^2) for the worst case .
// 
//  TODO: In my preference we should always be using simple insertion unless and untill it is not asked where we need a sorting to reduce step time complexicity and then we can use this at that tiem when we know that that we have to break somewhere then we can use this at that time . as it will be saving time complexicity .
//
#include <bits/stdc++.h>
using namespace std;
template <class T>
int binarySearch(T arr[], T item, int low, int high)
{
    if (high <= low)
    {
        return ((item > arr[low]) ? (low + 1) : low);
    }
    int mid = (low + high) / 2;
    if (item == arr[mid])
    {
        return mid + 1;
    }
    if (item > arr[mid])
    {
        return binarySearch(arr, item, mid + 1, high);
    }
    return binarySearch(arr, item, low, mid - 1);
}

template <class T>
void binaryInsertionSorting(T arr[], int size)
{
    int i, j, location;
    T selected;
    for (i = 1; i < size; i++)
    {
        j = i - 1;
        selected = arr[i];
        location = binarySearch(arr, selected, 0, j);
        while (j >= location)
        {
            /* code */
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

template <class T>
void print(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // int arr[100];
    // char arr[100];
    string arr[100];
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "\nenter the element : ";
        cin >> arr[i];
        /* code */
    }
    cout << "Sorted Array :  \n";
    // insertionSort<int>(arr,size);
    // insertionSort<char>(arr,size);
    binaryInsertionSorting<string>(arr, size);
    // print<int>(arr,size);
    print<string>(arr, size);
    // print<char>(arr,size);
}