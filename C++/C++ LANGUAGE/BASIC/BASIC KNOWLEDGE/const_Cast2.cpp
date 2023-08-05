// CPP program to cast a function such that it can recieve const data such that it does not suppose to
// For example, in the following program fun() receives a normal pointer, but a pointer to a const can be passed with the help of const_cast.
#include <iostream>
using namespace std;
int fun(int *ptr)
{
    return (*ptr + 10);
}
int main()
{
    const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast<int *>(ptr);
    cout << fun(ptr1);
    return 0;
}
