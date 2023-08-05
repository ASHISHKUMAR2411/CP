#include<bits/stdc++.h>
using namespace std;
vector<int>a[10001];
int v[10001]={0},b[10001]={0};
void dfs(int s)
{
    v[s]=1;
    for(int i=0;i<a[s].size();i++)
    {
        if(v[a[s][i]]==0)
        dfs(a[s][i]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,count=0;
        int n,f,s;
        cin>>n>>f>>s;
        for(i=0;i<=n;i++)
        {
            a[i].clear();
            v[i]=0;
            b[i]=0;
        }
        for(i=0;i<f;i++)
        {
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
        }
        for(i=0;i<s;i++)
        cin>>b[i];
        for(i=0;i<s;i++)
        {
            if(v[b[i]]==0)
            dfs(b[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(v[i]==1)
                count++;
        }
        cout<<count<<"\n";
    }
}