#include <bits/stdc++.h>
#include <chrono>
using std::cout;
using std::vector;
using namespace std::chrono;

int getMax(vector<int> &a)
{
    int max = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max; // maximum element from the array
}

void countSort(vector<int> &a) // function to perform counting sort
{
    int n = a.size();
    int output[n + 1];
    int max = getMax(a, n);
    int count[max + 1]; // create count array with size [max+1]

    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0; // Initialize count array with all zeros
    }

    for (int i = 0; i < n; i++) // Store the count of each element
    {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1]; // find cumulative frequency

    /* This loop will find the index of each element of the original array in count array, and
    place the elements in output array*/
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--; // decrease count for same numbers
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i]; // store the sorted elements into main array
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
    countSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Sorted Array: \n";
    Output(arr);
    cout << "Method took " << duration.count() << " nanosecond\n";
}