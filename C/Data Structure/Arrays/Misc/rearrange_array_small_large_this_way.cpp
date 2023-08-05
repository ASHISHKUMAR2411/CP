#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, j, i, temp = 0;
    cin >> n;
    cout << "\neneter the array : ";
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (j = 1; j < n; j++)
    {
        temp = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > temp)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = temp;
    }
    for (i = n/2, j = n - 1;  i >0 ; i -= 1, j -= 2)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    for (i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
}