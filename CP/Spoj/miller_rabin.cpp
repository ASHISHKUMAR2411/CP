    #include <bits/stdc++.h>
    #define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #define ulli unsigned long long int
    #define endl '\n'
    #define vi vector<int>
    using namespace std;

    ulli mul(ulli a , ulli b , ulli mod){
        ulli res = 0;
        while(b){
            if(b&1)
                res = (res + a)%mod;
            a = (2*a)%mod;
            b >>= 1;
        }
        return res;
    }

    ulli power(ulli a , ulli b , ulli mod ){
        ulli res = 1;
        while(b){
            if(b&1)
                res = mul(res,a,mod);
            a = mul(a,a,mod);
            b>>=1;
        }
        return res;
    }

    bool check(ulli n , int i , ulli d , int s){
        ulli x = power(i,d,n);
        if(x ==1 || x == n-1)
            return false;
        for(int j = 1;j<s;j++){
            x = mul(x,x,n);
            if(x == n-1)
                return false;
        }
        return true;
    }

    bool miller_rabin(ulli n){
        if(n<4)
            return (n == 2 || n == 3);
        int s = 0;
        ulli d = n-1;
        while((d&1) == 0){
            d>>=1;
            s++;
        }
        vi v = {2,3,5,7,11,13,17,19,23,29,31,37};
        for(int i: v){
            if(n==i) return true;
            if(check(n,i,d,s))
                return false;
        }
        return true;
    }
    int main(){
        fast;
        ulli n;
        int t;
        cin>>t;
        while(t--){
            cin>>n;
            if(miller_rabin(n))
                cout << "YES" << endl;
            else cout<<"NO"<< endl;
        }
    }