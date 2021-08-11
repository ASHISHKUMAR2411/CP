#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s)
{
    if ((int)(s.length()) < 2)
    {
        return "NO";
    }
    else
    {
        int a[26];
        for (int i = 0; i < 26; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < (int)(s.length()); i++)
        {
            a[(s[i] - 'a')]++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] % 2 == 1)
            {
                count++;
            }
        }
        if ((int)(s.length()) % 2 == 0)
        {
            if (count > 0)
            {
                return "NO";
            }
            else
            {
                return "YES";
            }
        }
        else
        {
            if(count==1)
            {
                return "YES";
            }
            else{
                return "NO";
            }
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
