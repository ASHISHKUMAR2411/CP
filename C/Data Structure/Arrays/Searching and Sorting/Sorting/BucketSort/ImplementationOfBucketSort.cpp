// Bucket Sort is an Algorithm which is used to sort an array with Uniformly Distributed element around the range i.e if elements are uniformly distributed it takes linear complexity and if elements are not distributed it takes Quadratic Complexity

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void insertionSort(vector<int>  &arr)
{
    int n = arr.size();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void BucketSort(int arr[], int n, int k)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    max++;
    vector<int> B[k];
    for (int i = 0; i < n; i++)
    {
        int j = (k * arr[i]) / max;
        B[j].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
        // We should use insertion Sort
        insertionSort(B[i]);
        // sort(B[i].begin(), B[i].end());

    int index = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < B[i].size(); j++)
            arr[index++] = B[i][j];
}
int main()
{
    // 
    srand(time(0));
    auto start = high_resolution_clock::now();
    int n = 1000;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << ",";
    }
    int k = rand() % n;
    cout << endl;
    cout << endl;
    cout << endl;
    BucketSort(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}