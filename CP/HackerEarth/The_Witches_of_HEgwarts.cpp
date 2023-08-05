#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,flag=0;
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map <int,int> m;
        queue <int> q;
        m[n]=0;
        q.push(n);
        int p;
        while(!q.empty())
        {
            p = q.front();
            if(p==1)
            break;
            q.pop();
            if(p%3==0)
            {
                if(m[p/3]==0)
                {
                    m[p/3]=m[p]+1;
                    q.push(p/3);
                }
            }
            if(p%2==0)
            {
                if(m[p/2]==0)
                {
                    m[p/2]=m[p]+1;
                    q.push(p/2);
                }
            }
            if(m[p-1]==0)
            {
                m[p-1]=m[p]+1;
                q.push(p-1);
            }
        }
        //cout<<endl;
        cout<<m[1]<<endl;
    }   
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         if(n == 1){
//             cout << 0 << endl;
//             continue;
//         }
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
//         unordered_map<int, int> mp;
//         q.push({n, 0});
//         mp[n] = 0;
//         int count = INT_MAX;
//         while(!q.empty()){
//             auto top = q.top();
//             q.pop();
//             int node = top.first;
//             int chance = top.second;
//             if(node == 1){
//                 count = min(count, chance);
//                 continue;
//             }
//             if(node%3 == 0){
//                 if(mp.find(node/3) == mp.end()){
//                     mp[node/3] = chance + 1; 
//                     q.push({node/3, chance + 1});
//                 }
//                 else{
//                     if(mp[node/3] > chance + 1){
//                         mp[node/3] = chance + 1; 
//                         q.push({node/3, chance + 1});
//                     }
//                 }
//             }
//             if((node - 1)%3 == 0){
//                 if(mp.find(node/3) == mp.end()){
//                     mp[node/3] = chance + 2; 
//                     q.push({node/3, chance + 2});
//                 }
//                 else{
//                     if(mp[node/3] > chance + 2){
//                         mp[node/3] = chance + 2; 
//                         q.push({node/3, chance + 2});
//                     }
//                 }
//             }
//             if((node - 2) > 1 and (node - 2)%3 == 0){
//                 if(mp.find(node/3) == mp.end()){
//                     mp[node/3] = chance + 3; 
//                     q.push({node/3, chance + 3});
//                 }
//                 else{
//                     if(mp[node/3] > chance + 3){
//                         mp[node/3] = chance + 3; 
//                         q.push({node/3, chance + 3});
//                     }
//                 }
//             }
//             else if(node%2 == 0){
//                 if(mp.find(node/2) == mp.end()){
//                     mp[node/2] = chance + 1; 
//                     q.push({node/2, chance + 1});
//                 }
//                 else{
//                     if(mp[node/2] > chance + 1){
//                         mp[node/2] = chance + 1; 
//                         q.push({node/2, chance + 1});
//                     }
//                 }
//                 // q.push({node/2, chance + 1});
//             }
//             else if((node - 1)%2 == 0 and (node - 1) > 1){
//                 if(mp.find(node/2) == mp.end()){
//                     mp[node/2] = chance + 2; 
//                     q.push({node/2, chance + 2});
//                 }
//                 else{
//                     if(mp[node/2] > chance + 2){
//                         mp[node/2] = chance + 2; 
//                         q.push({node/2, chance + 2});
//                     }
//                 }
//             }
//         }
//         cout << count << endl;
//     }
// }