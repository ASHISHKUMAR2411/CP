#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define MAX 53
using namespace std;
ulli A[15] = {2,3,5,7,11,13,17,19,23,29,37,41,43,47,53}; 
int main()
{
    fast;
    int n,count = 0,i;
    ulli t,sum = 0;
    cin>>n;
    while(n--)
    {
        cin>>t;
        sum = 1,count =0,i =0;
        while((sum * A[i]) <= t && i < 15)
        {
            sum = sum * A[i];
            i++;
            count++;
        }
        cout<<count<<endl;
    }
}