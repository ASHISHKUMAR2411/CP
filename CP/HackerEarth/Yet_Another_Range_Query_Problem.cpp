#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q; 
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        int count =0;
        for(int i = l; i <= r and i <= n; i++){
            if(arr[i] >= l and arr[i] <= r){
                count++;
            }
        }
        cout << count << endl;
    }
}