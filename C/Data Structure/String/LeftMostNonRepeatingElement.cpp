#include <bits/stdc++.h>
using namespace std;

// Naive Solution
bool FindNonRepeatingElement(string &s){
    int i = 0, j = 0;
    for (i = 0; i < s.length() -1 ; i++)
    {
        bool flag = false;
        for (j = 0; j < s.length(); j++)
        {
            if(i != j && s[i] == s[j]){
                flag = true;
                break;
            }
        }
        if(flag == false)
            return i;
    }
    return -1;
}

bool FindNonRepeatingElement2(string &s){
    int count[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if(count[s[i]] == 1){
            return i;
        }
    }
    return -1;
}
int main() {
    srand(time(0));
    string s = "", sub = "";
    int n = rand() % 250;
    for (int i = 0; i < n; i++)
    {
        s += (char)('a' + rand() % 26);
    }
    cout << s << endl;
    cout << "The left repeating letter is : " << FindNonRepeatingElement2(s) << endl;
    cout << "The left repeating letter is : " << FindNonRepeatingElement(s) << endl;
    return 0;
}