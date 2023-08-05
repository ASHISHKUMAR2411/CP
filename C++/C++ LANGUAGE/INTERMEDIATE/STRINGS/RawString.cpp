//CPP program for  RawString, we are demonstrating the raw string in order ,
#include <iostream>
using namespace std;
int main()
{
    string string1 = "Geeks\nFor\nGeeks";
    string string2 = R"(Geeks\nFor\nGeeks)";
    cout << " " << string1 << "\n"<< string2 << endl;
    return 0;
}