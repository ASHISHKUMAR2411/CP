#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>pii;
const int mx=1e6;
bool vis[mx];
int parent[mx];
vector<pii>adj[mx];
int dist[mx];

void dijkstra(int source)
{
    priority_queue<pii>q;
    dist[source]=1000000007;
    parent[source]=source;
    q.push(make_pair(dist[source],source));
    while(!q.empty())
    {
        pii pq=q.top();
        q.pop();
        int u=pq.second;
        if(vis[u])
        {
            continue;
        }
        vis[u]=true;
        for(auto it : adj[u])
        {
            int v=it.second;
            int capacity=it.first;
            int lwmn=min(dist[u],capacity);
            if(lwmn>dist[v])
            {
                parent[v]=u;
                dist[v]=lwmn;
                q.push(make_pair(dist[v],v));
            }
        }
    }
}

int main()

{
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
        dist[i]=0;
        vis[i]=false;
    }
    int s,d,c;
    while(m--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }
    cin>>s>>d>>c;
    dijkstra(s);
    vector<int>ans;
    ans.push_back(d);
    int t=d;
    while(t!=s)
    {
        t=parent[t];
        ans.push_back(t);
    }
    for(int j=ans.size()-1;j>=0;j--)
    {
        cout<<ans[j]<<" ";
    }
    cout<<endl;
    int total_people_can_be_travel_this_route = dist[d]-1;
    if(c%total_people_can_be_travel_this_route==0)
    {
        cout<<(c/total_people_can_be_travel_this_route)<<endl;
    }
    else
    {
        cout<<(c/total_people_can_be_travel_this_route)+1<<endl;
    }

    return 0;
}
// // #include<bits/stdc++.h>
// // using namespace std;
// // int main(){
// //     int n, m;
// //     cin >> n >> m;
// //     vector<pair<int,int>> adj[n+1];
// //     for(int i = 0; i < m; i++){
// //         int from, to, passenger;
// //         cin >> from >> to >> passenger;
// //         adj[from].push_back({to, passenger});
// //         adj[to].push_back({from, passenger});
// //     } 
// //     int from, to, passenger;
// //     cin >> from >> to >> passenger;
// //     vector<int> dist(n + 1, INT_MIN);
// //     vector<int> parent(n + 1, -1);
// //     priority_queue<vector<int>> pq;
// //     pq.push({0, from});
// //     dist[from] = 0;
// //     while(!pq.empty()){
// //         auto top = pq.top();
// //         pq.pop();
// //         int node = top.second;
// //         for(auto it : adj[node]){
// //             int nd = it.first;
// //             int capacity = it.second;
// //             if(dist[nd] < capacity){
// //                 parent[nd] = node;
// //                 dist[nd] = capacity;
// //                 pq.push({capacity, nd});
// //             }
// //         }
// //     }
// // }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int numberOfCity, numberOfRoads;
//     cin >> numberOfCity >> numberOfRoads;
//     vector<pair<int, vector<int>>> tripsCount(numberOfCity+1);
//     for(int i = 1; i <= numberOfCity; i++){
//         vector<int> arr;
//         tripsCount[i] = {1e9, arr};
//     } 
//     vector<pair<int,int>> adj[numberOfCity+1];
//     for(int i = 0; i < numberOfRoads; i++){
//         int from, to, passenger;
//         cin >> from >> to >> passenger;
//         adj[from].push_back({to, passenger});
//         // adj[to].push_back({from, passenger});
//     } 
//     int from, to, numberOfPassenger;
//     cin >> from >> to >> numberOfPassenger;
//     priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
//     pq.push({0, from});
//     tripsCount[from].first = 0;
//     tripsCount[from].second.push_back(from);
//     vector<bool> vis(numberOfCity + 1, false);
//     while(!pq.empty()){
//         auto top = pq.top();
//         pq.pop();
//         int node = top[1];
//         if(vis[node]) continue;
//         vis[node] = true;
//         for(auto it : adj[node]){
//             int nd = it.first;
//             int ps = it.second;
//             int turn = ceil((float)(numberOfPassenger)/ps);
//             int dummyPassenger = numberOfPassenger + turn;
//             int t = ceil((float)(dummyPassenger)/ps);
//             if(t < tripsCount[nd].first){
//                 // cout << nd << " " << dummyPassenger;
//                 // cout << ":" << t << endl;
//                 tripsCount[nd].first = t;
//                 pq.push({tripsCount[nd].first, nd});
//                 vector<int> arr = tripsCount[node].second;
//                 arr.push_back(nd);
//                 tripsCount[nd].second = arr;
//             }
//             else if((t) == tripsCount[nd].first){
//                 vector<int> arr = tripsCount[node].second;
//                 arr.push_back(nd);
//                 int i = 0;
//                 while(i < arr.size() and arr[i] < tripsCount[nd].second[i]){
//                     i++;
//                 }
//                 if(i == arr.size()){
//                     tripsCount[nd].second = arr;
//                 }
//             }
//         }
//     }
//     int maxTrip = INT_MIN;
//     for(auto it : tripsCount[to].second){
//         cout << it << " " << tripsCount[it].first;
//         cout << endl;
//         maxTrip = max(maxTrip, tripsCount[it].first);
//     }
//     cout << endl << maxTrip << endl;
//     return 0;
// }