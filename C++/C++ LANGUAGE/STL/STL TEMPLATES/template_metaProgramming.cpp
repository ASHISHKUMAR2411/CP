// ? in template meta programming the calculation is done at compile time
//  because of which it is very famous among programmer

// ? the below program calculates 2^n
#include <iostream>
using namespace std;
//  for factorial 
template <unsigned int n> struct factorial
{
    enum
    {
        val = n * factorial<n - 1>::val
    };
};

template<> struct factorial<0>
{
    enum
    {
        val = 1
    };
};

// for 2^n
template <int n> struct funStruct
{
    enum
    {
        val = 2 * funStruct<n - 1>::val
    };
};
template <> struct funStruct<0>
{
    enum
    {
        val = 1
    };
};
int main()
{
    cout << funStruct<8>::val << endl;
    return 0;
}

//TODO : The program calculates “2 raise to the power 8 (or 2^8)”. In fact, the structure funStruct can be used to calculate 2^n for any known n (or constant n). The special thing about above program is: calculation is done at compile time. So, it is compiler that calculates 2^8. To understand how compiler does this, let us consider the following facts about templates and enums:

// TODO : 1) We can pass nontype parameters (parameters that are not data types) to class/function templates.
//TODO : 2) Like other const expressions, values of enumeration constants are evaluated at compile time.
//TODO : 3) When compiler sees a new argument to a template, compiler creates a new instance of the template.

// *Template Metaprogramming is generally not used in practical programs, it is an interesting concept though.