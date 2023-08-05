#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
void rotate(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i != j)
    {
        swap(arr[i], arr[j]);
        i++;
    }
}
int main()
{
    fast;
    int n;
    cin >> n;
    int arr[n];
    f(i, n) cin >> arr[i];
    int temp = arr[n - 1];

    // o(n) time complexity
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;

    //  one more approach with O(n) complexity
    rotate(arr, n);

    f(i, n) cout << " " << arr[i];
    return 0;
}