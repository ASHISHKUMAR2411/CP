// CPP code for bad_alloc
#include <iostream>
#include <new>
//  if allocation is not possible then we get error not the catch statement are executed , so we have to be alert .
// Driver code
int main()
{
    try
    {
        int *gfg_array = new int[100000000];
    }
    catch (std::bad_alloc &ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what();
    }
    return 0;
}
