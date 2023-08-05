// Program to implement the kth smallest element of the array
// taking random inputs at runtime using rand() function to test the algorithm.
#include <bits/stdc++.h>
#include <chrono>
using std::cout;
using std::vector;
using namespace std::chrono;
using std::cout;
using std::endl;
using std::vector;

template <typename T>
void printVector(const vector<T> &vec)
{
    for (auto &i : vec)
        cout << i << " ";
    cout << endl;
}

void BubbleSort(vector<int> &a)
{
    bool swapp = true;
    while (swapp)
    {
        swapp = false;
        for (size_t i = 0; i < a.size() - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                a[i] += a[i + 1];
                a[i + 1] = a[i] - a[i + 1];
                a[i] -= a[i + 1];
                swapp = true;
            }
        }
    }
}

int findMinDiff(vector<int> &arr, int m)
{
    int n = arr.size();
    if (m == 0 || n == 0)
        return 0;
    BubbleSort(arr);
    if (n < m)
        return -1;
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++){
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

// Driver program to test above function
int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand() % 10 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 1000 + 1);
    printVector(arr);
    cout << "\n";
    int m = rand() % n + 1;
    auto start = high_resolution_clock::now();
    int res = findMinDiff(arr, m);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    if (res == -1)
        cout << "No such m exists\n";
    else
        cout << "Minimum difference is " << res << "\n";
    cout << "Method took " << duration.count() << " nanosecond\n";
}

    // 2 10 10
    // 2 Minimum difference is 0 Method took 310 nanosecond
