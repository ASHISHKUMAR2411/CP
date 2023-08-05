// CPP program to find the array of string type using a soimple another method
// Method 3:

// This is the simplest ad most efficient one. We can directly assign the address of 1st character of the string to a pointer to char. This should be the preferred method unless your logic needs a copy of the string.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    char *ptr;
    string s("ASHISH KUMAR ");
    ptr = &s[0];
    cout << ptr << endl;
    return 0;
}