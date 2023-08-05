// take O(nlogn) time
#include<bits/stdc++.h>
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
    int i , j , temp =0 , temp1 =0 ;
    for(j=1;j<n;j++)
    {
        temp=ind[j];
        temp1 = arr[j];
        i=j-1;
        while(i>=0&&ind[i]>temp)
        {
            ind[i+1]=ind[i];
            arr[i+1] = arr[i];
            i--;
        }
        ind[i+1]=temp;
        arr[i+1] = temp1;
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
}