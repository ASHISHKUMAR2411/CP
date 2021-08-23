#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define MAX 1000000000
using namespace std;
int main()
{
    fast;
    int i = 2;
    char a[10],b[10];
    while (i--)
    {
        scanf("%s %s",&a,&b);
        int j = 0, k = 0, count = 0;
        for (int i = 0; i <10 ; i++)
        {
            j = 0, k = i;
            while (k < 10 && j < 5 && a[k] == b[j])
            {
                k++;
                j++;
            }
            if (j == 5)
            {
                count = 1;
                cout << 1 << endl;
                break;
            }
        }
        if (count == 1)
            ;
        else
            cout << 0 << endl;
    }
}