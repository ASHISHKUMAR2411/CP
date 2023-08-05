#include<bits/stdc++.h>
using namespace std;
bool isPrime(int N){
    bool flag = 1;
    double sqroot = sqrt(N);
    // Iterate from 2 to sqrt(n)
    for (int i = 2; i <= sqroot; i++)
    {
        // If n is divisible by any number between 2 and
        // sqrt(n), it is not prime
        if (N % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main(){
    vector<int> prime_no(1e6 + 1, 0);
    prime_no[2] = 1;
    prime_no[3] = 1;
    for(int i = 4; i <= 1e6; i++){
        if(isPrime(i)){
            prime_no[i] = 1;
        }
    } 
    for(int i = 1; i <= 1e6; i++){
        prime_no[i] += prime_no[i-1];
    } 
    // cout << "{";
    // for(auto it : prime_no){
    //     cout << it << ",";
    // }
    // cout << "}";
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << prime_no[n] << "\n";
    }
}