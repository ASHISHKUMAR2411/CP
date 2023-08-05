// C program for the  introduction of sorting
// by ASHISH KUMAR 2020kucp1008

//  Efficiency of an algorithm depends on two parameters:

//* 1. Time Complexity

//* 2. Space Complexity

//* 1. Time Complexity:-
// Time Complexity: Time Complexity is defined as the number of times a particular instruction set is executed rather than the total time is taken. It is because the total time taken also depends on some external factors like the compiler used, processor’s speed, etc.


//* 2. Space Complexity:-
// Space Complexity: Space Complexity is the total memory space required by the program for its execution.

// One important thing here is that in spite of these parameters the efficiency of an algorithm also depends upon the nature and size of the input.



//! in this introduction we will also discuss everything about the divide and conquer(DAC) algorithm and how it is used in computer science .



//* 1. Introduction To DAC
// *2. Algorithm under that .
// *3. Recurrsion relation with DAC
// *4. Problem using DAC technique .


//* 1. Introduction To DAC
//  In this we have divide where we divide the problem into many other small problem we face and then we conquer by solving each of the problem step by step , then at the last we combine the solution


// *2. Algorithm under that .
// ?here we will just write their names ..
// 1. Quicksort
// 2. Merge Sort
// 3. CLosest PAir of Points
// 4. Strassen's Algoritm
// 5. Cooley-Tukey Fast Fourier Transform .
// 6. Karatsuba Algoritm for fast multiplication
// 7. classical algorithm .


// SORTING
// IN this analysis we will come across many algorithm techniques one by one .
// which are
// 1. Quick Sort
// 2. Merge Sort
// 3. Bubble Sort
// 4. Selection Sort
// 5. Insertion Sort


// SOME TERMINOLOGY BEFORE GOING TO ACTUAL SORTING

// ? What is in-place sorting?

// An in-place sorting algorithm uses constant extra space for producing the output (modifies the given array only). It sorts the list only by modifying the order of the elements within the list.
// For example, Insertion Sort and Selection Sorts are in-place sorting algorithms as they do not use any additional space for sorting the list and a typical implementation of Merge Sort is not in-place, also the implementation for counting sort is not in-place sorting algorithm.

// ? What is stable sorting?

// When equal elements are indistinguishable, such as with integers, or more generally, any data where the entire element is the key, stability is not an issue. Stability is also not an issue if all keys are different.
// Some Sorting Algorithms are stable by nature, such as Bubble Sort, Insertion Sort, Merge Sort, Count Sort etc.


// ? What are Internal and External Sortings?

// When all data that needs to be sorted cannot be placed in-memory at a time, the sorting is called external sorting. External Sorting is used for massive amount of data. Merge Sort and its variations are typically used for external sorting. Some external storage like hard-disk, CD, etc is used for external storage.
// When all data is placed in-memory, then sorting is called internal sorting.

// WHAT is stable ?
// A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order in sorted output as they appear in the input array to be sorted.

// Note: Subscripts are only used for understanding the concept.

// Input : 4A 5 3 2 4B 1
// Output : 1 2 3 4B 4A 5

// Stable Selection Sort would have produced
// Output : 1 2 3 4A 4B 5
