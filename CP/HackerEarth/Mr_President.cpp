#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[], vector<long long> &ans)
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            ans.push_back(cost);
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost, k;
    initialize();
    cin >> nodes >> edges >> k;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    vector<long long> ans;
    minimumCost = kruskal(p, ans);
    // cout << minimumCost << endl;
    // for(auto it : ans){
    //     cout << it << " ";
    // }
    bool flag = false;
    int count = 0;
    for(int i = 1; i <= nodes; i++){
        if(id[i] == i)
            count++;
    }
    if(count > 1){
        cout << -1 << endl;
    }
    else if(k < ans.size()){
        cout << -1 << endl;
    }
    else{
        int n = ans.size();
        for(int i = 1; i < n; i++){
            ans[i] += ans[i-1];
        }
        // for(auto it : ans){
        //     cout << it << " ";
        // }
        int answer = n; 
        for(int i = 0; i < n; i++){
            if((ans[i] + n - 1 - i) > k) break;
            answer = n - 1 - i;
        }
        cout << answer << endl;
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// const long long MAX = 1e6 + 1;
// long long id[MAX], nodes, edges;
// pair <long long, pair<long long, long long> > p[MAX];
// void initialize()
// {
//     for(long long i = 0;i < MAX;++i)
//         id[i] = i;
// }

// long long root(long long x)
// {
//     while(id[x] != x)
//     {
//         id[x] = id[id[x]];
//         x = id[x];
//     }
//     return x;
// }

// void union1(long long x, long long y)
// {
//     long long p = root(x);
//     long long q = root(y);
//     id[p] = id[q];
// }

// long long kruskal(pair<long long, pair<long long, long long> > p[], vector<long long> &ans)
// {
//     long long x, y;
//     long long cost, minimumCost = 0;
//     for(long long i = 0;i < edges;++i)
//     {
//         // Selecting edges one by one in increasing order from the beginning
//         x = p[i].second.first;
//         y = p[i].second.second;
//         cost = p[i].first;
//         // Check if the selected edge is creating a cycle or not
//         if(root(x) != root(y))
//         {
//             ans.push_back(cost);
//             minimumCost += cost;
//             union1(x, y);
//         }    
//     }
//     return minimumCost;
// }

// int main(){
//     long long n, m, k;
//     cin >> n >> m >> k;
//     initialize();
//     for(long long i = 0; i < m; i++){
//         long long weight, x, y;
//         cin >> x >> y >> weight;
//         p[i] = make_pair(weight, make_pair(x, y));
//     } 
//     sort(p, p + edges);
//     vector<long long> ans;
//     long long minimumCost = kruskal(p, ans);
//     for(auto it : ans){
//         cout << it << endl;
//     }
    // if(minimumCost <= k){
    //     cout << 0 << endl;
    // }
    // else if(k < ans.size()){
    //     cout << -1 << endl;
    // }
    // else{
    //     for(int i = 1; i < n; i++){
    //         ans[i] += ans[i-1];
    //     }
    //     int answer = 0; 
    //     for(int i = 0; i < n; i++){
    //         if((ans[i] + n - 1 - i) > k) break;
    //         answer = n - 1 - i;
    //     }
    //     cout << answer << endl;
    // }
// }



