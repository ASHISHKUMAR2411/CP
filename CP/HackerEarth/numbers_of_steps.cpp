#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define pb push_back
#define sz(x) (int)(x).size()
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
int main()
{
    fast;
    int arr[5001];
    for (int i = 0; i <= 5000; ++i)
    {
        arr[i] = 0;
    }
    int n;
    cin >> n;
    int A[n], B[n], C[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        arr[A[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n; ++i)
    {
        C[i] = A[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        while ((A[i] - B[i]) >= 0)
        {
            arr[(A[i] - B[i])]++;
            A[i] = A[i] - B[i];
        }
    }
    vi c;
    for (int i = 0; i <= 5000; ++i)
    {
        if (arr[i] == n)
        {
            count = 0;
            for (int j = 0; j < n; j++)
            {
                if(B[i]!=0)
                count += (C[j] - i) / B[j];
            }
            if (count != 0)
                c.pb(count);
        }
    }
    if ((int)(c.size()) == 0)
        cout << -1 << endl;
    else
    {
        sort(c.begin(), c.end());
        cout << c[0] << endl;
    }
}

#include <iostream>

using namespace std;

int main()

{

    int n, min = 5001, steps = 0, f = 0;

    cin >> n;

    int a[n], b[n];

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

        if (a[i] < min)

            min = a[i];
    }

    for (int i = 0; i < n; i++)

        cin >> b[i];

    for (int i = 0; i < n; i++)

    {

        while (a[i] > min && b[i] != 0)

        {

            a[i] -= b[i];

            steps++;
        }

        if (a[i] < min)

        {

            min = a[i];

            i = -1;
        }

        if (a[i] < 0)

        {

            f = -1;

            break;
        }
    }

    if (f == -1)

        cout << "-1";

    else

        cout << steps;
}