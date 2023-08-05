#include<bits/stdc++.h>
using namespace std;
vector<int>p,q;
void dfs(int node, vector<bool> &vis, vector<int> adj[],vector<int> &a,vector<int> &b)
{
    vis[node] = true;
    p.push_back(a[node]);
    q.push_back(b[node]);
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it, vis, adj, a, b);
        }
    }
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> a(n+1), b(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
        }
        vector<int> adj[n+1];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n+1, false);
        bool ans=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                p.clear();
                q.clear();
                dfs(i, vis, adj, a, b);
                sort(p.begin(),p.end());
                sort(q.begin(),q.end());
                if(p!=q)
                {
                    ans=0;
                }
            }
        }
        if(ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

}