#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "\nenter the array: ";
    int A[n];
    for (int i = 0; i < n; i++)
    {
    there:
        cin >> A[i];
        if (A[i] < 0)
        {
            cout << "enter again : ";
            goto there;
        }
    }
    int B[n], C[n], E[n];
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i] % 10;
        C[i] = A[i];
    }
    for (int i = 0; i < n; i++)
    {
        while (A[i] > 10)
        {
            A[i] = A[i] / 10;
        }
    }
    int temp = 0, flag = 1;
    int max_index = 0, max = A[0];
    for (int i = 0; i < n; i++)
    {
        max = A[i];
        max_index = i;
        for (int j = 0; j < n; j++)
        {
            if (A[j] > max)
            {
                max = A[j];
                max_index = j;
            }
            else if (A[j] == max)
            {
                if (B[j] > B[max_index])
                {
                    max_index = j;
                    max = A[j];
                }
            }
        }
        A[max_index] = 0;
        B[max_index] = 0;
        E[i] = C[max_index];
    }
    for (int i = 0; i < n; i++)
    {
        cout << E[i];
    }
}