#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n ;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        int mo = 1e9+7;
        int num = (((((n%mo)*(n%mo)*2)%mo)-(n % mo)+ mo )%mo);
        cout<<num<<"\n";
    }
}