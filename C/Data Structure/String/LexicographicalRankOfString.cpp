// GIven a String Find the lexicographically Rank of the string
// This is when string has distinct character
#include <bits/stdc++.h>
using namespace std;
#define CHAR 256
#define mod 1000000007
int factorial(int n)
{
    int num = 1;
    while (n > 1)
    {
        num = ((num % mod) * (n % mod)) % mod;
        n--;
    }
    return num;
}
int FindRank(string const &s)
{
    int c[CHAR] = {0};
    int res = 1, mul = factorial(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        c[s[i]]++;
    }
    for (int i = 1; i < CHAR; i++)
    {
        c[i] += c[i - 1];
    }
    for (int i = 0; i < s.length(); i++)
    {
        mul = mul / (s.length() - i);
        res = ((res % mod) + ((c[s[i] - 1] % mod) * (mul % mod)) % mod) % mod;
        if(res < 0){
            res = res + mod;
        }
        for (int j = s[i]; j < CHAR; j++)
            c[j]--;
    }
    return res;
}

int main()
{
    srand(time(0));
    int n = rand() % 250;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += (char)('a' + rand() % 26);
    }
    cout << s << endl;
    cout << "The rank is : " << FindRank(s) << endl;
    return 0;
}