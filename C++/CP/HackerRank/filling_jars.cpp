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
int main()
{
    fast;
    int n, m,a,b,k;
    lli sum = 0;
    cin >> n >> m;
    while(m--)
    {
        cin>>a>>b>>k;
        sum += (b-a+1)*k;
    }
    sum = floor(sum/n);
    cout<<sum<<endl;
    // lli A[n + 1];
    // f(i, n) A[i] = 0;
    // int ar[m][3];
    // f(i, m) 
    //     f(j, 3)
    //     {
    //         cin >> ar[i][j];
    //     }
    //     fir(i,ar[i][0],ar[i][1])
    //     {
    //         A[i] += ar[i][2];
    //     }
    
}