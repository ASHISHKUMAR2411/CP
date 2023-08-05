// C program for the analysis of the quick sort using the linked list
// ASHISH KUMAR

// ANALYSIS
// The worst case time complexity of this algorithm is O(n^2)
// and the average case complexity is O(nlogn).

// Quicksort can be implemented for Linked List only when we can pick a fixed point as the pivot (like the last element in the above implementation). Random QuickSort cannot be efficiently implemented for Linked Lists by picking random pivot.

// if single linked lists are used, merge sort and quick sort have the same average running time: O(n logn).
// As compared to array we have list where
// we don't actually swap the values like array , here we reposition the list by links
// as array random access was possible with index but in single linked list we have cannot do that we have to traverse the list every single time .

// in this we don't actually do partition we just changes thier link to the next node which is a good think as compared to array
//  PSEUDO CODE

// 1.   quickSort( **headRef
// 2.       (*headRef) = quickSortRecur(*headRef, getTail(*headRef));

// 1. *quickSortRecur(*head,*end)
// 2.     if (!head || head == end)
// 3.         return head;
// 4.     *newHead = NULL, *newEnd = NULL;
// 5.     * pivot = partition(head, end, &newHead, &newEnd);
// 6.     if (newHead != pivot)
// 7.         struct ll* tmp = newHead;
// 8.      while (tmp->next != pivot)
// 9.            tmp = tmp->next;
// 10.     tmp->next = NULL;
// 11.     newHead = quickSortRecur(newHead, tmp);
// 12.     tmp = getTail(newHead);
// 13.     tmp->next = pivot;
// 14.     pivot->next = quickSortRecur(pivot->next, newEnd);
// 15.     return newHead;

#include <stdio.h>
#include <stdlib.h>
struct ll
{
    int flag;
    int data;
    struct ll *next;
};
// function to create the list
struct ll *create()
{
    int data;
    struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
    printf("Lets Create Head of the Linked list First : \n")
        printf("\n enter the number for Head");
    scanf("%d", &data);
    temp->data = data;
    temp->flag = 0;
    temp->next = NULL;
    return temp;
}

// function to insert new element to the list
void insert(struct ll *ptr)
{
    struct ll *pre;
    while (ptr != NULL)
    {
        pre = ptr;
        ptr = ptr->next;
    }
    int data;
    struct ll *temp = (struct ll *)malloc(sizeof(struct ll));
    printf("\n enter the data : ");
    scanf("%d", &data);
    temp->data = data;
    temp->flag = 0;
    temp->next = NULL;
    pre->next = temp;
}

// function to delete the element
void deletion(struct ll *ptr)
{
    int pos, count = 0;
    struct ll *pre;
    printf("enter the position to delete : ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        printf("\n can't delete this position ");
        return;
    }
    while (ptr != NULL && count < pos)
    {
        pre = ptr;
        count++;
        ptr = ptr->next;
    }
    pre->next = ptr->next;
}

// function to find the list
int length(struct ll *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    // printf("\n%d",count);
    return count;
}

// function to print the list
void print(struct ll *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Returns the last node of the list
struct ll *getTail(struct ll *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot
struct ll *partition(struct ll *head, struct ll *end, struct ll **newHead, struct ll **newEnd)
{
    struct ll *pivot = end;
    struct ll *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
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
            struct ll *tmp = cur->next;
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
struct ll *quickSortRecur(struct ll *head, struct ll *end)
{
    // base condition
    if (!head || head == end)
        return head;

    struct ll *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    struct ll *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct ll *tmp = newHead;
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
void quickSort(struct ll **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

int main()
{
    struct ll *head = create();
    int choice, l;
    char ch;
    while (1)
    {
        printf("\n List of Operations: ");
        printf("\n1.Insertion");
        printf("\n2.deletion");
        printf("\n3.Find length");
        printf("\n4.print the list ");
        printf("\n5.quick_sort");
        printf("\n6.exit");
        printf("\n");
    label:
        printf("\n enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(head);
            break;
        case 2:
            deletion(head);
            break;
        case 3:
            l = length(head);
            printf("\n%d", l);
            break;
        case 4:
            print(head);
            break;
        case 5:
            quickSort(&head);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n you have entered the wrong choice  ");
            goto label;
            break;
        }
    }
    return 0;
}

// SIR best experience of the code is to just run it , also shared the .exe file in case if this code does not run in your system