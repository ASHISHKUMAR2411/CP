#include<bits/stdc++.h> 
using namespace std;
void dfs(int s , vector<int>& vis , vector<int>adj[] , vector<int>& temp){
    vis[s] = 1; 
    temp.push_back(s); 
    for(int i = 0 ; i < adj[s].size() ; i++){ 
        if(vis[adj[s][i]] == 0) 
            dfs(adj[s][i] , vis , adj , temp); 
        } 
} 

void modify(vector<int>& a , vector<int>& b){
    vector<int>t; 
    for(auto it : b){
        t.push_back(a[it]); 
    } 
    sort(t.begin() , t.end()); 
    sort(b.begin() , b.end()); 
    for(int i = 0; i < t.size() ; i++){ 
        a[b[i]] = t[i]; 
    } 
} 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; 
    cin >> n; 
    vector<int>p(n); 
    for(int i = 0 ; i < n ; i++) 
        cin >> p[i]; 
    vector<int>adj[n]; 
    for(int i = 0 ; i < n; i++){ 
        string s; 
        cin >> s; 
        for(int j = 0 ; j < n ; j++) 
            if(s[j] == 'Y'){ 
                adj[i].push_back(j); 
            } 
    } 
    vector<int>vis(n , 0); 
    for(int i = 0 ; i < n ; i++){   
        if(vis[i] == 0){ 
            vector<int>temp; 
            dfs(i , vis , adj , temp); 
            modify(p , temp); 
        } 
    } 
    for(int i = 0 ; i < n ; i++) 
        cout<<p[i]<<" "; 
}

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int a[n+1];
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     vector<int> adj[n+1];
    
//     for(int i = 1; i <= n; i++){
//         string s;
//         cin >> s;
//         for(int j = 1; j <= n; j++){
//             if(s[j-1] == 'Y'){
//                 // se.insert(i);
//                 // se.insert(j);
//                 adj[i].push_back(j);
//             }
//         }
//     }
//     vector<bool> vis(n + 1, false);
//     for(int i = 1; i <= n; i++){
//         if(!vis[i]){
//             vis[i] = true;
//             set<int> se;
//             se.insert(i);
//             for(auto it : adj[i]){
//                 if(!vis[it]){
//                     vis[it] = true;
//                     se.insert(it);
//                 }
//             }
//             vector<int> arr;
//             for(auto it : se){
//                 arr.push_back(a[it]);
//             }
//             sort(arr.begin(), arr.end());
//             int j = 0;
//             for(auto it : se){
//                 // cout << it << " ";
//                 a[it] = arr[j];
//                 j++;
//             }
//         }
//         // cout << endl;
//     }
    
    
//     // for(auto it: adj){
//     //     for(auto i : it){
//     //         cout << i << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // vector<bool> vis(n + 1, false);
//     // for(int i = 1; i <= n; i++){
//     //     queue<int> q;
//     //     q.push(i);
//     //     while(!q.empty()){
//     //         int top = q.front();
//     //         bool flag = false;
//     //         q.pop();
//     //         for(auto it : adj[top]){
//     //             if(a[it] < a[top] and it > top){
//     //                 q.push(it);
//     //                 swap(a[it], a[top]);
//     //                 flag = true;
//     //                 // break;
//     //             }
//     //         }
//     //         if(flag) q.push(top);
//     //     }
//     // }
//     for(int i = 1; i <= n; i++){
//         cout << a[i] << " ";
//     }
//     cout << endl;
    
// }