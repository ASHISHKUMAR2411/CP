// CPP program to find the functioning of the getline function in C++

// The C++ getline() is a standard library function that is used to read a string or a line from an input stream. It is a part of the <string> header. The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered. While doing so the previously stored value in the string object str will be replaced by the input string if any.
// The getline() function can be represented in two ways:
// Syntax:

// istream& getline(istream& is,
//    string& str, char delim);
// 2. Parameters:

// is: It is an object of istream class and tells the function about the stream from where to read the input from.
// str: It is a string object, the input is stored in this object after being read from the stream.
// delim: It is the delimitation character which tells the function to stop reading further input after reaching this character.

#include <iostream>
#include <string>
using namespace std;
#define Max_Len 30
int main()
{
    char name[Max_Len], address[Max_Len], Id[Max_Len];
    cout << "\nenetre the name :";
    cin.getline(name, Max_Len);
    cout << "\nenter your adress (enter @ to exit )";
    cin.getline(address, Max_Len, '@');
    // if the len execeeds the max-len then it will stop execution after that i.e it will print the result unless the format is clear

    cout << "\neneter the Id : ";
    cin.getline(Id, Max_Len);
    cout << "\nThe name is : " << name;
    cout << "\nThe adress is : " << address;
    cout << "\nThe ID is : " << Id;
    return 0;
}