// The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

// 1) The subarray which is already sorted.
// 2) Remaining subarray which is unsorted.

// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

// for example
// arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
// 11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
// 11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
// 11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
// 11 12 22 25 64 

// it is taking O(n^2) time ...


#include<iostream>
using namespace std;
// using template to execute for all data types 
template<class T>
// function selection sort starts here 
void selection_sort(T A[],int size)
{
    T temp;
    int min=0;
    for(int i=0;i<size-1;i++)
    {
        min = i;
        for(int j=i+1;j<size;j++)
        {
            // finding the minimum value's index for the swap 
            if(A[i]>A[j])
            {
                min=j;
            }
        }
        // swapping the data here 
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}
int main()
{
    // char Arr[100];
    string Arr[100];
    // float Arr[100];
    // int Aaa[100];
    int n;
    cout<<"enter the array : \n";
    // cin>>ch;


    // declaring the loop 
    for(int i=0;i<n;i++)
    {
        cout<<"enter the "<<i+1<<" :  ";
        cin>>Arr[i];
    }
    n=sizeof(Arr)/sizeof(Arr[0]);

    // calling the selection sort function 


    // selection_sort<int>(Arr,n);
    // selection_sort<char>(Arr,n);
    // selection_sort<float>(Arr,n);
    selection_sort<string>(Arr,n);

    // showing the sorted loop . 
    for (int i = 0; i < n; i++)
    {
        cout<<Arr[i]<<" ";
        /* code */
    }
    return 0;
}
