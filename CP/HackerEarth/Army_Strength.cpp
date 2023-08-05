#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--){
        int g, m;
        cin >> g >> m;
        int max_g = INT_MIN, max_m = INT_MIN;
        for (int i = 0; i < g; i++){
            int x = 0;
            cin >> x;
            max_g = max(max_g, x);
        }
        for (int i = 0; i < m; i++){
            int x = 0;
            cin >> x;
            max_m = max(max_m, x);
        }
        if(max_g >= max_m){
            cout << "Godzilla\n";
        }
        else{
            cout << "MechaGodzilla\n";
        }
    }
    return 0;
}