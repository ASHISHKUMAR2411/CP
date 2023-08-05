// The purpose of using unordered_set is when we only have key to handle, not value
#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    unordered_set<int> set;
    for (int i = 0; i < 100; i++)
    {
        set.insert(rand() % 100);
    }
    for (auto it : set)
    {
        cout << it << " ";
    }
    cout << endl;
    // cout << set.begin() << endl;
    cout << set.bucket(rand() % 100) << endl;
    cout << set.bucket_count() << endl;
    // cout << set.cbegin() << endl;
    // cout << set.cend() << endl;
    cout << set.count(rand() % 100) << endl;
    // cout << set.emplace(rand() % 100) << endl;
    // cout << set.emplace_hint(set.cbegin(), rand() % 100) << endl;
    // cout << set.empty() << endl;
    // cout << set.end() << endl;
    // cout << set.equal_range(rand() % 100) << endl;
    // cout << set.find(rand() % 100) << endl;
    // cout << set.hash_function() << endl;
    // cout << set.get_allocator() << endl;
    // cout << set.key_eq() << endl;
    // cout << set.load_factor() << endl;
    cout << set.max_bucket_count() << endl;
    // cout << set.max_load_factor(0.7) << endl;
    cout << set.max_size() << endl;
    // cout << set.rehash(101);
    cout << set.bucket_count() << endl;
    for (int i = 0; i < 10; i++)
    {
        int n = rand() % 100;
        if (set.find(n) != set.end())
        {
            cout << n << "\n";
        }
        else
        {
            cout << n << "\n";
        }
    }
}