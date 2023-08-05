#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k)
{
    if (s.length() == 0 && t.length() == 0)
    {
        return "Yes";
    }
    else if (s.length() == 0 && t.length() != 0)
    {
        if (k < t.length())
        {
            return "No";
        }
        else
        {
            return "Yes";
        }
    }
    else if (s.length() != 0 && t.length() == 0)
    {
        if (k < s.length())
        {
            return "No";
        }
        else
        {
            return "Yes";
        }
    }
    int i = 0;
    while (t[i] == s[i])
    {
        i++;
    }
    if (s.length() == t.length())
    {
        if (s.length() == i)
        {
            if (k < (2 * s.length()))
            {
                if (k % 2 == 0)
                {
                    return "Yes";
                }
                else
                {
                    return "No";
                }
            }
            else
            {
                return "Yes";
            }
        }
        else if (i == 0)
        {
            if (k < (s.length() + t.length()))
            {
                return "No";
            }
            else
            {
                return "Yes";
            }
        }
        else
        {
            if (k < 2 * (s.length() - i))
            {
                return "No";
            }
            else
            {
                if ((k - 2 * (s.length() - i) % 2 == 0))
                {
                    return "Yes";
                }
                else
                {
                    return "No";
                }
            }
        }
    }
    else
    {
        if (i == s.length())
        {
            if (k < (t.length() - i))
            {
                return "No";
            }
            else
            {
                if ((k - t.length() - i) % 2 == 0)
                {
                    return "Yes";
                }
                else
                {
                    return "No";
                }
            }
        }
        else if (i == t.length())
        {
            if (k < (s.length() - i))
            {
                return "No";
            }
            else
            {
                if ((k - s.length() - i) % 2 == 0)
                {
                    return "Yes";
                }
                else
                {
                    return "No";
                }
            }
        }
        else if (i != t.length() && i != s.length())
        {
            if (k < (s.length() + t.length() - 2 * i))
            {
                return "No";
            }
            else
            {
                if ((k - (s.length() + t.length() - 2 * i)) % 2 == 0)
                {
                    return "Yes";
                }
                else
                {
                    return "No";
                }
            }
        }
        else if (i == 0)
        {
            if (k < (s.length() + t.length()))
            {
                return "No";
            }
            else
            {
                return "Yes";
            }
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
