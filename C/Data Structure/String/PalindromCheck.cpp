// Check Palindrom
#include <bits/stdc++.h>
using namespace std;

bool Check(string &s)
{
    string s1 = s;
    reverse(s.begin(), s.end());
    if (s1 == s)
    {
        return true;
    }
    return false;
}
// O(n)
bool CheckPalindrom(string &s)
{
    int begin = 0, end = s.length() - 1;
    while(begin <= end){
        if(s[begin] == s[end]){
            begin++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "Ashishsihs";
    if (CheckPalindrom(s))
    {
        cout << "Yes Palindrom" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
