// Return from Void functions
#include <iostream>
using namespace std;
void Print()
{
    cout << "\nReturn the void function";
    return (void)"doesn't Print this";
}
void test()
{
    cout << "\nHello there we are testing the void function ";
    return Print();
}
int main()
{
    test();
    return 0;
}