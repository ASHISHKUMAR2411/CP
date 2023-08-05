#include<bits/stdc++.h>
using namespace std;
string dfs(int index, int parent, vector<string> &ans, vector<int> adj[], vector<string> &val){
    string temp = "";
    for(auto it : adj[index]){
        if(it == parent) continue;
        temp += dfs(it, index, ans, adj, val);
    }
    temp += val[index];
    return ans[index] = temp;
}
int main(){
    int n, q;
    cin >> n >> q;
    vector<string> val(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    vector<int> adj[n + 1];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<string> ans(n + 1);
    dfs(1, -1, ans, adj, val);
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        string s;
        cin >> s;
        string t = ans[x];
        vector<int> temp(26, 0), imp(26, 0);
        for(int i = 0; i < s.size(); i++){
            imp[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            temp[t[i] - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(imp[i]){
                imp[i] = imp[i] - temp[i];
                if(imp[i] > 0) count += imp[i];
            }
        }
        cout << count << "\n";
    }
}