#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
using namespace std;

int main(){
    fast;
    lli n
    cin>>n;
    int i, x;
    unsigned long Fx, Fxp1, tmp;
    x = 1;
    Fx = 1;
    Fxp1 = 1;
    for (i = 1; i <= k; i++)
    {
        /* Block-1 start */
        x = x * 2;
        tmp = 2 * Fx * Fxp1 - Fx * Fx;
        Fxp1 = Fx * Fx + Fxp1 * Fxp1;
        Fx = tmp;
        /* Block-1 end */
        if (b[i] == 1)
        {
            /* Block-2 start */
            x = x + 1;
            tmp = Fx + Fxp1;
            Fx = Fxp1;
            Fxp1 = tmp;
            /* Block-2 end */
        }
    }
}