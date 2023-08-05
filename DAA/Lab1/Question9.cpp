#include <bits/stdc++.h>
#include <chrono>
using std::cout;
using std::vector;
using namespace std::chrono;
int binarySearch(vector<int> &arr, int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}
int findPivot(vector<int> &arr, int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        return low;
    int mid = (low + high) / 2; 
    /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}

int pivotedBinarySearch(vector<int>& arr, int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
    if (arr[pivot] == key)
        return pivot;
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
    return binarySearch(arr, pivot + 1, n - 1, key);
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
    int n = rand() % 100 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100 + 1);
    }
    int key = rand() % 10 + 1;
    Output(arr);
    cout << "\n";
    auto start = high_resolution_clock::now();
    cout << "Index of the element is : "<< pivotedBinarySearch(arr, arr.size, key) <<"\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Method took " << duration.count() << " nanosecond\n";
}