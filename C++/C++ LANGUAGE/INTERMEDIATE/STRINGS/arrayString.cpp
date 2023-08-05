// CPP program to use the array inbuilt function
#include <iostream>
#include <array>
#include <string>
// NOTE array are same as vectors
using namespace std;
int main()
{
    array<string, 4> color{" Red ", " yellow ", " green ", " Blue "};
    cout << color.at(2);
    for (int i = 0; i < 4; i++)
    {
        cout << color[i] << " ";
    }
}