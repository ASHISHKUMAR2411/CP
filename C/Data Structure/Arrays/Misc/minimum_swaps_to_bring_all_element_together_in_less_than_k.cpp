#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "\neneter the element : ";
    int A[n];
    for (int i = 0; i < n; i++)
    {
    there:
        cin >> A[i];
        if (A[i] < 0)
        {
            cout << "\nenter again : ";
            goto there;
        }
    }
    cout << "\nenter the value of the element whose value and less than that is used to put to keep all the element together : ";
    int k;
    cin >> k;
    int count = 0;
    int B[n];
    for (int i = 0; i < n; i++)
    {
        if (A[i] <= k)
        {
            B[count++] = i;
        }
    }
    int max =0;
    for(int i 0;i<count;i++)
    {
        int c1 =0;
        for(int j =i;j<count;j++ )
        {
            if(B[j+1]==(B[j]+1))
            {
                c1++;
            }
        }
        if(c1>max)
        {
            max = c1 ;
        }
    }
    
    int np_swaps = 0;
    if(max == 0)
    {
        for (int i = 0; i < count - 1; i++)
        {
            if (B[i + 1] != (B[i] + 1))
            {
                np_swaps++;
                B[i + 1] = B[i] + 1;
            }
        }
    }
    else
    {
        np_swaps = count - max ;
    }
    
    cout << "No of swaps are : " << np_swaps;
}