// CPP program to understand the Template of C++ i Array

// NOTE : These strings are constants and their contents cannot be changed. Because string literals (literally, the quoted strings) exist in a read-only area of memory, we must specify “const” here to prevent unwanted accesses that may crash the program.

#include <iostream>
using namespace std;
template <class T>
void Creation(T a[], int size)
{
    for (int u = 0; u < size; u++)
    {
        cout << "\nenter the element :";
        cin >> a[u];
    }
}
template <class T>
void print(T a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << i[a];
    }
}
int main()
{
    cout << "\n enter the size of the array you want ";
    int size;
    cin >> size;
    // int arr[size];
    string arr[size];
    cout << "\nenter the element of the array \n";
    Creation<string>(arr, size);
    cout << "\n the element of the array is : ";
    print<string>(arr, size);
    return 0;
}