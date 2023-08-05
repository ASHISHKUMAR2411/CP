// Find the longest substring with distinct character
#include<bits/stdc++.h>
using namespace std;
int FindLongestSubStringWithDistinctCharacter(string &s){
    int res = 0, i = 0;
    vector<int> prev(256, -1);
    for (int j = 0; j < s.length(); j++){
        i = max(i, prev[s[j]] + 1);
        int maxE = j - i + 1;
        res = max(res, maxE);
        prev[s[j]] = j;
    }
    return res;
}
int main(){
    srand(time(0));
    int n = rand() % 250;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += (char)('a' + rand() % 26);
    }
    cout << s << endl;
    cout << "Longest Distinct substring is : " << FindLongestSubStringWithDistinctCharacter(s) << endl;
    return 0;
}
