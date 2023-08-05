#include <iostream>
using namespace std;
int main()
{
    int *ptr = new (nothrow) int[100];
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout << "\nenter the element ";
        cin >> *(ptr + i);
    }
    cout << " the array is \n";
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i];
    }
    delete[] ptr;
    return 0;
}