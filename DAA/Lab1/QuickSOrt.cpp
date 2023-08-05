#include <bits/stdc++.h>
#include <chrono>
using std::cout;
using std::vector;
using namespace std::chrono;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     
    // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Sorted Array: \n";
    Output(arr);
    cout << "Method took " << duration.count() << " nanosecond\n";
}