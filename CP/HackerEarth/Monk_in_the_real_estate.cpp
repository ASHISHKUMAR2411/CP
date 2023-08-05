#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        set<int> s;
        for(int i =0; i < n; i++){
            int u, v;
            cin >> u >> v;
            s.insert(u);
            s.insert(v);
        }
        cout << s.size() << "\n";
    }
}