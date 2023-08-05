// Spiral format
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "\nenter the value of row and column : ";
    cin >> n >> m;
    int arr[n][m];
    cout << "\nenter the element of the array : \n ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        there:
            cin >> arr[i][j];
            if (arr[i][j] < 0)
            {
                cout << "enter again : ";
                goto there;
            }
        }
    }
    for (int i = 0; i < (n - i); i++)
    {
        for (int j = i; j < (m - i); j++)
        {
            if (arr[i][j] == -1)
            {
                exit(0);
            }
            cout << " " << arr[i][j];
            arr[i][j] = -1;
        }
        for (int j = i + 1; j < (n - i); j++)
        {
            if (arr[j][m - i - 1] == -1)
            {
                exit(0);
            }
            cout << " " << arr[j][m - i - 1];
            arr[j][m - i - 1] = -1;
        }
        for (int j = (m - 2 - i); j >= i; j--)
        {
            if (arr[n - i - 1][j] == -1)
            {
                exit(0);
            }
            cout << " " << arr[n - i - 1][j];
            arr[n - i - 1][j] = -1;
        }
        for (int j = n - 2 - i; j > i; j--)
        {
            if (arr[j][i] == -1)
            {
                exit(0);
            }
            cout << " " << arr[j][i];
            arr[j][i] = -1;
        }
    }
}