// QUICK SORT
// ARRAY
// ANALYSIS

// O(n^2)      -> worst
// O(n*log(n)) -> best
// O(n*log(n)) -> average

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// function to print array elements
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// main function
int main()
{
    int data[] = {8, 7, 2, 1, 0, 9, 6};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);

    // perform quicksort on data
    quickSort(data, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}




// QUICK SORT
// LINKED LIST 
// ANALYSIS 
// The worst case time complexity of this algorithm is O(n^2) 
// and the average case complexity is O(nlogn).

// code 
// C++ program for Quick Sort on Singly Linled List
#include <stdio.h>
#include<stdlib.h>

/* a node of the singly linked list */
struct Node {
	int data;
	struct Node* next;
};

/* A utility function to insert a node at the beginning of
* linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

// Returns the last node of the list
struct Node* getTail(struct Node* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end,
					struct Node** newHead,
					struct Node** newEnd)
{
	struct Node* pivot = end;
	struct Node *prev = NULL, *cur = head, *tail = pivot;

	// During partition, both the head and end of the list
	// might change which is updated in the newHead and
	// newEnd variables
	while (cur != pivot) {
		if (cur->data < pivot->data) {
			// First node that has a value less than the
			// pivot - becomes the new head
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot
		{
			// Move cur node to next of tail, and change
			// tail
			if (prev)
				prev->next = cur->next;
			struct Node* tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the
	// current list, pivot becomes the head
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node
	(*newEnd) = tail;

	// Return the pivot node
	return pivot;
}

// here the sorting happens exclusive of the end node
struct Node* quickSortRecur(struct Node* head,
							struct Node* end)
{
	// base condition
	if (!head || head == end)
		return head;

	struct Node *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be
	// updated by the partition function
	struct Node* pivot
		= partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur
	// for the left part.
	if (newHead != pivot) {
		// Set the node before the pivot node as NULL
		struct Node* tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last node of the left half to
		// pivot
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(struct Node** headRef)
{
	(*headRef)
		= quickSortRecur(*headRef, getTail(*headRef));
	return;
}

// Driver code
int main()
{
	struct Node* a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	printf("Linked List before sorting \n");
	printList(a);

	quickSort(&a);

	printf( "Linked List after sorting \n");
	printList(a);

	return 0;
}





// MERGE SORT
// ARRAY
// ANALYSIS
//  O(n*log(n)) -> worst
//  O(n*log(n)) -> best
//  O(n*log(n)) -> average


// *Auxiliary Space: O(n)
// *Algorithmic Paradigm: Divide and Conquer
// *Sorting In Place: No in a typical implementation
// *Stable: Yes




// *Drawbacks of Merge Sort

//Slower comparative to the other sort algorithms for smaller tasks.
// Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
// It goes through the whole process even if the array is sorted.



#include<stdio.h>
void merging(int arr[], int low,int mid,int high)
{
    int size1 = mid - low +1 ;
    int size2 = high - mid;
    int left[size1] , right[size2];
    for(int i =0 ;i<size1;i++)
    {
        left[i] = arr[low+i]; 
    }
    for(int j = 0 ;j<size2;j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int i =0 ,j =0 , k = low;
    while(i<size1 && j< size2)
    {
        if(left[i]<right[j])
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
    while(i<size1)
    {
        arr[k++] = left[i++];
    }
    while(j<size2)
    {
        arr[k++] = right[j++];
    }
}
void mergeSort(int  arr[], int low , int high )
{
     if(low>=high){
        return;//returns recursively
    }
    int mid =  low + (high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merging(arr,low,mid,high);
}

void print(int arr[], int size )
{
    for(int i =0;i<size;i++)
    {
        printf("%d ",&arr[i]);
    }
}
int main()
{
    int arr[100],size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        printf("Enter the element : ");
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,size-1);
    print(arr,size);
    return 0;
}

// MERGE SORT
// LINKED LIST 
// ANALYSIS
// Time Complexity: O(n*log n)
// Space Complexity: O(n*log n)

// code
// C code for linked list merged sort
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* function prototypes */
struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Node** headRef)
{
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

/* Function to print nodes in a given linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* res = NULL;
	struct Node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	/* Sort the above created Linked List */
	printf("\n list before sorting \n");
    printList(a);
    MergeSort(&a);

    printf("\nSorted Linked List is: \n");
    printList(a);
	return 0;
}





