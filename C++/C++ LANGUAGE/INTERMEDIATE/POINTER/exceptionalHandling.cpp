#include <iostream>

// using namespace std;
// NOTE The most important reason why free() should not be used for de-allocating memory allocated using NEW is that, it does not call the destructor of that object while delete operator does.



int main(int argc, char **argv)
{

    int *piValue = NULL;

    try
    {
        piValue = new int[99999]; // allocate huge amount of memory
    }
    catch (...)
    {
        cout << "Free memory is not available" << endl;

        return -1;
    }

    delete[] piValue;

    return 0;
}