#include <bits/stdc++.h>
using namespace std;
bool compare(auto p , auto q){
    return p.second > q.second;
}
int main(){
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        int x, y , z, p;
        cin >> s >> y >> z >> x >> p ;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}