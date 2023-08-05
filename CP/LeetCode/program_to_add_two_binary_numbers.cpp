#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
int main()
{
    fast;
    string a , b , c ="";
    cin>>a>>b;
    char p1,p2;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry = 0,i = 0,j = 0;
    for ( i = 0,j =0; i<(int)(a.length()) && j < (int)(b.length());i++,j++){
        p1 = a[i];
        p2 = b[j];
        p2 = p1+p2-'0'-'0'+carry;
        carry = p2/2;
        if(p2%2) c+='1';
        else c+='0'; 
    }
    while(i<(int)(a.length())){
        p1 = a[i]-'0'+carry;
        carry = p1/2;
        if(p1%2) c+= '1';
        else c+='0';
        i++;
    }
    while(j<(int)(b.length())){
        p2 = b[j]-'0'+carry;
        carry = p2/2;
        if(p2%2) c+= '1';
        else c+='0';
    }
    if(carry) c+='1';
    reverse(c.begin(),c.end());
    cout<<c<<endl;
}