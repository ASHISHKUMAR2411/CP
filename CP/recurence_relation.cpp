// here we are working on fibonacci series work with recurrence relationship
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
#define mo 1000000007
using namespace std;
lli ar[3];
lli T[3][3], I[3][3];
void matMul(lli A[3][3], lli B[3][3], int dim)
{
    lli res[dim + 1][dim + 1];
    fi(i, dim)
    {
        fi(j, dim)
        {
            res[i][j] = 0;
            fi(k, dim)
            {
                lli x = (A[i][k] * B[k][j]) % mo;
                res[i][j] = (res[i][j] + x) % mo;
            }
        }
    }
    fi(i, dim) fi(j, dim) A[i][j] = res[i][j];
}
lli getFib(int n)
{
    if (n <= 2)
        return ar[n];

    I[1][1] = I[2][2] = 1;
    I[2][1] = I[1][2] = 1;

    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;

    n = n - 1;
    while (n)
    {
        if (n % 2)
            matMul(I, T, 2), n--;
        else
            matMul(T, T, 2), n = n / 2;
    }
    lli x = ((ar[1] * I[1][1] + ar[2] * I[2][1]) % mo);
    return x;
}
int main()
{
    fast;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> ar[1] >> ar[2] >> n, n++;
        cout << getFib(n) << endl;
    }
}