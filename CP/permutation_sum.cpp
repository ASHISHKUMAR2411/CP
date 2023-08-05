
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lli long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int main()
{
    lli t,n;
    lli A[(int)1e5+4];
    A[0]=0,A[1]=1,A[2]=1,A[3]=3;
    lli sum=0 , j =0;
    scanf("%lld",&t);
    while(t--)
    {
        sum = 0;
        scanf("%lld",&n);
        for(int i = 1 ;i<(n/2);i++)
        {
            sum += i*4;
        }
        if(n==1)
        {
            printf("%lld\n",1);
        }
        else if(n%2==0)
        {
            sum += n-1;
            printf("%lld\n",sum);
        }
        else {
            sum += 2*n - 3;
            printf("%lld\n",sum);

        }
    }
}