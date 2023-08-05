#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int t, x;
    cin >> t;
    for (int i = 0; i < t; i++)
    {

        cin >> x;
        v.push_back(x);
    }

    for (auto i = v.begin(); i != v.end(); ++i)
    {
        if ((*i )== 0)
        {
            v.push_back(*i);
            v.erase(i);
        }
    }
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    return 0;
}