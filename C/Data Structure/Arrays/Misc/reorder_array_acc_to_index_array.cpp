#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n], ind[n];
    cout << "\nenter the element of array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nenter the element of index array : \n";
    for (int i = 0; i < n; i++)
    {
    there:
        cin >> ind[i];
        if (ind[i] >= n)
        {
            cout << "enter again : ";
            goto there;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ind[j] == i)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                temp = ind[j];
                ind[j] = ind[i];
                ind[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << ind[i];
    }
}