// Find a pattern in the text
#include <bits/stdc++.h>
using namespace std;
// If pattern have repeating character
vector<int> Pattern(string &text, string &pattern)
{
    int i = 0, j = 0;
    vector<int> pos;
    while (i <= (text.length() - pattern.length()))
    {
        int k = i;
        while (k < text.length() && j < pattern.length() && text[k] == pattern[j])
        {
            j++;
            k++;
        }
        if (j == pattern.length())
        {
            pos.push_back(i);
        }
        j = 0;
        i++;
    }
    return pos;
}

// If pattern have distinct characters
// O(n) time complexity
vector<int> Pattern2(string &text, string &pattern)
{
    int i = 0, j = 0;
    vector<int> pos;
    while (i <= (text.length() - pattern.length()))
    {
        int k = i;
        while (k < text.length() && j < pattern.length() && text[k] == pattern[j])
        {
            j++;
            k++;
        }
        if (j == pattern.length())
        {
            pos.push_back(i);
        }
        if (j == 0)
        {
            i++;
        }
        else
        {
            i = i + j;
            j = 0;
        }
    }
    return pos;
}

// Rabin Karp Algorithm which is better than naive but in worst case it is like naive
// But it is very important when we have to search for multiple pattern in the string using hash function
#define d 256
#define q 256
vector<int> Pattern3(string &txt, string &pat)
{
    vector<int> pos;
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t)
        {
            bool flag = true;
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
                if (flag)
                    pos.push_back(i);
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

            if (j == M)
                pos.push_back(i);
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
    auto ip = unique(pos.begin(), pos.end());
    // Now v becomes {1 3 10 1 3 7 8 * * * * *}
    // * means undefined

    // Resizing the vector so as to remove the undefined terms
    pos.resize(distance(pos.begin(), ip));
    return pos;
}

// For KMP
// Time Complexity O(n)
// For every position we find the lps i.e longest proper prefix suffix

// KMP Naive SOlution
// O(n^2)
int LPS(string &str, int n)
{
    for (int len = n - 1; len > 0; len--)
    {
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != str[n - len + i])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            return len;
        }
    }
    return 0;
}

// Now Finding LPS in O(n^3)
void FindLPS(string &str, vector<int> &lps)
{
    for (int i = 0; i < str.length(); i++)
    {
        lps[i] = LPS(str, i + 1);
    }
}

// Now Finding LPS in O(n)
void FindingLPS(string &str, vector<int> &lps)
{
    lps[0] = 0;
    int len = lps[0];
    int i = 1;
    while (i < lps.size())
    {
        if (str[i] == str[len])
        {
            len++;
            str[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

// Now KMP ALgorithm
vector<int> KMP(string &txt, string &pat)
{
    int n = txt.length(), m = pat.length();
    vector<int> pos, lps(m);
    // Two Ways One to use naive solution and other to use O(n)
    // 1. Naive
    // FindLPS(pat, lps);
    // 2. Linear
    FindingLPS(pat, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            pos.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    return pos;
}

int main()
{
    string text = "kajweahiodjwenascliwhfjwiokalwcmdoasljcnuwkasnlksaodjknwdkaslmxlaskl";
    string pattern = "jwe";
    for (int i : KMP(text, pattern))
    {
        cout << i << " ";
    }
    return 0;
}