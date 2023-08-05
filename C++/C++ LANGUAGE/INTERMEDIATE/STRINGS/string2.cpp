#include <iostream>
#include <string>
using namespace std;
int main()
{
    string arr[4] = {"Ashish", " Sony", "Priya", "radha "};
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}