// Finding median of the matrix.
#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &arr)
{
    cout << "\n"
        << "-------------------------------"
         << "\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// This Takes O(r*c) time complexity
int FindMedian(vector<vector<int>> &arr)
{
    vector<int> p;
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr[i].size(); j++)
            p.push_back(arr[i][j]);
    printVector(p);
    nth_element(p.begin(), p.begin() + p.size() / 2, p.end());
    printVector(p);

    return p[p.size() / 2];
}

// Now for Better Time complexity we have O(r*log(max(arr) - min(arr))*log(c))

int FindMedian2(vector<vector<int>> &arr)
{
    int min = arr[0][0], max = arr[0][arr[0].size() - 1];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][0] < min)
            min = arr[i][0];
        if (arr[i][arr.size() - 1] > max)
            max = arr[i][arr.size() - 1];
    }
    int medPos = (arr.size() * arr[0].size() + 1) / 2;
    while (max > min)
    {
        int mid = min + (max - min) / 2;
        int midPos = 0;
        for (int i = 0; i < arr.size(); i++)
            midPos += upper_bound(arr[i].begin(), arr[i].begin() + arr[i].size(), mid) - arr[i].begin();
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

void print(vector<vector<int>> &arr)
{
    // this is not much cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Sort(vector<vector<int>> &arr)
{
    // Column wise
    for (int i = 0; i < arr.size(); i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
}
int main()
{
    srand(time(0));
    vector<vector<int>> arr;
    int n = rand() % 10, m = rand() % 5;
    while (m % 2 == 0 || n % 2 == 0)
    {
        m = rand() % 5;
        n = rand() % 5;
    }
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(rand() % 100);
        }
        arr.push_back(v);
    }
    print(arr);
    Sort(arr);
    print(arr);
    cout << "the median is : " << FindMedian2(arr) << endl;
    return 0;
}