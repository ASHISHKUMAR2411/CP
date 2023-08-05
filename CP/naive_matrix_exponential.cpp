// in this we are calculating the matrix exponential in( dim^3 * power) complexity
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
#define N 101
using namespace std;
int ar[N][N], I[N][N];
void matMul(int A[][N],int B[][N],int dim)
{
    int res[dim+1][dim+1];
    fi(i,dim)
    {
        fi(j,dim)
        {
            res[i][j] = 0;
            fi(k,dim) res[i][j] += A[i][k]*B[k][j];
        }
    }
    fi(i,dim) fi(j,dim) A[i][j] = res[i][j];
}
void matExp(int A[][N], int dim, int n)
{
    fi(i, dim) fi(j, dim)
    {
        if (i == j)
            I[i][j] = 1;
        else
            I[i][j] = 0;
    }
    fi(i,n)
    matMul(I,A,dim);
    fi(i,dim) fi(j,dim) A[i][j] = I[i][j];
}
void matPrint(int A[][N],int dim)
{
    fi(i,dim)
    {
        fi(j,dim) cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    fast;
    int t, dim, power;
    cin >> t;
    while (t--)
    {
        cin >> dim >> power;
        fi(i, dim) fi(j, dim) cin >> ar[i][j];
        matExp(ar, dim, power);
        matPrint(ar, dim);
    }
}