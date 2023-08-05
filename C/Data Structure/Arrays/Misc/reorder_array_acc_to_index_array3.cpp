// Takes O(n) time and O(1) complexity
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ind[n], arr[n];
    for (int i = 0; i < n; i++)
    {
    there:
        cout << "\nenter the index : ";
        cin >> ind[i];
        if (ind[i] >= n)
        {
            cout << "\nenter again: ";
            goto there;
        }
        cout << "\nneter the array value : ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        while (ind[i] != i)
        {
            int temp1 = ind[i];
            ind[i] = ind[temp1];
            ind[temp1] = temp1;
            int temp = arr[i];
            arr[i] = arr[temp1];
            arr[temp1] = temp;
        }
    }
    cout << "\nthe index array : ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << ind[i];
    }
    cout << "\nthe array value is : ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
