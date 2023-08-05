#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >>m;
    vector<int> adj(n+1,0);
    // memset(adj, 0, sizeof(adj));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u]++;
        adj[v]++;
    }
    long long int count = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (n - 1 - adj[i])*adj[i];
    }
    count = ((n *1ll*(n-1)*1ll*(n-2)))/6;
    cout << count - ans/2 << endl;
}
