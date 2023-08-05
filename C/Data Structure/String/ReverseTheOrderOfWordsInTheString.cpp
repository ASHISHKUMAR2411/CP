// Reverse the order of words in the string
#include <bits/stdc++.h>
using namespace std;

void reverseTheOrderOfWordsInTheString(string &s)
{
    vector<int> words;
    stringstream ss(s);
    string word;
    // error
    while (ss >> word)
    {
        // words.push_back(word);
    }
    s = "";
    for (int i = words.size() - 1; i >= 0; i--)
    {
        s += words[i];
    }
}

// Using one fact that reverse the each words then reverse the whole string can convert it reversed order of the string
void reverseTheString(string &s)
{
    int i = 0, j = 0;
    while (j < s.length())
    {
        if (j == s.length() - 1)
        {
            reverse(s.begin() + i, s.end());
        }
        else if (s[j] == ' ')
        {
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        j++;
    }
    reverse(s.begin(), s.end());
}

int main()
{
    srand(time(0));
    int n = rand() % 37;
    string s = "", sub = "";
    for (int i = 0; i < n; i++)
    {
        int m = rand() % 20;
        sub = "";
        for (int j = 0; j < m; j++)
        {
            sub += (char)('a' + rand() % 26);
        }
        if (i != n - 1)
        {
            sub += " ";
        }
        s += sub;
    }
    cout << s << endl;
    reverseTheString(s);
    cout << s << endl;
}