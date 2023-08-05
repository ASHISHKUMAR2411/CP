// A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order in sorted output as they appear in the input array to be sorted.

// Note: Subscripts are only used for understanding the concept.

// Input : 4A 5 3 2 4B 1
// Output : 1 2 3 4B 4A 5

// Stable Selection Sort would have produced
// Output : 1 2 3 4A 4B 5

// Selection sort works by finding the minimum element and then inserting it in its correct position by swapping with the element which is in the position of this minimum element. This is what makes it unstable.




// C++ program for modifying Selection Sort
// so that it becomes stable.
// #include <iostream>
// using namespace std;

// void stableSelectionSort(int a[], int n)
// {
     // Iterate through array elements
//     for (int i = 0; i < n - 1; i++)
//     {

         // Loop invariant : Elements till a[i - 1]
         // are already sorted.

        // Find minimum element from
        // arr[i] to arr[n - 1].
//         int min = i;
//         for (int j = i + 1; j < n; j++)
//             if (a[min] > a[j])
//                 min = j;

       // Move minimum element at current i.
//         int key = a[min];
//         while (min > i)
//         {
//             a[min] = a[min - 1];
//             min--;
//         }
//         a[i] = key;
//     }
// }

// void printArray(int a[], int n)
// {
//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
//     cout << endl;
// }

 // Driver code
// int main()
// {
//     int a[] = { 4, 5, 3, 2, 4, 1 };
//     int n = sizeof(a) / sizeof(a[0]);
//     stableSelectionSort(a, n);
//     printArray(a, n);
//     return 0;
// }





// #include <bits/stdc++.h>
// #include <string.h>
// using namespace std;
// int main()
// {
//     char str[20][20],dummy[20];
//     int n,k=0,min=0;
//     cout<<"\nenter the number of element in the string : ";
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cout<<"\neneter the string : ";
//         cin>>str[i];
//     }
//     for(int i=0;i<n-1;i++)
//     {
//         min =i;
//         for(int j=i+1;j<n;j++)
//         {
//             k=0;
//             if(str[min][k]>=str[j][k])
//             {
//                 min=j;
//             }
//             else if(str[min][k]==str[j][k])
//             {
//                 while(str[min][k]==str[j][k])
//                 {
//                     k++;
//                 }
//                 if(str[min][k]>=str[j][k])
//                 { 
//                     min=j;
//                 }
//             }
//         }
//         strcpy(dummy,str[i]);
//         strcpy(str[i],str[min]);
//         strcpy(str[min],dummy);
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<str[i]<<" ";
//     }
//     return 0;
// }






// C++ program for implementation of selection sort 
#include <bits/stdc++.h>
using namespace std;

// The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.

void swap(int &xp, int &yp) 
{ 
    int temp = xp; 
    xp = yp; 
    yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 

    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] <= arr[min_idx]) 
            min_idx = j; 

        // Swap the found minimum element with the first element 
        swap(arr[min_idx], arr[i]); 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

// Driver program to test above functions 
int main() 
{ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
}

// Time Complexity: O(n^2) as there are two nested loops.

// Auxiliary Space: O(1)