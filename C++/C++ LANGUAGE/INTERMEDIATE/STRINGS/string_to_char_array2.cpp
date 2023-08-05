//CPP programs to find the array of the string tye string using simple method
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s("ASHISH KUMAR ");
    char arr[s.length()];
    for (int i = 0; i < sizeof(arr); i++)
    {
        arr[i] = s[i];
        cout << " " << arr[i];
    }
    return 0;
}