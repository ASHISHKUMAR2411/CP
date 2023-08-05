// Find whether the given two string are rotated.
#include <bits/stdc++.h>
using namespace std;

bool FindWhetherStringAreRotated(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;
    return ((s1 + s1).find(s2) != string::npos);
}

int main()
{
    string s1 = "ABCD", s2 = "CDAB";
    if (FindWhetherStringAreRotated(s1, s2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}