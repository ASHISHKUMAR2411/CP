#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a[2] = {0};
        for(int i = 0; i < n; i++){
            if(s[i] == '0') a[0]++;
            else a[1]++;
        }
        int x = 0;
        int sum = 0;
        if(a[1]){
            x = 1;
            sum = 1;
            a[1]--;
        }
        else{
            x = 0;
            sum = 0; 
            a[0]--;
        }
        while(a[1] > 0 or a[0] > 0){
            if(x == 1){
                if(a[0] > 0){
                    a[0]--;
                    sum += 1;
                }
                else if(a[1] > 0){
                    a[1]--;
                    x = 0;
                }
            }
            else{
                if(a[1] > 0){
                    sum += 1;
                    a[1]--;
                    x = 1;
                }
                else if(a[0] > 0){
                    x = 0;
                    a[0]--;
                }
            }
        }
        cout << sum << "\n";

    }
}