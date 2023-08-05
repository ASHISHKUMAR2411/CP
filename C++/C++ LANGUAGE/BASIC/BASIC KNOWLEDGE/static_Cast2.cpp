// CPP in this program we will change our snippet code
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    char c = 'a';
    // pass at compile time, may fail at run time
    int *q = (int *)&c;
    int *p = (static_cast<int *>((int *)&c));
    cout << *p << " " << *q;
    return 0;
}
