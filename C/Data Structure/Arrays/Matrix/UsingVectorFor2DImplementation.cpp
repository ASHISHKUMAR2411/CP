#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Not Cache Friendly
    // Here number of rows are fixed but not the columns
    // Individual rows are dynamic sizes which is Good. 
    // Easy to pass to a function 
    srand(time(0));
    int m = rand() % 100, n = rand() % 10;
    vector<int> arr[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i].push_back(rand());
        }
    }
    for (int i = 0; i < m; i++)
    {
        /* code */
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout<<"\n"<<"\n"<<"-----------------------------------"<<"\n";

    // 2nd Method is using vector of vector
    // Easy to pass to a function
    // dynamic array
    // Not Cache friendly
    vector<vector<int>> A;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(rand());
        }
        A.push_back(v);
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    
    
}