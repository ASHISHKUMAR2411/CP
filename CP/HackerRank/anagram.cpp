#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
struct key
{
    char ch;
    int count;
};
int main()
{
    string s;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        getline(cin, s);
        if ((s.length() % 2) == 1)
        {
            cout << -1;
            return 0;
        }
        vector<key> letter;
        int size = 0;
        letter.reserve(s.length());
        for (int i = 0; i < s.length() / 2; i++)
        {
            letter.push_back({s[i], 1});
            size++;
            for (int j = 0; j < i; j++)
            {
                if (s[i] == letter[j].ch)
                {
                    letter[j].count++;
                    letter.pop_back();
                    size--;
                    letter.shrink_to_fit();
                }
            }
        }
        int z = 0;
        for (int i = s.length() / 2; i < s.length(); i++)
        {
            z = 0;
            for (int j = 0; j < size; j++)
            {
                if (s[i] == letter[j].ch)
                {
                    letter[j].count--;
                    z = 1;
                    break;
                }
            }
            if (z == 0)
            {
                letter.push_back({s[i], 1});
                size++;
            }
        }
        z = 0;
        for (int i = 0; i < size; i++)
        {
            if (letter[i].count > 0)
            {
                z += abs(letter[i].count);
            }
            
        }
        cout << z/2;
    }
    return 0;
}