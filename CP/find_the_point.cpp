#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int main()
{
    fast;
    int n , p1,p2,q1,q2;
    cin>>n;
    while(n--)
    {
        cin>>p1>>p2>>q1>>q2;
        cout<<(2*q1-p1)<<" "<<(2*q2-p2)<<endl;
    }
}