// CPP program for using getline function()
// 1. Syntax:

// istream& getline (istream& is, string& str);
// 2. The second declaration is almost the same as that of the first one. The only difference is, the latter have an delimitation character which is by default newline(\n)character.
// Parameters:

// is: It is an object of istream class and tells the function about the stream from where to read the input from.
// str: It is a string object, the input is stored in this #object after being read from the stream.

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    cout << " HELLO " << str << " WELOCME TO CODING ";
    return 0;
}