// If we have a pattern to search but the pattern may be present in any of its permutation i.e anagram so we have to search it
#include <bits/stdc++.h>
using namespace std;
#define CHAR 128
bool Same(int arr1[], int arr2[])
{
    for (int i = 0; i < CHAR; i++)
    {
        if (arr2[i] != arr1[i])
        {
            return false;
        }
    }
    return true;
}
bool FindAnagram(string &s, string &pat)
{
    int n = s.length(), m = pat.length();
    if (s.length() < pat.length())
        return false;
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for (int i = 0; i < CHAR; i++){
        CT[i] = CP[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        CT[s[i]]++;
        CP[pat[i]]++;
    }
    for (int i = m; i < n; i++)
    {
        if (Same(CT, CP))
        {
            return true;
        }
        CT[s[i]]++;
        CT[s[i - m]]--;
    }
}

int main()
{
    string s = "Ashish", s2 = "hishas";
    if (FindAnagram(s, s2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}