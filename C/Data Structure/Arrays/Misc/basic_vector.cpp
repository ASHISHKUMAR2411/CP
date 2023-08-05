// array are the data type which are useful in cache and random access but they takes bad for the stack and pop operation ..
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> v1(v.size());
    for (int i = 1; i <= v.size(); i += 2)
    {
        v1.insert(v1.begin() + i, v.end()-i,v.end()-i);
        v1.insert(v1.begin() + (i - 1), v.begin()-i,v.begin()-i);
    }
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}