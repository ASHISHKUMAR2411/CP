// To Check if a string is a substring of another string. here substring may or may be consecutive strings
#include <bits/stdc++.h>
using namespace std;
// O(n)
bool isSubString(const string &s, const string &sub)
{
    int i = 0, j = 0;
    if (sub == "")
    {
        return true;
    }
    while (i < s.length() && j < sub.length())
    {
        if (sub[j] == s[i])
        {
            j++;
        }
        i++;
    }
    if (j == sub.length())
    {
        return true;
    }
    return false;
}

int main()
{
    srand(time(0));
    string s = "", sub = "";
    int n = rand() % 250, n1 = rand() % 7;
    for (int i = 0; i < n; i++)
    {
        s += (char)('a' + rand() % 26);
    }
    if (n1 > n)
    {
        n1 = n1 % n;
    }
    for (int i = 0; i < n1; i++)
    {
        sub += (char)('a' + rand() % 26);
    }
    cout << s << endl;
    cout << sub << endl;
    if (isSubString(s, sub))
    {
        cout << " The string  is subsequence " << endl;
    }
    else
    {
        cout << "the string is not " << endl;
    }
    return 0;
}
