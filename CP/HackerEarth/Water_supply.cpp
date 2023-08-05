#include <bits/stdc++.h>

#define IOS \
ios::sync_with_stdio(0); \
cin.tie(0); \
cout.tie(0);

#define endl "\n"

#define ll long long

#define pb push_back

#define mp make_pair

#define f1(i, a, b) for (int i = a; i < b; i++)

#define f2(i, a, b) for (int i = a; i > b; i--)

#define ff first

#define ss second

#define lb lower_bound

#define ub upper_bound

#define mod 1000000007

// insert m.insert({ , });

// make_pair( , );

using namespace std;

vector<ll> arr[200001];

ll ar[200001];

ll vis[200001];

int col[20000];

int cc_size; //for size of connected components.

int maxD;

ll cnt;

int max_node;

void dfs(int node)

{

cnt++;

if (ar[node] == 1)

return;

vis[node] = 1;

for (int child : arr[node])

{

if (vis[child] == 0)

{


 

dfs(child);

}

}

}

int main()

{

IOS;

// for(int i=0;i<n;i++){

// arr[i].clear();

// vis[i]=0;

ll n;

cin >> n;

for (ll i = 1; i <= n - 1; i++)

{

ll a, b;

cin >> a >> b;

arr[a].pb(b);

arr[b].pb(a);

}

for (ll i = 1; i <= n; i++)

{

cin >> ar[i];

} //we store 1 and 0 in index of given vertices.

ll res = INT_MIN;

for (ll i = 1; i <= n; i++)

{

if (vis[i] == 0)

{

cnt = 0;

dfs(i);

res = max(res, cnt);

}

}

cout << res << endl;

}
// #include<bits/stdc++.h>
// using namespace std;
// #define IOS \
// ios::sync_with_stdio(0); \
// cin.tie(0); \
// cout.tie(0);
// void dfs(int index, int parent, vector<int> adj[], int &count, vector<int> &blocked, vector<bool> &vis){
//     count++;
//     if(blocked[index] == 1) return;
//     vis[index] = true;
//     for(auto it : adj[index]){
//         if(it == parent) continue;
//         if(!vis[it])
//             dfs(it, index, adj, count, blocked, vis);
//     }
//     return;
// }
// int main(){
//     IOS;
//     int n;
//     cin >> n;
//     vector<int> adj[n + 1];
//     for(int i = 0 ; i < n-1; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> blocked(n + 1);
//     for(int i = 1; i <= n; i++){
//         cin >> blocked[i];
//     }
//     int maxi = INT_MIN;
//     vector<bool> vis(n + 1, false);
//     for(int i = 1; i <= n; i++){
//         if(!vis[i]){
//             int count = 0;
//             dfs(i, -1, adj, count, blocked, vis);
//             // cout << i << " " << count << "\n";
//             maxi = max(maxi, count);
//         }
//     }
//     cout << maxi << "\n";
// }