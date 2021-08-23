#include <bits/stdc++.h>
using namespace std;
int ar[26];
void sieve()
{
    ar[(int)('I'-'A')] = 1;
    ar[(int)('V'-'A')] = 5;
    ar[(int)('X'-'A')] = 10;
    ar[(int)('L'-'A')] = 50;
    ar[(int)('C'-'A')] = 100;
    ar[(int)('D'-'A')] = 500;
    ar[(int)('M'-'A')] = 1000;
}
int main()
{
    sieve();
    string s ;
    cin>>s;
    int sum = 0;
    reverse(s.begin(),s.end());
    for(int i =0;i<(int)(s.length());i++)
    {
        if((ar[s[i]-'A']-ar[s[i-1]-'A'])<0)
        {
            sum -= ar[s[i]-'A'];
        }
        else
        {
            sum += ar[s[i]-'A'];
        }
    }
    cout<<sum<<endl;
}