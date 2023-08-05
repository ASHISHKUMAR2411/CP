#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n; 
    vector<int> arr(n+1, INT_MAX);
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        arr[u] = min(arr[u], w);
        arr[v] = min(arr[v], w);
    }
    int q;
    cin >> q;
    vector<int> dummy = arr;
    for(int i = 0; i < q; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(arr[u] > w or arr[v] > w){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}