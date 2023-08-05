// in this we have the two links front and back which is used for linking in the list
// insertion at the gievn node
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
    struct dll *pre = *ptr, *ctr = *ptr;
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
        // pre=pre->next;
    }
    end->back = NULL;
    *ptr = end;
    // print(*ptr);
}
int main()
{
    int choice;
    char ch;
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
        printf("\n8.exit");
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