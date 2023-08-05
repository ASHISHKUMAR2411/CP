#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int main()
{
    fast;
    ulli m,n;
    cin>>n>>m;
    if(n==1) cout<<m-1<<endl;
    else if(m==1) cout<<n-1<<endl;
    else{
    ulli product = ((n-1)*(n-1)*(m-1));
    cout<<product<<endl;
    }
}