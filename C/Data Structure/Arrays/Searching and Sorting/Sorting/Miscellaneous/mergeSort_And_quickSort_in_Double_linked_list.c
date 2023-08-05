// C program to demostrate the merge and quick sort using double linked list 
// by ASHISH KUMAR 2020kucp1008 

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
struct dll
{

    int data;
    struct dll *front;
    struct dll *back;
};
struct dll *create()
{
    struct dll *temp = (struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data for the head : ");
    scanf("%d", &temp->data);
    temp->back = NULL;
    temp->front = NULL;
}
void insert_forward(struct dll *ptr)
{
    struct dll *pre = ptr;
    while (pre->front != NULL)
    {
        pre = pre->front;
    }
    struct dll *temp = (struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data you want to store :");
    scanf("%d", &temp->data);
    temp->front = NULL;
    temp->back = pre;
    pre->front = temp;
}
void insert_backward(struct dll **ptr)
{
    struct dll *pre = *ptr;
    while (pre->back != NULL)
    {
        pre = pre->back;
    }
    struct dll *temp = (struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data you want to store :");
    scanf("%d", &temp->data);
    temp->front = pre;
    temp->back = NULL;
    pre->back = temp;
    *ptr = pre->back;
}
void insetion_at_given(struct dll **ptr)
{
    struct dll *pre = *ptr;
    int data;
bro:
    printf("\nenter the data where node has to be inserted :");
    scanf("%d", &data);
    struct dll *temp = (struct dll *)malloc(sizeof(struct dll));
    while (pre != NULL)
    {
        if (pre->data == data)
        {
            if (pre == *ptr)
            {
                int choice;
                printf("\n1.for Insert_forward");
                printf("\n2.for Insert_backward");
            lab:
                printf("\n enter your choice :");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("\n enter the data you want to store :");
                    scanf("%d", &temp->data);
                    (pre->front)->back = temp;
                    temp->front = pre->front;
                    pre->front = temp;
                    temp->back = pre;
                    break;
                case 2:
                    insert_backward(&pre);
                    *ptr = pre;
                    break;
                default:
                    printf("\n Wrong Choice ");
                    printf("\n enter your choice again : ");

                    goto lab;
                }
                return;
            }
            int choice;
            printf("\n1.for Insert_forward");
            printf("\n2.for Insert_backward");
        labe:
            printf("\n enter your choice :");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\n enter the data you want to store :");
                scanf("%d", &temp->data);
                if (pre->front == NULL)
                {
                    pre->front = temp;
                    temp->front = NULL;
                    temp->back = pre;
                    return;
                }
                (pre->front)->back = temp;
                temp->front = pre->front;
                pre->front = temp;
                temp->back = pre;
                return;
                break;
            case 2:
                printf("\n enter the data you want to store :");
                scanf("%d", &temp->data);
                (pre->back)->front = temp;
                temp->back = pre->back;
                temp->front = pre;
                pre->back = temp;
                return;
                break;
            default:
                printf("\n Wrong Choice ");
                printf("\n enter your choice again : ");
                goto labe;
            }
        }
        pre = pre->front;
    }
    printf("\n element not found please enter again :");
    goto bro;
}
void display_forward(struct dll *ptr)
{
    struct dll *pre = ptr;
    if (pre == NULL)
    {
        printf("\n there is no data to display : ");
        return;
    }
    while (pre != NULL)
    {
        printf("%d ", pre->data);
        pre = pre->front;
    }
    return;
}
void display_backward(struct dll *ptr)
{
    struct dll *pre = ptr;
    if (pre == NULL)
    {
        printf("\n there is no data to display : ");
        return;
    }
    while (pre->front != NULL)
    {
        pre = pre->front;
    }
    while (pre != NULL)
    {
        printf("%d ", pre->data);
        pre = pre->back;
    }
    return;
}
void deletion_front(struct dll **ptr)
{
    struct dll *pre = *ptr;
    if (*ptr == NULL)
    {
        printf("\n nothing to delete : ");
        return;
    }
    (pre->front)->back = NULL;
    pre = pre->front;
    *ptr = pre;
}
void deletion(struct dll **ptr)
{
    if (ptr == NULL)
    {
        printf("\n nothing to delete : ");
        return;
    }
    struct dll *pre = *ptr;
    int data;
their:
    printf("\nenter the data you want to delete :");
    scanf("%d", &data);
    while (pre != NULL)
    {
        if (pre->data == data)
        {
            if (pre == *ptr)
            {
                deletion_front(ptr);
                return;
            }
            if (pre->front == NULL)
            {
                (pre->back)->front = NULL;
                return;
            }
            (pre->back)->front = pre->front;
            (pre->front)->back = pre->back;
            return;
        }
        pre = pre->front;
    }
    printf("\nelement not found enter again ");
    goto their;
}
void reverse(struct dll **ptr)
{
    struct dll *pre = *ptr, *end = *ptr, *curr = *ptr, *ctr = NULL, *as = NULL;
    while (pre->front != NULL)
    {
        pre = pre->front;
    }
    end = pre;
    while (curr != end)
    {
        as = curr;
        pre->front = curr;
        (pre->front)->back = pre;
        curr = curr->front;
        (pre->front)->front = ctr;
        if (as != *ptr)
        {
            ctr->back = pre->front;
        }
        ctr = pre->front;
    }
    end->back = NULL;
    *ptr = end;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
struct dll *last_node(struct dll *ptr)
{
    while (ptr && ptr->front)
    {
        ptr = ptr->front;
    }
    return ptr;
}
struct dll *partition(struct dll *ptr, struct dll *pre)
{
    int x = pre->data;
    struct dll *i = ptr->back;
    for (struct dll *j = ptr; j != pre; j = j->front)
    {
        if (j->data <= x)
        {
            i = (i == NULL) ? ptr : i->front;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? ptr : i->front;
    swap(&(i->data), &(pre->data));
    return i;
}
void _quickSort(struct dll *l, struct dll *h)
{
    if (h != NULL && l != h && l != h->front)
    {
        struct dll *p = partition(l, h);
        _quickSort(l, p->back);
        _quickSort(p->front, h);
    }
    return;
}
void quick_sort(struct dll *head)
{
    struct dll *h = last_node(head);
    _quickSort(head, h);
    // display_forward(ptr);
    return;
}
struct dll *split(struct dll *head)
{
    struct dll *fast = head, *slow = head;
    while (fast->front && (fast->front)->front)
    {
        fast = (fast->front)->front;
        slow = slow->front;
    }
    struct dll *temp = slow->front;
    slow->front = NULL;
    return temp;
}
struct dll *merge(struct dll *first, struct dll *second)
{
    if (!first)
    {
        return second;
    }
    if (!second)
    {
        return first;
    }
    if ((first->data) < (second->data))
    {
        first->front = merge(first->front, second);
        (first->front)->back = first;
        first->back = NULL;
        return first;
    }
    else
    {
        second->front = merge(first, second->front);
        (second->front)->back = second;
        second->back = NULL;
        return second;
    }
}
struct dll *mergeSort(struct dll *head)
{
    if (!(head) || !(head->front))
    {
        return head;
    }
    struct dll *second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}
int main()
{
    int choice;
    // char ch;
    struct dll *head;
    head = create();
    while (1)
    {
        printf("\n1.for Insertion at tail ");
        printf("\n2.for Insertion at head ");
        printf("\n3.for Insert_at_given_node");
        printf("\n4.for Display");
        printf("\n5.for Display From Back ");
        printf("\n6.Deletion of element ");
        printf("\n7.Reverse the list ");
        printf("\n8.QuickSort");
        printf("\n9.MergeSort");
        printf("\n10.exit");
    label:
        printf("\n enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_forward(head);
            break;
        case 2:
            insert_backward(&head);
            break;
        case 3:
            insetion_at_given(&head);
            break;
        case 4:
            display_forward(head);
            break;
        case 5:
            display_backward(head);
            break;
        case 6:
            deletion(&head);
            break;
        case 7:
            reverse(&head);
            break;
        case 8:
            quick_sort(head);
            break;
        case 9:
            head = mergeSort(head);
            break;

        case 10:
            free(head);
            exit(0);
            break;
        default:
            printf("\n Wrong Choice ");
            printf("\n enter your choice again : ");
            goto label;
        }
    }
    return 0;
}


// sir i have also provided the .exe file in case if the code show error in your system  while running . sir for best experience just run the code 