// Program to check whether the two string are anagram of each other
#include <bits/stdc++.h>
using namespace std;

bool CheckAnagram(string &s1, string &s2)
{
    unordered_map<char, int> map1, map2;
    bool flag = false;
    for (char i : s1)
    {
        map1[i]++;
    }
    for (char i : s2)
    {
        map2[i]++;
    }
    for (auto i : map1)
    {
        auto it = map2.find(i.first);
        if (it == map2.end())
        {
            return false;
        }
        else
        {
            if (it->second == i.second)
            {
                flag = true;
            }
            else
            {
                return false;
            }
        }
    }
    for (auto i : map2)
    {
        auto it = map1.find(i.first);
        if (it == map1.end())
        {
            return false;
        }
        else
        {
            if (it->second  == i.second)
            {
                flag = true;
            }
            else
            {
                return false;
            }
        }
    }
    return flag;
}
bool CheckAnagram2(string &s1 , string &s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1 == s2;
}

bool CheckAnagram3(string &s1 , string &s2){
    if(s1.length() != s2.length())
        return false;
    int count[256] = {0};
    for(char c : s1){
        count[c]++;
    }
    for(char c : s2){
        count[c]--;
        if(count[c]<0){
            return false;
        }
    }
    for(int i : count){
        if(i!=0){
            return false;
        }
    }
    return true;
}
int main()
{
    string s1 = "Ashish";
    string s2 = "Ahhssi";
    if (CheckAnagram3(s1, s2))
    {
        cout << "Anagram";
    }
    else
    {
        cout << "Not Anagram";
    }
    return 0;
}