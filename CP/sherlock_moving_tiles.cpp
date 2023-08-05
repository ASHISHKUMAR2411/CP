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
    lli l,s1,s2,q;
    cin>>l>>s1>>s2>>q;
    ulli queries[q];
    for(int i=0;i<q;i++)
    {
        cin>>queries[i];
    }
    double time = 0.0;
    for(int i = 0;i<q;i++)
    {
        time = ((((double)l)* (sqrt(2)) - (sqrt(2*queries[i])))/(double)(abs(s2-s1)));
        printf("%.4lf\n",time);
    }

}