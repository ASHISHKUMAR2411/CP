#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define EPS 10
#define endl '\n'
#define pi pair<lli, lli>
using namespace std;
pi fib(lli n)
{
    if (n == 0)
        return {0, 1};
    auto p = fib(n >> 1);
    lli c = ((p.first % EPS) * ((2 * (p.second % EPS)) % EPS - p.first % EPS + EPS) % EPS) % EPS;   // this line was changed
    lli d = ((p.first % EPS) * (p.first % EPS)) % EPS + ((p.second % EPS) * (p.second % EPS)) % EPS; // this line was changed
    if (n & 1)
        return {d, (c + d) % EPS};
    else
        return {c, d};
}
int main()
{
    fast;
    lli t,m,n,sum = 0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        sum = 0;
        for(int i = n;i<m;i+=2){
            if(i == 0) sum += 1;
            else if(i == 1) sum =( sum+2)% EPS;
            else if(i==2) sum = (sum+5) %EPS;
            else
            sum = (sum%EPS + fib(i).first % EPS + fib(i).second % EPS)% EPS;
        }
        cout<<sum<<endl;
    }
}