#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Method 1
    // THis Type of implementation is not cache friendly as it store inside array(n) at different memory location

    // The benefit is that we can make array of any size desireable size which can be like instead of giving n every time we can give whatever size we want to give it just has to be within the range of memory storage.

    // it is easy to pass as argument
    int **arr1;
    srand(time(0));
    int m = rand() % 100, n = rand() % 10;
    arr1 = new int *[m];
    for (int i = 0; i < m; i++)
        arr1[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr1[i][j] = rand();
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout<< "\n"
        << "\n"
        << "\n";

    // Method 2
    //

    int *arr2[m];
    for (int i = 0; i < m; i++)
        arr2[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr2[i][j] = rand();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n"
         << "\n"
         << "\n";
    return 0;
}