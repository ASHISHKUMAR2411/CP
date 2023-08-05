#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2)
{
    if ((int)(s1.length()) == 0 && (int)(s2.length()) == 0)
    {
        return 0;
    }
    if ((int)(s1.length()) == 0 && (int)(s2.length()))
    {
        return (int)(s2.length());
    }
    if ((int)(s2.length()) == 0 && (int)(s1.length()))
    {
        return (int)(s1.length());
    }
    int a[26], b[26];
    for (int i = 0; i < 26; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    for (int i = 0; i < (int)(s1.length()); i++)
    {
        a[(s1[i] - 'a')]++;
    }
    for (int i = 0; i < (int)(s2.length()); i++)
    {
        b[(s2[i] - 'a')]++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] == b[i] && a[i] != 0)
        {
            count += a[i];
        }
        else if (a[i] != 0 && b[i] != 0)
        {
            if (a[i] < b[i])
            {
                count += a[i];
            }
            else
            {
                count += b[i];
            }
        }
    }
    int no_of_deletion = (int)(s1.length() + s2.length()) - 2*count;
    return no_of_deletion;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    cout << result << "\n";

    // fout.close();

    return 0;
}
