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
    for (int i = 0; i <= 2000; i++){
        if (auxiliary[i] > 0){
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
    vector<int> arr;
    int n = rand() % 10 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 1000 + 1);
    printVector(arr);
    cout << "\n";
    int k = rand() % n + 1;
    auto start = high_resolution_clock::now();
    int res = kthSamllest(arr, k);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << k <<"th smallest element of the Array is : "<< res << "\n";
    cout << "Method took " << duration.count() << " nanosecond\n";
}
// 4 335 594 354 335

//     4th smallest element of the Array is : 594 Method took 11037 nanosecond

    // 10 56 99 96 80 50 100 46 9 92 53

    // Sorted Array : 53 92 9 46 100 50 80 96 99 56 Method took 221 nanosecond
