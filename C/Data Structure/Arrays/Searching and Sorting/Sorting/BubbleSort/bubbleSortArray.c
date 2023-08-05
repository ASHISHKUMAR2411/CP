// C program to Analysis the Bubble Sorting Technique using Array 

// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

// Generally Bubble Sort function always runs O(n^2) time even if the array is sorted. It can be optimized by stopping the algorithm if inner loop didn’t cause any swap. 



// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

// Sorting In Place: Yes
// Stable: Yes

// Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.

// pseude code is 
// bubblesort(A,n)
// 1. for(1:A.length)
// 2.    for(1:A.length-1)
// 3.       if(A[i]>A[i+1])
// 4.         exchange A[i] with A[i+1]



#include<stdio.h>
#include<stdbool.h>

// swapping
void swapping(int *value1 , int *value2)
{
    int temp ;
    temp = *value1;
    *value1 = *value2 ;
    *value2 = temp;
}

// bubble sorting(modidifed)
void bubbleSort(int arr[],int size)
{
    // variable to check whether the function is already sorted or not 
    bool swapped = false;
    for(int i=0;i<size-1;i++)
    {
        swapped = false;
        // here swapped is used to check the sorting if already sorted then it stops the process , which saves time complexity for further checking which is a good thing . 
        for (int  j = 0; j  < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swapping(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
        {
            break;
        }
    }
}

// for printing the array 
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

// here main starts 
int main()
{
    int arr[100];
    int size;
    scanf("%d",&size);
    for (int  i = 0; i < size; i++)
    {
        printf("\nenter the element : ");
        scanf("%d",&arr[i]);
    }
    printf("Sorted Array :  \n");
    bubbleSort(arr,size);
    print(arr,size);
}