// C++ program to demonstrate vector of strings using
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    // Declaring Vector of String type
    // Values can be added here using initializer-list syntax
    vector<string> colour{"Blue", "Red", "Orange"};

    // Strings can be added at any time with push_back
    colour.push_back("Yellow");

    // Print Strings stored in Vector
    for (int i = 0; i < colour.size(); i++)
        cout << colour[i] << "\n";
}
