// C program to show the analysis about merge sort using array
// by Ashish Kumar 2020KUCP1008 


// ABOUT MERGE SORT

// * It is also divide and conquer algorithm
// * It divides the array into two half and sort them and then merge them accordingly

// ANALYSIS

// * T(n) = 2T(n/2) + θ(n)
//  Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

// *Auxiliary Space: O(n)
// *Algorithmic Paradigm: Divide and Conquer
// *Sorting In Place: No in a typical implementation
// *Stable: Yes

// *Drawbacks of Merge Sort

//Slower comparative to the other sort algorithms for smaller tasks.
// Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
// It goes through the whole process even if the array is sorted.


// PSEUDO CODE 
// MergeSort
//1. mergeSort(A,low,high)
//2.    if(low>high) 
//3.      return;
//4.    int mid = low + (high - low) / 2;
//5.    calling mergeSort(arr, low, mid);
//6.    calling mergeSort(arr, mid + 1, high);
//7.    calling  merging(arr, low, mid, high);


// Merging 
//1.  merging( arr,low,mid,high)
//2.       size1 = mid - low + 1; // for sub array sizes 
//3.       size2 = high - mid; 
//4.       left[size1],right[size2];
//5.        for (int i = 0; i < size1; i++)
//6.              left[i] = arr[low + i];
//7.        for (int j = 0; j < size2; j++)
//8.              right[j] = arr[mid + 1 + j];
//9.        i = 0, j = 0, k = low;
//10.       while (i < size1 && j < size2)
//11.            if (left[i] < right[j])
//12.                 arr[k] = left[i];
//13.                 i++;
//14.            else
//15.                 arr[k] = right[j]; 
//16.                 j++;
//17.            k++;        
//18.            while (i < size1)
//19.                  arr[k++] = left[i++];    
//20.            while (j < size2)
//21.                  arr[k++] = right[j++];



// It creates an auxiliary array of same size as the given array while sorting which is not in quick sort that why it is considered faster than merge sort

#include <stdio.h>
void merging(int arr[], int low, int mid, int high)
{

    // here we are merging the arrays , in order to achieve that we have to create two array left and right in which we first store the divided array then we will interactively merge the element while comparing them ,
    // here size1 and size2 are the size of the left abd right arrays
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int left[size1], right[size2];

    // here we are storing the element into them
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    // then we are comparing each and every element before merging them into another array arr[] ,
    int i = 0, j = 0, k = low;
    while (i < size1 && j < size2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    //  then we are checking the lefout element in any of the two array and then simply copying them into the main array as they  are already sorted .
    while (i < size1)
    {
        arr[k++] = left[i++];
    }
    while (j < size2)
    {
        arr[k++] = right[j++];
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return; //returns recursively
    }
    // here dividing the array into two equal parts and then recursive doing them again so untill they become single element and then it will simpler to compare and merge them again .
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merging(arr, low, mid, high);
}

// here printing the array

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

// here mains starts

int main()
{
    int arr[100], size;
    printf("\nenter the size of the array : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element : ");
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}
