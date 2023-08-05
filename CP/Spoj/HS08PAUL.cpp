#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'
using namespace std;

bool isPrime( int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3;i <= n/i;i += 2)
        if(n % i == 0) return false;
    
    return true;
}

vector<long long int> p;
void sieve(){
    int num;
    for(int i = 0 ; i * i < 10000000 ; i++){
        for(int j = 0 ; j*j*j*j < 10000000 ; j++){
            num = j*j*j*j + i*i ;
            if(isPrime(num)){
                p.push_back(num);
            }
        }
    }
    sort(p.begin(),p.end());
    unique(p.begin(),p.end());
}

int main(){
    fast;
    sieve();
    int t, n, lo, hi, mi;
    cin>>t;
    while(t--){
        cin>>n;
        if(n == 1) cout<<0<<endl;
        else{
            lo = 0, hi = (int)(p.size()) - 1;
            while (lo < hi){
                mi = (lo + hi + 1) / 2;
                if (p[mi] > n)
                    hi = mi - 1;
                else
                    lo = mi;
            }
            cout<<lo+1<<endl;
        }
    }
}