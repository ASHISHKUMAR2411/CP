// CPP program to check the getline function
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str;
    int id;
    cout << "\nEnter your ID : ";
    cin >> id;
    cout << "\nenter the name : ";
    getline(cin, str);
    cout << " \n YOur ID is : " << id;
    cout << "\n your name is : " << str;
    cout << "\nENter your name again : ";
    getline(cin, str);
    cout << "\nyou entered : " << str;
    return 0;
}