#include<bits/stdc++.h>
using namespace std;
bool prime(long int N)
{
    if(N==1) return false;
    for(long int i =2;i*i<=N;i++)
        if(N%i==0) return false;
    return true;
}
int main()
{
    long int n;
    cin>>n;
    cout<<prime(n);
}