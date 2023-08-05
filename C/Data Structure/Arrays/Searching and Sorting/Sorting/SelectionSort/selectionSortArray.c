// C program to discuss about the selection sorting in array 

// The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

// 1) The subarray which is already sorted.
// 2) Remaining subarray which is unsorted.

// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.


// ANALYSIS 
// Time Complexity : O(n*n)      -> worst case
//                   O(n*n)      -> best case
//                   O(n*n)      -> average case

// Space Complexity: O(1)

// Selection sort works by finding the minimum element and then inserting it in its correct position by swapping with the element which is in the position of this minimum element. This is what makes it unstable.

// Algorithm 
// 





// ACTUAL CODE FOR THE IMPLEMENTATION 


#include<stdio.h>

// The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.

void swap(int *value1, int *value2) 
{ 
    int temp = *value1; 
    *value1 = *value2; 
    *value2 = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, minimum_index; 

    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        minimum_index = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] <= arr[minimum_index]) 
            minimum_index = j; 

        // Swap the found minimum element with the first element 
        swap(&arr[minimum_index], &arr[i]); 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
    printf("%d ",&arr[i]); 
    printf("\n");
} 

// Driver program to test above functions 
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
    selectionSort(arr, size); 
    printf("Sorted array: \n"); 
    printArray(arr, size); 
    return 0; 
}