#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    // prints from right but ++a is first changes so ir does not print first the first one prints is 
    cout << a++ << a++ << ++a << ++a;
    // in addition it is used as it first uses ++a so it uses one of its feature that is first increase now if we assume a++ as x and ++a as y then x will first use yhe value of the a which is 15 as ++a has changes it 15+ +15+15 will be use as first step as ++a will now use it before using that x will increent it to 16 then 17 then 18 as there are thre x so now we have only y =18 so sum will be 15+18+15+15 
    a = a++ + ++a + a++ + a++;
    cout << "\n" << a;
    return 0;
}