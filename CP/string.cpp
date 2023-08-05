#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> Dynamic_Array ;
    string s;
    for(int i =0;i<4;i++)
    {
        cin>>s;
        Dynamic_Array.push_back(s);
    }
    sort(Dynamic_Array.begin(), Dynamic_Array.end(),greater<string>());
    for (int i = 0; i < Dynamic_Array.size(); i++)
    {
        cout << " " << Dynamic_Array[i];
    }
    return 0;
}