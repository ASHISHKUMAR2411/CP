// C program to find the merge sort using single linked list 
// 2020kucp1008 Ashish Kumar 

// Merge sort is often preferred for sorting a linked list. The slow random-access performance of a linked list makes some other algorithms (such as quicksort) perform poorly. 



// ANALYSIS
// Time Complexity: O(n*log n)
// Space Complexity: O(n*log n)



// Pseudo Code  

// MergeSort(headRef)
// 1) If the head is NULL or there is only one element in the Linked List 
//     then return.
// 2) Else divide the linked list into two halves.  
//       FrontBackSplit(head, &a, &b); /* a and b are two halves */
// 3) Sort the two halves a and b.
//       MergeSort(a);
//       MergeSort(b);
// 4) Merge the sorted a and b (using SortedMerge() discussed here) 
//    and update the head pointer using headRef.
//      *headRef = SortedMerge(a, b);


// Actual Implemetaion of the Merge Sort using linked list 
#include<stdio.h>
#include<stdlib.h>
struct ll
{
    int flag;
    int data ;
    struct ll *next;
};
// function to create the list 
struct ll *create()
{
    int data;
    struct ll *temp=(struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data ");
    scanf("%d",&data);
    temp->data=data;
    temp->flag=0;
    temp->next=NULL;
    return temp;
}

// function to insert new element to the list 
void insert(struct ll *ptr)
{
    struct ll *pre;
    while(ptr!=NULL)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    int data;
    struct ll *temp=(struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->flag=0;
    temp->next=NULL;
    pre->next=temp;
}

// function to delete the element 
void deletion(struct ll *ptr)
{
    int pos,count=0;
    struct ll *pre;
    printf("enter the position to delete : ");
    scanf("%d",&pos);
    if(pos==0)
    {
        printf("\n can't delete this position ");
        return;
    }
    while(ptr!=NULL && count<pos)
    {
        pre=ptr;
        count++;
        ptr=ptr->next;
    }
    pre->next=ptr->next;
}

// function to find the list 
int length(struct ll *ptr)
{
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    // printf("\n%d",count);
    return count;
}

// function to print the list 
void print(struct ll *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}



/* function prototypes */
struct ll* SortedMerge(struct ll* a, struct ll* b);
void FrontBackSplit(struct ll* source,
                    struct ll** frontRef, struct ll** backRef);
 
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct ll** headRef)
{
    struct ll* head = *headRef;
    struct ll* a;
    struct ll* b;
 
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
struct ll* SortedMerge(struct ll* a, struct ll* b)
{
    struct ll* result = NULL;
 
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
void FrontBackSplit(struct ll* source,
                    struct ll** frontRef, struct ll** backRef)
{
    struct ll* fast;
    struct ll* slow;
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
 

int main()
{
    struct ll *head=create();
    int choice,l;
    char ch;
    while(1)
    {
        printf("\n1.Insertion");
        printf("\n2.deletion");
        printf("\n3.Find length");
        printf("\n4.print the list ");
        printf("\n5.MERGE SORT");
        printf("\n6.exit");
        printf("\n");
        label:
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert(head);
            break;
            case 2:
            deletion(head);
            break;
            case 3:
            l=length(head);
            printf("\n%d",l);
            break;
            case 4:
            print(head);
            break;
            case 5:
            MergeSort(&head);
            break;
            case 6:
            exit(0);
            break;
            default : 
            printf("\n you have entered the wrong choice  ");
            goto label;
            break;
        }
    }
    return 0;
}


// why merge sort is better than quick sort as in linked list implementation ?

// In case of linked lists the case is different mainly due to difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory.

// Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time if we are given reference/pointer to the previous node. Therefore merge operation of merge sort can be implemented without extra space for linked lists.

// In arrays, we can do random access as elements are continuous in memory. Let us say we have an integer (4-byte) array A and let the address of A[0] be x then to access A[i], we can directly access the memory at (x + i*4). Unlike arrays, we can not do random access in linked list.

// Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node from the head to i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for quick sort. Merge sort accesses data sequentially and the need of random access is low.