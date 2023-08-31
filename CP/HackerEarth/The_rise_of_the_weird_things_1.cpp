#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    cin >> n;
    vector<int> even, odd;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        if(ele%2){
            odd.push_back(ele);
        }
        else{
            even.push_back(ele);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    int sum = 0;
    for(int i = 0; i < even.size(); i++){
        sum += even[i];
        cout << even[i] << " ";
    }
    cout  << sum << " ";
    sum  = 0;
    for(int i = 0; i < odd.size(); i++){
        sum += odd[i];
        cout << odd[i] << " ";
    }
    cout  << sum << endl;
}