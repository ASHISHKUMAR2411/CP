#include <bits/stdc++.h>
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