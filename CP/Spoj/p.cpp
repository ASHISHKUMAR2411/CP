#include<bits/stdc++.h>
using namespace std;
int maxN = 1e8;
vector<char> prime(maxN+1, true);
vector<int> onlyprime;
int main(){
    prime[0] = prime[1] = false;
    for(int i = 2; i*i<=maxN; i++){
        if(prime[i]){
            for(int j = i*i;j<=maxN;j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i = 2 ; i<=maxN; i++){
        if(prime[i]){
            onlyprime.push_back(i);
        }
    }
    for(int i = 1;i<(int)(onlyprime.size()); i+=100){
        cout<<onlyprime[i-1]<<"\n";
    }
}