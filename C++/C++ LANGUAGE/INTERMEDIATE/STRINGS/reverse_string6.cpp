// CPP program to reverse the string using temporray string
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ASHISH KUMAR";
    string rev;
    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        rev.push_back(str[size-1-i]);
    }
    cout << rev << endl;
}