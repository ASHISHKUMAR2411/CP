#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> input(n);
    map<char, int> mp;
    for(int i = 0; i < n; i++){
        cin >> input[i];
        for(int j = 0; j < input[i].size(); j++){
            mp[input[i][j]] = 1;
        }
    }
    vector<int> adj[26];
    vector<int> vis(26, 0);
    for(int k = 0; k < n - 1; k++){
        string u = input[k];
        string v = input[k + 1];
        int i = 0, j  = 0;
        while(i < u.size() and j < v.size() and u[i] == v[j]){
            i++;
            j++;
        }
        if(i != u.size() and j != v.size()){
            adj[v[j] - 'a'].push_back(u[i]- 'a');
            vis[v[j] - 'a']++;
            vis[u[i] - 'a']++;
            queue<pair<int,int>> q;
            int val = mp[v[j]];
            q.push({v[j] - 'a', val});
            while(!q.empty()){
                auto temp = q.front();
                q.pop();
                int node = temp.first;
                int le = temp.second;
                for(auto it : adj[node]){
                    if(mp[it + 'a'] < le + 1){
                        mp[it + 'a'] = le + 1;
                        q.push({it, le + 1});
                    }
                }
            }
        }
    }
    // for(auto it : mp){
    //     // maxi = max(it.second, maxi);
    //     cout << it.first << " " << it.second << "\n";
    // }
    for(int k = 0; k < n - 1; k++){
        string u = input[k];
        string v = input[k + 1];
        int i = 0, j  = 0;
        while(i < u.size() and j < v.size() and u[i] == v[j]){
            i++;
            j++;
        }
        if(i != u.size() and j != v.size()){
            if(mp[v[j]] != (mp[u[i]] - 1) and vis[v[j] - 'a'] == 1){
                mp[v[j]] = mp[u[i]] - 1;
            }
        }
    }
    int maxi = 0;
    for(auto it : mp){
        maxi = max(it.second, maxi);
        // cout << it.first << " " << it.second << "\n";
    }
    for(int i = 0; i < 26; i++){
        if(vis[i] == 0 and mp.find(i + 'a') != mp.end() and mp[i + 'a'] == 1){
            mp[i + 'a'] = maxi;
        }
    }
    vector<char> level[26];
    for(auto it : mp){
        level[it.second].push_back(it.first);
    }
    for(int i = 25; i >= 0; i--){
        if(level[i].size()){
        sort(level[i].begin(), level[i].end());
        for(auto it : level[i]){
            cout << it;
        }
        cout << "\n";
        }
    }

    // for(int k = 0; k < n - 1; k++){
    //     string u = input[k];
    //     string v = input[k + 1];
    //     int i = 0, j  = 0;
    //     while(i < u.size() and j < v.size() and u[i] == v[j]){
    //         i++;
    //         j++;
    //     }
    //     if(i > 0 and vis[u[i - 1] - 'a'] == 0){
    //         if(mp[u[i-1]] < mp[v[j]]){

    //         }
    //     }
    // }
    
    // vector<int> adj[26];
    // vector<int> in(26, 0), out(26, 0);
    // for(int k = 0; k < n - 1; k++){
    //     string u = input[k];
    //     string v = input[k + 1];
    //     int i = 0, j  = 0;
    //     while(i < u.size() and j < v.size() and u[i] == v[j]){
    //         i++;
    //         j++;
    //     }
    //     if(i != u.size() and j != v.size()){
    //         in[v[j] - 'a']++;
    //         out[u[i] - 'a']++;
    //         adj[u[i] - 'a'].push_back(v[j] - 'a');
    //     }
    //     else if(i == u.size()){
    //         in[v[j] - 'a']++;
    //         out[u[i - 1] - 'a']++;
    //         adj[u[i - 1] - 'a'].push_back(v[j] - 'a');
    //     }
    //     else{
    //         in[v[j - 1] - 'a']++;
    //         out[u[i] - 'a']++;
    //         adj[u[i] - 'a'].push_back(v[j - 1] - 'a');
    //     }
    // }
    // // for(int i = 0; i < 26; i++){
    // //     if(adj[i].size() != 0){
    // //     cout << (char)(i + 'a') << ":";
    // //     for(auto it : adj[i]){
    // //         cout << (char)(it + 'a') << " ";
    // //     }
    // //     cout << endl;
    // //     }
    // // }
    // // for(int i = 0; i < 26; i++){
    // //     if(in[i] or out[i])
    // //     cout << (char)(i + 'a') << ":" << in[i] << " " << out[i] << endl;
    // // }
    // // starting point
    // int st = -1;
    // vector<char> ans;
    // vector<int> vis(26, 0);
    // vector<char> level[27]; 
    // for(int i = 0; i < 26; i++){
    //     if(in[i] == 0 and out[i] != 0){
    //         vis[i] = 1;
    //         int le = 1;
    //         level[le].push_back(i + 'a');
    //         ans.push_back(i + 'a');
    //         queue<pair<int,int>> q;
    //         q.push({i, le});
    //         while(!q.empty()){
    //             auto top = q.front();
    //             q.pop();
    //             int node = top.first;
    //             for(auto it : adj[top]){
    //                 if(in[it] == 1 and vis[it] == 0){
    //                     q.push(it);
    //                     vis[it] = 1;
    //                     ans.push_back(it + 'a');
    //                     in[it]--;
    //                     out[top]--;
    //                 }
    //                 else in[it]--;
    //             }
    //         }
    //     }
    // }
    // for(auto it : ans){
    //     cout << it << "\n";
    // }
    // cout << endl;
}