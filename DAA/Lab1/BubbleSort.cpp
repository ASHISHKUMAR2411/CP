// Program to implement the Bubble Sort
// taking random inputs at runtime using rand() function to test the algorithm.
#include <bits/stdc++.h>
#include <chrono>
using std::cout;
using std::vector;
using namespace std::chrono;

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

void Output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Driver program to test above function
int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand() % 10 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100 + 1);
    }
    Output(arr);
    cout << "\n";
    auto start = high_resolution_clock::now();
    BubbleSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Sorted Array: \n";
    Output(arr);
    cout << "Method took " << duration.count() << " nanosecond\n";
}

// 69, 8, 17, 45, 79, 43, 5, 84, 99, 6, 98, 24, 15, 34, 28, 28, 97, 81, 36, 69, 56, 63, 89, 11, 25

7 62 41 42 50 31 52 38

31 38 41 42 50 52 62 Method took 1098 nanosecond
