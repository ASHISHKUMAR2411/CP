// MultipleReturnType
/* Tuple

A tuple is an object capable to hold a collection of elements where each element can be of a different type.
Class template std::tuple is a fixed-size collection of heterogeneous values
Pair

This class couples together a pair of values, which may be of different types
A pair is a specific case of a std::tuple with two elements
Note : Tuple can also be used to return two values instead of using pair .
 */
#include <bits/stdc++.h>
using namespace std;
tuple<int, int, char> multipleOutput1(int num1, int num2)
{
    return make_tuple(num2, num1, 'a');
}
pair<int, int> multipleOutput2(int num1, int num2)
{
    return make_pair(num2, num1);
}
int main()
{
    int a, b;
    char cc;
    tie(a, b, cc) = multipleOutput1(5, 10);
    cout << " " << a << " " << b << " " << cc << " ";
    pair<int, int> p = multipleOutput2(15, 20);
    cout << " " << p.first << " " << p.second << " ";
    return 0;
}