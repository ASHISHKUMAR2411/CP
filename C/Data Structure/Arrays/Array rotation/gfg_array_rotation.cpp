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
// juggling algorithm O(n) and O(1) for array rotation
void jugglingAlgorithm(int a[], int n, int d)
{
    // where d is the number of rotation of array should happen
    int k, temp, j;
    for (int i = 0; i < __gcd(d % n, n); i++)
    {
        temp = a[i];
        j = i;
        while (1)
        {
            k = j + d % n;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            a[j] = arr[k];
            j = k;
        }
        a[j] = temp;
    }
}
// block Swap Algorithm O(n) and O(1) it swap towards 0 index i.e 1st values goes to the last i.e left Rotate
void Swap(int arr[], int fi, int si, int d)
{
    int i, temp;
    f(i, d)
    {
        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}
void blockSwapAlgorithm(int a[], int n, int d)
{
    int i, j;
    if (d == 0 || d == n)
        return;
    i = d;
    j = n - d;
    while (i != j)
    {
        if (i < j)
        {
            Swap(a, d - i, d + j - i, i);
            j -= i;
        }
        else
        {
            Swap(a, d - i, d, j);
        }
    }
    Swap(a, d - i, d, i);
}

// reversal algorithm O(n) & O(1) , in this we divide the array ar[0..d] and ar[d+1...n] and then we first reverse ar[0..d] and reverse the ar[d+1,n] part and then we reverse the array and this is how we get the array ...
// this is also helped to rotate the array in left
void reverseArray(int arr[], int start, int end)
{
    int temp = 0;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reversalAlgorithm(int arr[], int n, int d)
{
    if (d == 0)
    {
        return;
    }
    d = d % n;
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}
int main()
{
    fast;
    int n;
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];
    int k;
    cin >> k;
    jugglingAlgorithm(a, n, k);
    f(i, n) cout << " " << a[i];
    return 0;
}