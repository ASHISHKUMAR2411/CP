// CPP program to find the reverse of the string part 3
// In this we are just printing te reverse
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "ASHISH KUMAR";
    for (auto i = str.rbegin(); i != str.rend(); i++)
    {
        cout << *i;
    }
    return 0;
}
