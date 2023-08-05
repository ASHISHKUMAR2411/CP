// CPP program to find the reverse string using the Inbulit
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int main()
{
    string str = "ASHISH KUMAR ";
    // we have reverse algorithm inside algoritm 
    reverse(str.begin(),str.end());
    cout << str;
    return 0;
}