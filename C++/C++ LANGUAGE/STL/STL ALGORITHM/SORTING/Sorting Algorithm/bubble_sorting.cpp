// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

// Example: 
// First Pass: 
// ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
// ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4 
// ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2 
// ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
// Second Pass: 
// ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
// ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
// ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 ) 
// Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
// Third Pass: 
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
// ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 


// now actual program 

#include<bits/stdc++.h>
using namespace std;
template<class T>
void swapping(T *value1 , T *value2)
{
    T temp ;
    temp = *value1;
    *value1 = *value2 ;
    *value2 = temp;
}
template<class T>
void bubbleSort(T arr[],int size)
{
    T TEMP;
    for(int i=0;i<size;i++)
    {
        for (int  j = 0; j  < size; j++)
        {
            if(arr[i]<arr[j])
            {
                swapping(&arr[i],&arr[j]);
                // TEMP = arr[i];
                // arr[i]= arr[j];
                // arr[j] = TEMP;
            }
            /* code */
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
    int arr[100];
    int size;
    cin>>size;
    for (int  i = 0; i < size; i++)
    {
        cout<<"\nenter the element : ";
        cin>>arr[i];
        /* code */
    }
    bubbleSort<int>(arr,size);
    print<int>(arr,size);
    
}