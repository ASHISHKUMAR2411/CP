// Program to implement the Selection Sort
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
void printVector(const vector<T> &vec){
    for (auto &i : vec)
        cout << i << "; ";
    cout << endl;
}

template <typename T>
void selectionSort(vector<T> &vec){
    for (auto it = vec.begin(); it != vec.end(); ++it){
        auto min = it;
        for (auto i = it + 1; i != vec.end(); ++i)
            if (*i < *min)
                min = i;
        std::swap(*it, *min);
    }
}

// Driver program to test above function
int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand() % 10 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 100 + 1);
    printVector(arr);
    cout << "\n";
    auto start = high_resolution_clock::now();
    selectionSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Sorted Array: \n";
    printVector(arr);
    cout << "Method took " << duration.count() << " nanosecond\n";
}

// 4 52 42 43 99

    // Sorted Array : 42 43 52 99 Method took 611 nanosecond
