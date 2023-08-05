#include<bits/stdc++.h>
using namespace std;
string ans = "";
int lps(string& s1, string& s2, int n1, int n2, unordered_map<string, int> &mp)
{
    if (n1 == 0 || n2 == 0) {
        return 0;
    }
    string s = to_string(n1) + " " + to_string(n2);
    if (mp.find(s) != mp.end()) {
        return mp[s];
    }
    if (s1[n1 - 1] == s2[n2 - 1]) {
        ans.push_back(s1[n1 - 1]);
        return mp[s] = 1 + lps(s1, s2, n1 - 1, n2 - 1, mp);
    }
    else {
        return mp[s] = max(lps(s1, s2, n1 - 1, n2, mp),
                                lps(s1, s2, n1, n2 - 1, mp));
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ans = "";
        string dummy = s;
        reverse(dummy.begin(), dummy.end());
        int n = dummy.size();
        // string ans = ""; 
        unordered_map<string, int> mp;
        int lis = lps(s, dummy, n, n, mp);
        string dum = ans.substr(0, lis/2.0);
        reverse(dum.begin(), dum.end());
        if(lis%2)
            ans = ans.substr(0, ceil(lis/2.0))+dum;
        else{
            ans = ans.substr(0, lis/2.0)+dum;
        }
        int i = 0, j = n-1, k = ans.size() - 1;
        while(ans[i] == s[i] && i < n and i < ans.size()){
            i++;
        }
        while(ans[k] == s[j] and k >= 0 and j >= 0){
            j--;
            k--;
        }
        cout << i << " " << j << endl;
        if(i == ans.size() || k == -1){
            cout << ans << "\n";
            continue;
        }
        
    }
}