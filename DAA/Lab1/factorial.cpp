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
        cout << i << "; ";
    cout << endl;
}

int kthSamllest(vector<int> &arr, int k)
{
    // considering range of [-1000, 1000]
    int count = 0;
    int auxiliary[2001];
    for (int i = 0; i <= 2000; i++)
        auxiliary[i] = 0;
    for (int i = 0; i < arr.size(); i++)
        auxiliary[arr[i] + 1000]++;
    for (int i = 0; i <= 2000; i++)
    {
        if (auxiliary[i] > 0)
        {
            count += auxiliary[i];
            if (count >= k)
                return i - 1000;
        }
    }
    return INT_MAX;
}

// Driver program to test above function
int main()
{
    srand(time(0));
    int n = rand() % 10 + 1;
    cout << n << "\n";
    auto start = high_resolution_clock::now();
    long long int res = factorial(k);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << n << "! factorial is : " << res << "\n";
    cout << "Method took " << duration.count() << " nanosecond\n";
}
