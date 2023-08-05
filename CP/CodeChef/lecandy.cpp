#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define endl '\n'
using namespace std;
int main() {
    fast;
	int t,n,c,sum =0;
    cin>>t;
    while(t--){
        cin>>n>>c;
        int A[n];
        for(int i = 0;i<n;i++){
            cin>>A[i];
        }
        sum = 0;
        for(int i = 0; i<n;i++){
            sum+=A[i];
        }
        cout<<sum<<endl;
        if(sum >= c) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}