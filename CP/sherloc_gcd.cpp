#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i =0;i<n;i++)
        {
            cin>>A[i];
        }
        int g = A[0];
        for(int i = 1;i<n;i++)
        {
            g = gcd(g,A[i]);
        }
        if(gcd == 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}