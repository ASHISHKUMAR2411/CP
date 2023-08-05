#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin >> n; 
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[n];
    b[n - 1] = -1;
    stack<int> s;
    s.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--){
        if(a[i+1] > a[i]){
            int temp = s.top();
            s.push(a[i]);
            b[i] = temp;
        }
        else{
            while(!s.empty()){
                if(s.top() <= a[i]){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.empty()){
                s.push(a[i]);
                b[i] = -1;
            }
            else{
                int temp = s.top();
                s.push(a[i]);
                b[i] = temp;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if(b[i] == -1){
            while(!s.empty()){
                if(s.top() <= a[i]){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.empty()){
                b[i] = -1;
                s.push(a[i]);
            }
            else{
                // int temp = s.top();
                b[i] = s.top();
                s.push(a[i]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}