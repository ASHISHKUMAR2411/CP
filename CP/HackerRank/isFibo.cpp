#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define pii 3.14159
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
lli ar[50];
void isFibo()
{
    ar[0] = 0 , ar[1] = 1 ;
    long long int a = 0,b = 1;
    for(int i = 2;i<50;i++)
    {
        ar[i] = a+b;
        a = b;
        b = ar[i];
    }
}
int main()
{
    fast;
    isFibo();
    int t,count = 0;
    lli n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        count = 0;
        for(int i = 0;i<50;i++)
        {
            if(ar[i] == n) count = 1;
        }
        if(count == 1) cout<<"IsFibo"<<endl;
        else cout<<"IsNotFibo"<<endl;
    }
}