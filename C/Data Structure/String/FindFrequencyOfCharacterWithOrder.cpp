// Finding frequencies can be implemented with the following Two Function
#include <bits/stdc++.h>
using namespace std;
// Using hash func
void FindFreq(string &s)
{
    unordered_map<char, int> map;
    for (char i : s)
    {
        map[i]++;
    }
    for (auto i : map)
    {
        cout << " " << i.first << " " << i.second;
    }
}

void FindFreq2(string &s)
{
    vector<int> C(26, 0);
    for (auto i : s)
    {
        C[i - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(C[i]){
            cout << " "<<(char)(i + 'a') << ":" << C[i];
        }
    }
}

int main(){
    string s = "";
    srand(time(0));
    int n = rand()%50;
    for (int i = 0; i < n; i++){
        s += (char)('a' + rand() % 26);
    }
    cout << s << endl;
    cout << "\n";
    FindFreq(s);
    cout << "\n";
    FindFreq2(s);
    return 0;
}