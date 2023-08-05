#include<bits/stdc++.h> 
using namespace std; 
const int N = 1e3+1; 
vector<int> g[N];  
// input array 
int vis[N]; 
// visiting array 
int level[N];       
// level from source 
vector<int> sp(N, 0); 
// shortest path from source 
void bfs(int vertx){     
    queue<int> q;     
    q.push(vertx);     
    vis[vertx] = 1;     
    level[vertx] = 0;     
    sp[vertx] = -1;     
    while(!q.empty()){         
        vertx = q.front();        
        q.pop();         
        for(auto child: g[vertx]){             
            if(!vis[child]){                 
                q.push(child);                 
                vis[child] = 1;                 
                sp[child] = vertx;                 
                level[child] = level[vertx] + 1;             
            }         
        }     
    } 
} 
signed main(){     
    int n, m, t, c;     
    cin >> n >> m >> t >> c;     
    for(int i=0; i < m; i++){         
        int u, v;         
        cin >> u >> v;         
        g[u].push_back(v);         
        g[v].push_back(u);     
    }     
    int source, dest;     
    cin >> source >> dest;     
    sort(g[source].begin(),g[source].end());  
    // sort source's children     
    sort(g[dest].begin(),g[dest].end()); 
    // sort destination children     
    bfs(source);  //  bfs on source     
    cout << (level[dest] + 1) << endl;  
    // number of cities needs to be flown over     
    int parent = dest;     
    vector<int> path;     
    while(parent != -1){         
        path.push_back(parent); 
        // building path from parents         
        parent = sp[parent];     
    }     
    reverse(path.begin(),path.end());     
    for(auto val : path){         
        cout << val << " ";     
    }     
    cout << endl; 
}
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, m, c, t;
//     cin >> n >> m >> c >> t;
//     vector<pair<int,int>> adj[n+1];
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back({v, c});
//         adj[v].push_back({u, c});
//     } 
//     // for(int i = 1; i <= n; i++){
//     //     sort(adj[i].begin(), adj[i].end(), greater<pair<int,int>>());
//     // }
//     int s, e;
//     cin >> s >> e;
//     sort(adj[s].begin(), adj[s].end());
//     sort(adj[e].begin(), adj[e].end());
//     priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
//     pq.push({0, {s, -1}});
//     vector<int> dist(n+1, 1e9);
//     vector<int> parent(n+1, -1);
//     dist[s] = 0;
//     while(!pq.empty()){
//         auto top = pq.top();
//         pq.pop();
//         int d = top.first;
//         int node = top.second.first;
//         int p = top.second.second;
//         // if(node == e) break;
//         for(auto it : adj[node]){
//             int no = it.first;
//             int dis = it.second;
//             if(no == p) continue;
//             if(dist[no] > (d + dis)){
//                 dist[no] = d + dis;
//                 parent[no] = node;
//                 pq.push({dist[no], {no, node}});
//             }
//         }
//     }
//     vector<int> ans;
//     while(parent[e] != -1){
//         ans.push_back(e);
//         e = parent[e];
//         if(e == s) break;
//     }
//     ans.push_back(s);
//     reverse(ans.begin(), ans.end());
//     cout << ans.size() << "\n";
//     for(auto it : ans){
//         cout << it << " ";
//     }
// }