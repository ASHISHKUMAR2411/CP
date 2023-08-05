#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define f(i,m) for(int i = 0 ; i<m;i++)
#define fi(i,m) for(int i = 1 ; i<=m;i++)
#define fir(i,n,m) for(int i = n ; i<=m;i++)
using namespace std;

struct CLASS
{
    int height,width;
    CLASS(int h,int l)
    {
        this->height=h;
        this->width=l;
    }
    int area(int h,int w)
    {
        return h*w;
    }
};
int main()
{
    fast;
    CLASS n = CLASS(6,10);
    cout<<"the area is : "<<n.area(n.height,n.width);
}
