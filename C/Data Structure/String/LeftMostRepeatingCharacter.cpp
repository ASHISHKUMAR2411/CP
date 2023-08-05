// We have one string find the first character which appears twice 
#include<bits/stdc++.h>
using namespace std;
// Naive Solution O(n*n)
bool LeftRepeating(string &s){
    for (int i = 0; i < s.length() - 1; i++){
        for (int j = i + 1; j < s.length(); j++){
            if(s[i] == s[j]){
                return i;
            }
        }
    }
    return -1;
}

// O(n) & O(256) but multiple traversal
bool LeftRepeating2(string &s){
    int count[256] = {0};
    for (int i = 0; i < s.length(); i++){
        count[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++){
        if(count[s[i]] > 1){
            return i;
        }
    }
    return -1;
}

// O(n) & O(256) 
bool LeftRepeating3(string &s){
    int count[256];
    int res = INT_MAX;
    fill(count, count + 256, -1);
    for(int i = 0; i < s.length(); i++)
    {
        int fi = count[s[i]];
        if(fi == -1){
            count[s[i]] = i;
        }
        else{
            res = min(res, count[s[i]]);
        }
    }
    return res == INT_MAX ? -1 : res;
}

// O(n) & O(256) best solution
bool LeftRepeating4(string &s){
    bool count[256];
    fill(count, count + 256, false);
    int res = -1;
    for (int i = s.length() - 1; i >= 0; i--){
        if(count[s[i]]){
            res = i;
        }
        else{
            count[s[i]] = true;
        }
    }
    return res;
}

int main(){
    srand(time(0));
    string s = "", sub = "";
    int n = rand() % 250;
    for (int i = 0; i < n; i++)
    {
        s += (char)('a' + rand() % 26);
    }
    cout << s << endl;
    cout<<"The left repeating letter is : "<<LeftRepeating4(s) << endl;
    return 0;
}








