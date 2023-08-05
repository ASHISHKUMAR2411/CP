// Heap Sort takes O(nlogn) time complexity , in all three cases , But it not better than QuickSort , MergeSort because it uses more constants than them, and lower them also
// Heap Sort is better version of Selection Sort Technique where we find the maximum elements in the array and swap with the last element, But in selection sort we did this in linear search which makes it O(n*n) but in Heap sort we heapify it , which is creating the parent node bigger than childrens in which it takes O(logn) and we call for it all node which makes it O(nlogn) time complexity, which is better than Selection Sort

// Then why to study it because it is used in Sorting Libraries which makes it special like IntroSort in C++ it is used with quickSort when QuickSort goes out of O(nlogn) then it switches to Heap Sort for efficiency

#include <bits/stdc++.h>
using namespace std;
void Heapify(int arr[], int size, int ithIndex)
{
    int largestIndex = ithIndex, leftChildIndex = 2 * ithIndex + 1, rightChildIndex = 2 * ithIndex + 2;
    if (leftChildIndex < size && arr[largestIndex] < arr[leftChildIndex])
    {
        largestIndex = leftChildIndex;
    }
    if (rightChildIndex < size && arr[largestIndex] < arr[rightChildIndex])
    {
        largestIndex = rightChildIndex;
    }
    if (largestIndex != ithIndex)
    {
        swap(arr[ithIndex], arr[largestIndex]);
        Heapify(arr, size, largestIndex);
    }
}

void BuildHeap(int arr[], int n)
{
    // Building Heap
    // As Parent Node Index  is (i-1)/2
    // so for the last Index we will start so starting point is for n-1 is ((n-1) - 1)/2 = n/2 - 1
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n)
{
    // Build Heap
    BuildHeap(arr, n);

    // Now sorting from the last Index and reducing the size
    for (int i = n - 1; i > 0; i--)
    {
        // Swapping the first with the last as it has already done while building the heap
        swap(arr[i], arr[0]);
        // Now Building Heap with decreased size
        Heapify(arr, i, 0);
    }
}

int main()
{
    srand(time(0));
    int n = rand() % 250;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    HeapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}