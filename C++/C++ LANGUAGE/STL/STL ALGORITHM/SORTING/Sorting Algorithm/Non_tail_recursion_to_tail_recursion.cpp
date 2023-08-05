// converting non tail recursion to tail recursion

#include <iostream>
using namespace std;
unsigned facto(unsigned int n, unsigned int a)
{
    if (n == 0)
    {
        return a;
    }
    return facto(n - 1, n * a);
}
unsigned fact(int n)
{
    return facto(n, 1);
}
int main()
{
    cout << fact(5) << endl;
    return 0;
}
