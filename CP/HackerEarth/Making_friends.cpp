#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m; 
        cin >> n >> m;
        if(n%2){ cout << "No\n"; continue;}
        n = n/2;
        if(n >= m) cout << "Yes\n";
        else cout << "No\n";
        // cout << s.size() << "\n";
    }
}