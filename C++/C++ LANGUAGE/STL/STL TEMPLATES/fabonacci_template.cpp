// CPP file for the template of the fabonaci series
#include <iostream>
using namespace std;
template <class T>
void fabonacci(T x)
{
    T a = 1;
    T b = 1;
    T sum = 0;
    T i = 1;
    cout << a << " " << b;
    while (i < x)
    {
        sum = a + b;
        cout << " " << sum;
        a = b;
        b = sum;
        i++;
    }
}
int main()
{
    fabonacci<int>(5);
    cout<<endl;
    fabonacci<char>(5);
    cout<<endl;
    fabonacci<float>(5);
    cout<<endl;
    fabonacci<double>(5);
    cout<<endl;
    return 0;
}