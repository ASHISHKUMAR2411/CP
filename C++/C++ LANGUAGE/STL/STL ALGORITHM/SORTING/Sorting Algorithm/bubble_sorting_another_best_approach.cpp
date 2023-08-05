#include<bits/stdc++.h>
using namespace std;
template<class T>
void swapping(T &value1 , T &value2)
{
    T temp ;
    temp = value1;
    value1 = value2 ;
    value2 = temp;
}
template<class T>
void bubbleSort(T arr[],int size)
{
    bool swapped = false;
    for(int i=0;i<size-1;i++)
    {
        swapped = false;
        for (int  j = 0; j  < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapping(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
        {
            break;
        }
    }
}
template<class T>
void print(T arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    // int arr[100];
    // char arr[100];
    string arr[100];
    int size;
    cin>>size;
    for (int  i = 0; i < size; i++)
    {
        cout<<"\nenter the element : ";
        cin>>arr[i];
        /* code */
    }
    cout<<"Sorted Array :  \n";
    // bubbleSort<int>(arr,size);
    // bubbleSort<char>(arr,size);
    bubbleSort<string>(arr,size);
    // print<int>(arr,size);
    print<string>(arr,size);
    // print<char>(arr,size);
}

// The above function always runs O(n^2) time even if the array is sorted. It can be optimized by stopping the algorithm if inner loop didn’t cause any swap. 


// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
// Sorting In Place: Yes
// Stable: Yes
// Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.