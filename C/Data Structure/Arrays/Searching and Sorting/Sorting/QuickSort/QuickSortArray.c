// C program to do the analysis on the Quick Sort Algorithm
// by Ashish Kumar 2020kucp1008

/* KNOWING ABOUT QUICK SORT  */

// As Quick Sort is all about Divide and conquer So what it do is that he divide the array and sort it .
// In Quick sort Algorithm Is As Follows
// 1. We select an element as Pivot i.e around which we will divide the array and sort it ,
// 2. selecting a pivot is sometimes what makes it easier to sort ,
//     -> First Method Of Selecting : Choosing The last element as pivot ,which is the most
//        common method .
//     -> Second Method is Selecting Median of the array ,
//     -> Third Method is Selecting the First Element as Pivot
//     -> Fourth Method is selecting any random element as pivot

// 3. Then we find the partition of the array , basically dividing the array such that the pivoted element is somewhat  boundary between the left and right array .

// 4. then applying the same in the left and right and that we bring the sorting in work

/*  NOW ABOUT IT ANALYSIS  */

// ? In Quick Sort we generally do is divide and conquer and behind this scene we follow the technique of partition exchange sort where we pivot one element of the array and then we divide the array into two array and do it recursively that and join them at the end . It is Also a Comparison sort,

// ? It is faster than merge sort and 3 times fatser than Heapsort.

// PROPERTIES OF QUICK SORT
// In Place
// Not Stable
// Time Complexity : O(n^2)      -> worst case
//                   O(n*log(n)) -> best case
//                   O(n*log(n)) -> average case

// Space Complexity: O(n)        -> Worst Naive Approach
//                   O(log(n))   -> Best Approach

//! Algorithm is 
// pseudo code 

//  QUICKSORT(A; p; r)
//  1 if p<r
//  2 q = PARTITION(A; p; r)
//  3 QUICKSORT(A; p; q - 1)
//  4 QUICKSORT(A; q + 1; r)
//  To sort an entire array A, the initial call is QUICKSORT(A; 1; A:length)

// PARTITION.A; p; r/
//     1 x = A[r];
//     2 i = p - 1
//     3 for j = p to r - 1
//     4 if A[j] <= x
//     5 i = i + 1
//     6 exchange A[i] with A[j]
//     7 exchange A[i+ 1] with A[r]
//     8 return i + 1



/* CODE for Quick Sort Implementation  and Then Analyzing them on the basis of the code  */
// HERE we are trying the best implementation of quickSort in ordre to achieve that what we are going is :

// as quick sort is not inplace but part of it is inplace that is partiton function is in place  we can do one thing which is that we can apply recursion to a smaller part this will help in optimisation and speed.

// * Tail call elimination in quick sort make its more better and makes it's complier friendly and it because of that it is also better than merge sort

#include <stdio.h>
#include <stdlib.h>
int *createArray(int *arr, int size)
{
    arr = (int *)malloc(size * sizeof(int));
    return arr;
}

void arrayInsertion(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the element : ");
        scanf("%d", &arr[i]);
    }
}

void swapping(int *value1, int *value2)
{
    int temp;
    temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int Partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        /* code */
        if (arr[j] < pivot)
        {
            i++;
            swapping(&arr[i], &arr[j]);
        }
    }
    swapping(&arr[i + 1], &arr[high]);
    return i + 1;
}

void QuickSort(int *arr, int low, int high)
{
    while (low < high)
    {
        int pi = Partition(arr, low, high);
        // * It will require only O(log(n)) extra space at worst case which is best efficiency for quick sort on the stack where
        if ((pi - low) < (high - pi))
        {
            QuickSort(arr, low, (pi - 1));
            low = pi + 1;
        }
        else
        {
            QuickSort(arr, (pi + 1), high);
            high = pi - 1;
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// main starts here
int main()
{
    // enter the array you want to sort
    int *arr;
    int size;
    printf("Enter the size of array you want to sort : ");
    scanf("%d", &size);
    arr = createArray(arr, size);
    arrayInsertion(arr, size);
    QuickSort(arr, 0, size - 1);
    printf("\n THE SORTED ARRAY IS : \n");
    printArray(arr, size);
    return 0;
}


// why quick sort is better than the merge sort 

// Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite expensive. Allocating and de-allocating the extra space used for merge sort increases the running time of the algorithm.

// Comparing average complexity we find that both type of sorts have O(NlogN) average complexity but the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.

// Most practical implementations of Quick Sort use randomized version. The randomized version has expected time complexity of O(nLogn). The worst case is possible in randomized version also, but worst case doesn’t occur for a particular pattern (like sorted array) and randomized Quick Sort works well in practice.

// Quick Sort is also a cache friendly sorting algorithm as it has good locality of reference when used for arrays.

// Quick Sort is also tail recursive, therefore tail call optimizations is done.