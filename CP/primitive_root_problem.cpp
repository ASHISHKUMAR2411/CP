#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
vi factors , pu;
lli modularExponent(lli a, lli n,lli p)
{
    lli res = 1;
    while (n)
    {
        if(n%2)
            res = (res%p * a%p)%p,n--;
        else a = (a%p * a%p)%p , n/=2;
    }
    return res ;
}
void primeFac(lli N)
{
    for(lli i =2;i*i<=N;i++)
    {
        int cnt = 0;
        while(N%i ==0)
        {
            cnt++;
            N/=i;
        }
        factors.push_back(i);
        pu.push_back(i);
    }
    if(N>1) {factors.push_back(N); pu.push_back(N);
}
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    fast;
    lli p;
    cin>>p;
    lli s = p-1;
    // finding prime factors of s 
    primeFac(s);
    // finding s/pi 
    for(int i =0;i<(int)(factors.size());i++)
    {
        factors[i] = s/factors[i];
    }
    lli i =2,j =0,first = 0;
    // finding first primitive factor
    while(i && i<s)
    {
        j = 0;
        while(j < (int)(factors.size()) && (modularExponent(i,factors[j],p))!= 1)
        {
            j++;
        }
        if(j == (int)(factors.size())) 
        {
            first = i;
            break;
        }
        else{
            i++;
        }
    }
    cout<<first<<" ";
    int count = 0;
    for(int i = 1;i<p;i++)
    {
        if((gcd(i,s)) == 1)
        {
            count++;
        }
    }
    cout<<count;
}