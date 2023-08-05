// ? In Quick Sort we generally do is divide and conquer and behind this scene we follow the technique of partition exchange sort where we pivot one element of the array and then we divid the aray into two array and do it recurivesly that and jpin them at the end . It is Also a Comparison sort, 

// ? It is faster than merge sort and 3 times fatser than Heapsort.


// In Place
// Not Stable
// Time Complexity : O(n^2)      -> worst
//                   O(n*log(n)) -> best
//                   O(n*log(n)) -> average

// Space Complexity: O(n)        -> Worst Naive Approach
//                   O(log(n))   -> Best Approach

//! Algorithm is 


//? QUICKSORT(A; p; r)
//* 1 if p<r
//* 2 q = PARTITION(A; p; r)
//* 3 QUICKSORT(A; p; q - 1)
//* 4 QUICKSORT(A; q + 1; r)
//* To sort an entire array A, the initial call is QUICKSORT(A; 1; A:length) 

//?PARTITION.A; p; r/
//*    1 x = A[r];
//*    2 i = p - 1
//*    3 for j = p to r - 1
//*    4 if A[j] <= x
//*    5 i = i + 1
//*    6 exchange A[i] with A[j]
//*    7 exchange A[i+ 1] with A[r]
//*    8 return i + 1

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
int Partition(T arr[],int low ,int high)
{
    T pivot = arr[high];
    int i = low -1;
    for (int j = low; j <= high-1; j++)
    {
        /* code */
        if(arr[j]<pivot)
        {
            i++;
            swapping(arr[i],arr[j]);
        }
    }
    swapping(arr[i+1],arr[high]);
    return i+1 ;
}

template<class T>
void quickSort(T arr[], int low , int high)
{
    if(low<high)
    {
        int pivotPoint = Partition<T>(arr,low,high);
        quickSort(arr,low,pivotPoint-1);
        quickSort(arr,pivotPoint+1,high);
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
    quickSort<string>(arr,0,size);
    // print<int>(arr,size);
    print<string>(arr,size);
    // print<char>(arr,size);
}
