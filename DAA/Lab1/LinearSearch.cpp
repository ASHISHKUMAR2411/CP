// Program to implement the Linear Search
// taking random inputs at runtime using rand() function to test the algorithm.
#include <bits/stdc++.h>
#include <chrono>
using std::vector;
using std::cout;
using namespace std::chrono;

// Function to implement the Linear Search
int LinearSearch(vector<int> &arr, int ele)
{
    int i;
    for (i = 0; i < arr.size(); i++)
        if (arr[i] == ele)
            return i;
    return -1;
}

// Driver program to test above function
int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand();
    cout << n << "\n";
    for (int  i = 0; i < n; i++)
    {
        arr.push_back(rand());
    }
    for(int i : arr){
        cout << ", " << i;
    }
    cout << "\n";
    int ele = rand();
    cout << ele << " "<< n << "\n";
    auto start = high_resolution_clock::now();
    int result = LinearSearch(arr, ele);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Method took " << duration.count() << " nanosecond\n";
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}

// 69, 8, 17, 45, 79, 43, 5, 84, 99, 6, 98, 24, 15, 34, 28, 28, 97, 81, 36, 69, 56, 63, 89, 11, 25