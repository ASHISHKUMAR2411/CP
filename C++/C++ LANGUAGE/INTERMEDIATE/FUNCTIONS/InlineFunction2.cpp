/* It is also possible to define the inline function inside the class. In fact, all the functions defined inside the class are implicitly inline. Thus, all the restrictions of inline functions are also applied here. If you need to explicitly declare inline function in the class then just declare the function inside the class and define it outside the class using inline keyword. */
#include <iostream>
#include <string>
using namespace std;
class InlineFunction2
{
private:
    /* data */
    int a, b, add, sub, mul;
    float div;

public:
    void get();
    void addition();
    void subtract();
    void multiply();
    void divide();
};
inline void InlineFunction2 ::get()
{
    cout << "enter the first value : ";
    cin >> a;
    cout << "enter the second value : ";
    cin >> b;
}
inline void InlineFunction2::addition()
{
    add = a + b;
    cout << "\nthe sum is : " << add;
}
inline void InlineFunction2::subtract()
{
    sub = a - b;
    cout << "\nThe difference is : " << sub;
}
inline void InlineFunction2::multiply()
{
    mul = a * b;
    cout << "\nThe Multiple is : " << mul;
}
inline void InlineFunction2::divide()
{
    div = (float)a / b;
    cout << "\nThe division is  : " << div;
}
int main()
{
    cout << "\nLet's test the The inline function :  \n";
    InlineFunction2 s;
    s.get();
    s.addition();
    s.divide();
    s.subtract();
    s.multiply();
    return 0;
}
