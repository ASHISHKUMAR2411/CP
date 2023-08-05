#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
const ll M=1000003;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a[M+1];
    a[0]=1;
    for(ll i=1;i<=M;i++){
        a[i]=(i*a[i-1])%M;
    }
    ll t;
    scanf("%ld",&t);
    while(t--)
    {
        ll x,y;
        scanf("%ld %ld",&x,&y);
        if(y>M)
        printf("0\n");
        else
        cout<<(x*a[y])%M<<"\n";
    }
}
    #include <bits/stdc++.h>
    #define SpeeD ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    #define ll long long
    #define endl '\n'
    using namespace std;
     ll n , t , k  , m;
      ll a , b ;
    ll mod = 1e6 +3;
    ll fast (ll a , ll n)
    {
        ll res = 1 ;
        
        while (n){
            
            if (n&1)
             res=(res%mod * a%mod )%mod;
             
            a=(a%mod*a%mod)%mod;
            
           
            
            n>>=1;
        }
        return res%mod;
    }
 
    int main(){
        SpeeD;
        cin >> t;
        ll a[(int)1e5 + 1];
        a[0] = 1;
        for (int i = 1  ; i <= 1e5 ;i++){
          a[i] = (a[i-1]%mod * i %mod ) % mod;
        }
        
      while (t--)
      {
          cin >> n >> k ;
          ll ans=  1;
          if (n > mod)cout << 0 << endl;
          else
        //  cout << a[n];
          
          cout << (a[n] % mod * k % mod)%mod << endl;
      }
    }