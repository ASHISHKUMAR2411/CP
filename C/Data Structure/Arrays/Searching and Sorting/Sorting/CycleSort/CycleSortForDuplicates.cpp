#include <bits/stdc++.h>
using namespace std;
// Cycle Sort is used when we want to use less memeory writes , Like EPROMs have less memeory writes and it gets affected after one use
// It is a famous question

// this case is for when all elements are distinct
void CycleSort(vector<int> &arr)
{
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on
    // the right place
    for (int cycle_start = 0; cycle_start <= (int)(arr.size()) - 2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < (int)(arr.size()); i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position
        if (pos == cycle_start)
            continue;

        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;

        // put the item to it's right position
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start + 1; i < (int)(arr.size()); i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }

    // Number of memory writes or swaps
    cout << writes << endl ;
}
int main()
{
    srand(time(0));
    vector<int> arr  = {1, 6,3,1,3,4,5,6,7,0,9,7,64,23,67,4,3,6,3,22,5,7,9,0,7,4,2,3,33,5,7,6,4,32,4,56,7,8};
    // int n = rand() % 100;
    // for (int i = 0; i < n; i++)
    // {
    //     arr.push_back(rand());
    //     cout << arr[i] << " ";
    // }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    CycleSort(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}