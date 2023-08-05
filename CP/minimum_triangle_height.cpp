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
    int a,b;
    cin>>b>>a;
    if(a==b)
    {
        if(a%2==0)
        {
            cout<<((n*n)/(2*2))<<endl;
        }
        else{
            cout<<(((n*n)/(2*2))+n)<<endl;
        }
    }
    else{
        if(a%2==1 && b%2==0)
        {
            cout<<(((a/2)*(b/2))+(b/2))<<endl;
        }
        else if(b%2==1 && a%2==0)
        {
            cout<<(((a/2)*(b/2))+(a/2))<<endl;
        }
        else if(a%2==1 && b%2==1)
        {
            cout<<(((a/2)*(b/2))+ceil(a/2)+b/2)<<endl;
        }
        else
        {
            cout<<((a/2)*(b/2))<<endl;
        }
    }
}