#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int st = -1;
    vector<int> start(n + 1, -1), end(n + 1, -1), arr(n + 1, -1);
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++){
        cin >> start[i];
        mp[start[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> end[i];
    }
    int parent = 0;
    for(int i = 0; i < n; i++){
        arr[mp[i]] = parent; 
        parent = mp[i];
        while(end[parent] == i + 1){
            if(arr[parent] != -1)
                parent = arr[parent];
            else break;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}