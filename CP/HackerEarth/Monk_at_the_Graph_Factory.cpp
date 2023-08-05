#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n; 
    int sum = 0;
    for(int i = 0; i < n; i++){
        int u;
        cin >> u;
        sum += u;
    }
    if(sum%2){
        cout << "No\n";
    }
    else{
        sum = sum/2;
        if(sum == n-1) cout << "Yes\n";
        else cout << "No\n";
    }

}