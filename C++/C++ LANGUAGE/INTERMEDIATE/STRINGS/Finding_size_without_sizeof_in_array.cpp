// CPP program to find the size of the array without using sizeof function indeed
#include <bits/stdc++.h>
using namespace std;

// User defined sizeof macro
#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size1 = my_sizeof(arr) / my_sizeof(arr[0]);

    cout << "Number of elements in arr[] is "<< size1;
    int size2 = *(&arr+1)-arr;
    cout << "\nNumber of elements in arr[] is "<< size2;

    return 0;
}