// CPP program to find the reverse string 5
// using some extra space and using the constructor and passing opposite value will give us the reversed string
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ASHISH KUMAR";
    string rev = string(str.rbegin(), str.rend());
    cout << rev << endl;
    return 0;
}