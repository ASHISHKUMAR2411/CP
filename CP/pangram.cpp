#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
struct key{
    char ch;
    int count;
};
string pangrams(string s) {
    key letter[26];
    for(int i =0;i<26;i++)
    {
        letter[i].ch = 97 + i;
        letter[i].count = 0;
    }
    for(int i =0;i<s.length();i++)
    {
        for(int j =0;j<26;j++)
        {
            if(letter[j].ch == s[i])
            {
                letter[i].count++;
            }
        }
    }
    for(int i =0;i<26;i++)
    {
        if(letter[i].count == 0)
        {
            return "not pangram";
        }
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
