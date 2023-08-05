// CPP prgram to undertand c++ string
// NOTE These strings are constants and their contents cannot be changed. Because string literals (literally, the quoted strings) exist in a read-only area of memory, we must specify “const” here to prevent unwanted accesses that may crash the program.

#include <iostream>
using namespace std;
int main()
{
    const char *name[4] = {"Ashish", "Sony", "RAdha", "PRiya"};
    for (int i = 0; i < (sizeof(name) / sizeof(name[0])); i++)
    {
        cout << " " << name[i];
    }
    return 0;
}