#include <bits/stdc++.h>
using namespace std;
void print1(int arr[3][2])
{
    // here this function is fixed for 3 row and 2 col
    // it is cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print2(int arr[][2], int m)
{
    // In this we can have m rows i.e any number of rows but the column are fixed
    // it is also cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// we can't have fun(arr[][]) which is wrong as number of column is must.

// Next we have m rows but cols are fixed
void print3(int *arr[2], int m)
{
    // In this we can have m rows i.e any number of rows but the column are fixed
    // it is also cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Next we have dynamic size array
void print4(int **arr, int m, int n)
{
    // In this we can have m rows i.e any number of rows and n columns which is dynamic
    // it is also cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Next we have dynamic vector array with m rows fixed but dynamic columns
void print5(vector<int> *arr, int m)
{
    // this is not much cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Next we have dynamic vector array with m rows fixed but dynamic columns
void print6(vector<int> arr[], int m)
{
    // this is not much cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// When we have vector of vector dynamically allocated vector
void print7(vector<vector<int>> &arr)
{
    // this is not much cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    srand(time(0));
    int m = rand() % 10, n = rand() % 10;

    // 1
    int arr1[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr1[i][j] = rand();
        }
    }
    print1(arr1);

    // 2
    print2(arr1, 3);
    int arr2[m][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr2[i][j] = rand();
        }
    }
    print2(arr2, m);

    // 3
    int *arr3[2];
    for (int i = 0; i < 2; i++)
    {
        arr3[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr3[i][j] = rand();
        }
    }
    print3(arr3, n);

    // 4
    int **arr4;
    arr4 = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr4[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr4[i][j] = rand();
        }
    }
    print4(arr4, m, n);

    // 5
    vector<int> arr5[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr5[i].push_back(rand());
        }
    }
    print5(arr5, m);

    // 6
    print6(arr5, m);
    vector<int> *arr6;
    arr6 = new vector<int>(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr6[i].push_back(rand());
        }
    }
    print6(arr6, m);

    // 7
    vector<vector<int>> arr7;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(rand());
        }
        arr7.push_back(v);
    }
    print7(arr7);
    return 0;
}
