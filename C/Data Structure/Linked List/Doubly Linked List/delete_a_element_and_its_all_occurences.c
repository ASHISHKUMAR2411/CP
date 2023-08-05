// !in this what we have to do is we have given with the number x and we have to find the triplets whose sum is equal to x .
// ? in this we will be having two solution in which one of them is shown here and the other one is used using hash table.
// ? in this we have the two links front and back which is used for linking in the list
// ? insertion at the gievn node is alos available.
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
        // // pre=pre->next;
    }
    end->back = NULL;
    *ptr = end;
    // // print(*ptr);
}
void swap_kth(struct dll **ptr)
{
    // ! in this we have one important thing to note that if we give the number greater than the length of the list or even if the middle of the length od the list, then it will show undizered behaviour , we can solve that by counting length and modulud with the k or we can display an error message of unapproachable behaviour . I hape the one reading will understand.
    int count = 1;
    struct dll *pre = *ptr, *cre = *ptr, *temp = *ptr, *aage = NULL, *piche = NULL, *a = *ptr;
    while (cre->front != NULL)
    {
        cre = cre->front;
        temp = cre;
    }
    int k = 0;
    printf("\n enter the value of the K for the swap  the kth element from the both ends  ");
    scanf("%d", &k);
    while (count < k)
    {
        temp = temp->back;
        pre = pre->front;
        count++;
    }
    if (k == 1)
    {
        (pre->front)->back = temp;
        (temp->back)->front = pre;
        temp->front = pre->front;
        pre->back = temp->back;
        temp->back = NULL;
        pre->front = NULL;
        *ptr = temp;
        return;
    }
    (pre->front)->back = temp;
    (pre->back)->front = temp;
    (temp->back)->front = pre;
    (temp->front)->back = pre;
    aage = pre->front;
    piche = pre->back;
    pre->back = temp->back;
    pre->front = temp->front;
    temp->back = piche;
    temp->front = aage;
    return;
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
void find_sum(struct dll *first, struct dll *last, int data)
{
    // if (first == NULL)
    // {
    //     printf("\n pair not found ");
    //     return;
    // }
    // if (last == NULL)
    // {
    //     printf("\n pair not found ");
    //     return;
    // }
    if ((first->data) <= (last->data))
    {
        if (first == last)
        {
            printf("\n pair not found ");
            return;
        }
        if (((first->data) + (last->data)) > data)
        {
            find_sum(first, last->back, data);
        }
        else if (((first->data) + (last->data)) < data)
        {
            find_sum(first->front, last, data);
        }
        else if (((first->data) + (last->data)) == data)
        {
            printf("\n we found the pair\n the number are :  %d  %d\n the locations are :  %d  %d ", first->data, last->data, first, last);
            find_sum(first->front, last, data);
            return;
        }
        // else
        // {
        //     printf("\n no pair found ");
        //     return;
        // }
    }
    else
    {
        printf("\n pair not found ");
        return;
    }
}
void finding_pair(struct dll *ptr)
{
    // !in this condition is that we will be given with the list which is sorted
    // !for that we can find the lenght of the
    // mergeSort(ptr);
    if (ptr == NULL)
    {
        printf("\nno element to perform the operation");
        return;
    }
    quick_sort(ptr);
    int data;
    struct dll *pre = ptr;
    while (pre->front != NULL)
    {
        pre = pre->front;
    }
    printf("\nenter the given sum to find the pair ");
    scanf("%d", &data);
    find_sum(ptr, pre, data);
    return;
}
void insertion_sorting(struct dll **ptr)
{
    // !in this we have to take care of one thing which is that we have to give a inserted node and the node with value to be added to the linked list and the list after addition of the node is also sorted
    // ? we can do this by using two method that is calling insertion and sorting subsequently and respectivily , but this will ruin the question which it want to teach ,

    struct dll *temp = (struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data you want to store and sort :");
    scanf("%d", &temp->data);
    temp->back = NULL;
    temp->front = NULL;
    if (*ptr == NULL)
    {
        printf("\n no node till now so it will become the first node ");
        *ptr = temp;
        return;
    }
    struct dll *pre = *ptr;
    while (((pre->front)->data) < (temp->data))
    {

        pre = pre->front;
        if (pre->front == NULL)
        {
            pre->front = temp;
            temp->back = pre;
            temp->front = NULL;
            return;
        }
    }
    if (pre->data == ((*ptr)->data))
    {
        temp->front = pre;
        pre->back = temp;
        temp->back = NULL;
        *ptr = temp;
        return;
    }
    else
    {
        temp->front = pre->front;
        (pre->front)->back = temp;
        temp->back = pre;
        pre->front = temp;
        return;
    }
}
void deletion_position(struct dll **ptr)
{
    //! there is only one problem that is we cannot able to delete the last node
    int count = 1, k = 1;
    printf("\nenter the position you want to delete  : ");
    scanf("%d", &k);
    if (k == 1)
    {
        *ptr = (*ptr)->front;
        (*ptr)->back = NULL;
        return;
    }
    struct dll *pre;
cout:
    pre = *ptr;
    count = 1;
    while (pre != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        pre = pre->front;
    }
    if (pre == NULL)
    {
        printf("\n these number of nodes are not present so finding the modulus by total number : ");
        k = k % count;
        goto cout;
    }
    pre->front = (pre->front)->front;
    (pre->front)->back = pre;
    return;
}
void triplets(struct dll *first, struct dll *middle, struct dll *last, int data)
{
    // ! in this we can only find the only one triplets
    if (first == last)
    {
        printf("\nelement not found : ");
        return;
    }
    if (middle == last)
    {
        printf("\nelement not found ");
        return;
    }
    if (first == middle)
    {
        printf("\nelement not found ");
        return;
    }
    if (middle == (last->back))
    {
        if (((first->data) + (middle->data) + (last->data)) == data)
        {
            printf("\nWe found the tripplets : %d %d %d \n thier address is : %d %d %d ", first->data, middle->data, last->data, first, middle, last);
            if ((first->front) == middle)
            {
                return;
                ;
            }
            else if ((middle->back) == first)
            {
                triplets(first, middle->front, last, data);
            }
            else
            {
                triplets(first, middle->back, last, data);
            }
            return;
        }
        else if (((first->data) + (middle->data) + (last->data)) < data)
        {
            triplets(first->front, middle, last, data);
        }
        else if (((first->data) + (middle->data) + (last->data)) > data)
        {
            triplets(first, (middle->back), last->back, data);
        }
    }
    if (middle == (first->front))
    {
        if (((first->data) + (middle->data) + (last->data)) == data)
        {
            printf("\nWe found the tripplets : %d %d %d \n thier address is : %d %d %d ", first->data, middle->data, last->data, first, middle, last);
            if ((middle->front) == last)
            {
                return;
            }
            else if ((middle->back) == first)
            {
                triplets(first, last->back, last, data);
            }
            else
            {
                triplets(first, middle->front, last, data);
            }
            return;
        }
        else if (((first->data) + (middle->data) + (last->data)) > data)
        {
            triplets(first, middle, last->back, data);
        }
        else if (((first->data) + (middle->data) + (last->data)) < data)
        {
            triplets(first->front, (middle->front), last, data);
        }
    }
    if (((first->data) + (middle->data) + (last->data)) == data)
    {
        printf("\nWe found the tripplets : %d %d %d \n thier address is : %d %d %d ", first->data, middle->data, last->data, first, middle, last);
        // if ((middle->front) == last)
        // {
        //     triplets(first, middle->back, last, data);
        // }
        // else if ((middle->back) == first)
        // {
        //     triplets(first, middle->front, last, data);
        // }
        // else
        // {
        //     triplets(first, middle->back, last, data);
        //     triplets(first, middle->front, last, data);
        // }
        return;
    }
    else if (((first->data) + (middle->data) + (last->data)) > data)
    {
        triplets(first, middle->back, last, data);
    }
    else if (((first->data) + (middle->data) + (last->data)) < data)
    {
        triplets(first, middle->front, last, data);
    }
    else
    {
        printf("\nelement not found : ");
        return;
    }
}
void count_triplets(struct dll *ptr)
{
    if (ptr == NULL && ptr->front == NULL)
    {
        printf("\n no triplet found 🤦‍♂️");
        return;
    }
    int x;
    printf("\nenter the value of x for which triplet sum is to find : ");
    scanf("%d", &x);
    if (((ptr->data) + ((ptr->front)->data) + (((ptr->front)->front)->data)) == x)
    {
        printf("\n triplet found : %d  %d  %d \n the address is :  %d  %d  %d ", (ptr->data), ((ptr->front)->data), (((ptr->front)->front)->data), ptr, ptr->front, (ptr->front)->front);
        return;
    }
    struct dll *first = ptr, *middle = ptr, *last = ptr;
    while (last && last->front)
    {
        middle = middle->front;
        if (((last->front)->front) == NULL)
        {
            last = last->front;
            break;
        }
        last = (last->front)->front;
    }
    triplets(first, middle, last, x);
    return;
}
void removing_duplicate(struct dll *ptr)
{
    struct dll *pre = ptr, *ctr = ptr, *cre = ptr;
    while (pre != NULL)
    {
        ctr = pre->front;
        while (ctr != NULL)
        {
            if ((pre->data) == (ctr->data))
            {
                if (ctr->front == NULL)
                {
                    cre->front = NULL;
                    removing_duplicate(ptr);
                    return;
                }
                else
                {
                    cre->front = (cre->front)->front;
                    (cre->front)->back = cre;
                    removing_duplicate(ptr);
                    return;
                }
            }
            cre = ctr;
            ctr = ctr->front;
        }
        pre = pre->front;
    }
    return;
}
struct dll *predelete = NULL;
void element_deletion(struct dll **ptr, int data)
{
    if ((*ptr)->data == data)
    {
        if ((*ptr)->front == NULL)
        {
            predelete->front = NULL;
            return;
        }
        else
        {
            predelete->front = (*ptr)->front;
            (predelete->front)->back = predelete;
            return;
        }
    }
    while ((*ptr) != NULL)
    {
        if ((*ptr)->data == data)
        {
            element_deletion(ptr, data);
            return;
        }
        predelete = (*ptr);
        (*ptr) = (*ptr)->front;
    }
}
void remove_element(struct dll **ptr)
{
    struct dll *pre = *ptr, *precedor = *ptr;
    if (pre == NULL)
    {
        return;
    }
    int data_to_delete;
    printf("\nenter the data you want to delete : ");
    scanf("%d", &data_to_delete);
    if ((*ptr)->data == data_to_delete)
    {
        removing_duplicate(*ptr);
        (*ptr) = (*ptr)->front;
        (*ptr)->back = NULL;
        return;
    }
    while (pre != NULL)
    {
        if (pre->data == data_to_delete)
        {
            element_deletion(ptr, data_to_delete);
            return;
        }
        precedor = pre;
        pre = pre->front;
    }
    printf("\n no such element found : \n please enter again with different element : \n ");
}
int main()
{
    int choice;
    // char ch;
    struct dll *head;
    head = create();
    while (1)
    {
        printf("\n1.for Insert_forward");
        printf("\n2.for Insert_backward");
        printf("\n3.for Insert_st_given_node");
        printf("\n4.for Display_forward");
        printf("\n5.for Display_backward");
        printf("\n6.Deletion");
        printf("\n7.Reverse");
        printf("\n8Swapping_Kth_node_from_both_end");
        printf("\n9.QuickSort");
        printf("\n10.MergeSort");
        printf("\n11.Finding_Pair_for_the_given_sum");
        printf("\n12.Sorting_while_insertion");
        printf("\n13.Deletion_at_position");
        printf("\n14.Find_Tripplets_of_Given_Sum");
        printf("\n15.Removing_Duplicates");
        printf("\n16.Remove_Element");
        printf("\n17.exit");
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
            swap_kth(&head);
            break;
        case 9:
            quick_sort(head);
            break;
        case 10:
            head = mergeSort(head);
            break;
        case 11:
            finding_pair(head);
            break;
        case 12:
            quick_sort(head);
            insertion_sorting(&head);
            break;
        case 13:
            deletion_position(&head);
            break;
        case 14:
            count_triplets(head);
            break;
        case 15:
            removing_duplicate(head);
            break;
        case 16:
            remove_element(&head);
            break;
        case 17:
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