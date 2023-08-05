#include <iostream>
using namespace std;
//* * using recursion also we can do the same
template <class T>
void insertionSort(T arr[], int size)
{
    /*
    * code */
    static int i = 0;
    static T temp;
    //** as i starts from 0;
    if (i == (size - 1))
    {
        return;
    }
    i = i + 1;
    int j = i;
    temp = arr[i];
    while (j > 0 && arr[j - 1] > temp)
    {
        arr[j] = arr[j - 1];
        j--;
    }
    arr[j] = temp;
    insertionSort(arr, size);
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
    //* int arr[100];
    //* char arr[100];
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
    //* insertionSort<int>(arr,size);
    //* insertionSort<char>(arr,size);
    insertionSort<string>(arr, size);
    //* print<int>(arr,size);
    print<string>(arr, size);
    //* print<char>(arr,size);
}