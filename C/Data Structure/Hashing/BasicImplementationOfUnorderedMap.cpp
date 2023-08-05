// When We Have Key and Value Pair and We Want hashing then we can have unordered_map

#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int, int> map;
    for (int i = 0; i < 100; i++)
    {
        map.insert({rand() % 100, i});
    }
    for (auto it : map)
    {
        cout << "(" << it.first << "," << it.second << "), ";
    }
    cout << "\n";
    int n = rand() % 100;
    // at gives us the value of the key
    cout << n << "at"<<map.at(n) << "\n";
    cout << map.bucket_count()<< endl;
}
