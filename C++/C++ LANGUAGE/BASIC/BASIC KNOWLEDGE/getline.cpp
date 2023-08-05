#include <iostream>
#include <cstring>
using namespace std;
// using std::cin;
// using std::cout;
int main()
{
    string str;
    int i = 5;
    while (i--)
    {
        getline(cin, str);
        if(str.length()==0)
        getline(cin,str);
        cout << str << ":newline" << std::endl;
    }
    return 0;
}