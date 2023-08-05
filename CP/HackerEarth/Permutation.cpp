#include <bits/stdc++.h>
using namespace std;
int n;
string s;
unordered_map<string, int> dist;
void solution()
{
    int t;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        s.push_back('0' + t);
    }
    queue<string> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        string p = q.front();
        q.pop();
        for(int i = 2; i < n+1; i++)
        {
            string tmp = p;
            reverse(tmp.begin(), tmp.begin() + i);
            // deb(tmp);
            if (dist.find(tmp) == dist.end())
            {
                dist[tmp] = 1 + dist[p];
                q.push(tmp);
            }
        }
    }
    sort(s.begin(), s.end());
    cout << dist[s];
}
signed main()
{
    long t = 1;
    while (t--)
        solution();
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// void solve(int n, vector<int> a, int &count){
//     if(is_sorted(a.begin(), a.end())) return;
//     count++;
//     vector<int> b = a;
//     for(int i = 0; i < n; i++){
//         reverse(b.begin(), b.begin() + i + 1);
//         solve(n, b, count);
//         solve(n, a, count);

//     }
//     // if(n == 1) return;
//     // int index = -1;
//     // int maxi = INT_MIN;
//     // for(int i = 0; i < n; i++){
//     //     cout << a[i] << " ";
//     //     if(a[i] > maxi){
//     //         maxi = a[i];
//     //         index = i;
//     //     }
//     // }
//     // cout << "\n";
//     // if(index == n-1){
//     //     solve(n-1, a, count);
//     // }
//     // else{
//     //     if(index != 0){
//     //         reverse(a.begin(), a.begin() + index + 1);
//     //         reverse(a.begin(), a.begin() + n);
//     //         count += 2;
//     //         for(int i = 0; i < n; i++){
//     //             cout << a[i] << " ";
//     //         }
//     //         cout << "\n";
//     //     }
//     //     else{
//     //         reverse(a.begin(), a.begin() + n);
//     //         count += 1;
//     //         for(int i = 0; i < n; i++){
//     //             cout << a[i] << " ";
//     //         }
//     //         cout << "\n";
//     //     }
//     //     solve(n-1, a, count);
//     // }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> a(n, 0);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int count = 0;
//     solve(n, a, count);
//     cout << count << "\n";
// }