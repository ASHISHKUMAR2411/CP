// ! this tree is called ternary because the each node has three children one is left ,one is rigth and the third is middle and that is reson why it is alllled the ternary tree.
#include <stdio.h>
#include <stdlib.h>
struct tt
{
    int data;
    struct tt *left;
    struct tt *middle;
    struct tt *right;
};
struct tt *create();
void insert(struct tt *ptr);
void insert_left(struct tt *ptr);
void insert_middle(struct tt *ptr);
void insert_right(struct tt *ptr);
void display_right(struct tt *ptr);
void display_middle(struct tt *ptr);
void display_left(struct tt *ptr);
void display(struct tt *ptr, int level);
void display_all(struct tt *ptr);
void print_tabs(int number);
void print_left(struct tt *ptr);
void print_middle(struct tt *ptr);
void print_right(struct tt *ptr);
int main()
{
    struct tt *head = create();
    int choice = 0;
    while (1)
    {
        printf("\n1.Insert where you choice");
        printf("\n2.Insert_left");
        printf("\n3.Insert_middle");
        printf("\n4.Insert_right");
        printf("\n5.Display_All");
        printf("\n6.Print current left Value");
        printf("\n7.Print currrent middle Value");
        printf("\n8.Print current right Value");
        printf("\n9.Display only Left Value");
        printf("\n10.Display only Middle Value");
        printf("\n11.Display only Right Value ");
        printf("\n12.Exit");
    logo:
        printf("\nenter your choose :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(head);
            break;
        case 2:
            insert_left(head);
            break;
        case 3:
            insert_middle(head);
            break;
        case 4:
            insert_right(head);
            break;
        case 5:
            display_all(head);
            break;
        case 6:
            print_left(head);
            break;
        case 7:
            print_middle(head);
            break;
        case 8:
            print_right(head);
            break;
        case 9:
            display_left(head);
            break;
        case 10:
            display_middle(head);
            break;
        case 11:
            display_right(head);
            break;
        case 12:
            free(head);
            exit(0);
            break;
        default:
            printf("\nwrong choice : ");
            printf("\nenter again when asked :");
            goto logo;
            break;
        }
    }
}
struct tt *create()
{
    struct tt *temp = (struct tt *)malloc(sizeof(struct tt));
    printf("\nenter the data you want to as the root of the tree : ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->middle = NULL;
    temp->right = NULL;
}
void insert(struct tt *ptr)
{
    struct tt *ctr = ptr;
    int choice;
choi:
    printf("\n enter your choice for insert :");
    printf("\n1. for left and \n2. for middle \n3.Right :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insert_left(ctr);
        break;
    case 2:
        insert_middle(ctr);
        break;
    case 3:
        insert_right(ctr);
        break;
    default:
        printf("\n wrong choice :");
        goto choi;
        break;
    }
}
void insert_left(struct tt *ptr)
{
    struct tt *pre = ptr;
    if (pre->left != NULL)
    {
        printf("\nwe have left branch now we will go inside it and check for the space and sk you again where you want to insert ");
        insert(pre->left);
    }
    else
    {
        struct tt *temp = (struct tt *)malloc(sizeof(struct tt));
        if (temp != NULL)
        {
            int info;
            printf("\n enter the data you want to insert : ");
            scanf("%d", &info);
            temp->data = info;
            temp->left = NULL;
            temp->middle = NULL;
            temp->right = NULL;
            pre->left = temp;
            return;
        }
        else
        {
            printf("\n meemory not allocated for insertion ");
            return;
        }
    }
}
void insert_middle(struct tt *ptr)
{
    struct tt *pre = ptr;
    if (pre->middle != NULL)
    {
        printf("\nwe have middle  branch now we will go inside it and check for the space and ask you again where you want to insert ");
        insert(pre->middle);
    }
    else
    {
        struct tt *temp = (struct tt *)malloc(sizeof(struct tt));
        if (temp != NULL)
        {
            int data;
            printf("\n enter the data you want to insert : ");
            scanf("%d", &data);
            temp->data = data;
            temp->left = NULL;
            temp->middle = NULL;
            temp->right = NULL;
            pre->middle = temp;
            return;
        }
        else
        {
            printf("\n meemory not allocated for insertion ");
            return;
        }
    }
}
void insert_right(struct tt *ptr)
{
    struct tt *pre = ptr;
    if (pre->right != NULL)
    {
        printf("\nwe have right  branch now we will go inside it and check for the space and sk you again where you want to insert ");
        insert(pre->right);
    }
    else
    {
        struct tt *temp = (struct tt *)malloc(sizeof(struct tt));
        if (temp != NULL)
        {
            int data;
            printf("\n enter the data you want to insert : ");
            scanf("%d", &data);
            temp->data = data;
            temp->left = NULL;
            temp->middle = NULL;
            temp->right = NULL;
            pre->right = temp;
            return;
        }
        else
        {
            printf("\n meemory not allocated for insertion ");
            return;
        }
    }
}
void display_right(struct tt *ptr)
{
    struct tt *pre = ptr;
    while (pre->right != NULL)
    {
        printf("%d ", pre->data);
        pre = pre->right;
    }
    printf("%d ", pre->data);
}
void display_left(struct tt *ptr)
{
    struct tt *pre = ptr;
    while (pre->left != NULL)
    {
        printf("%d ", pre->data);
        pre = pre->left;
    }
    printf("%d ", pre->data);
}
void display_middle(struct tt *ptr)
{
    struct tt *pre = ptr;
    while (pre->middle != NULL)
    {
        printf("%d ", pre->data);
        pre = pre->middle;
    }
}
void display(struct tt *ptr, int level)
{
    if (ptr == NULL)
    {
        print_tabs(level);
        printf("----<empty>----\n");
        return;
    }
    print_tabs(level);
    printf(" Value = %d\n", ptr->data);
    print_tabs(level);
    printf("left\n");
    display(ptr->left, level + 1);
    print_tabs(level);
    printf("middle\n");
    display(ptr->middle, level + 1);
    print_tabs(level);
    printf("right\n");
    display(ptr->right, level + 1);
    print_tabs(level);
    printf("done\n");
}
void display_all(struct tt *ptr)
{
    display(ptr, 0);
}
void print_tabs(int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("\t");
    }
}
void print_left(struct tt *ptr)
{
    if (ptr->left == NULL)
    {
        printf("\n no value to display empty this side");
        return;
    }
    else
        printf("%d\n", (ptr->left)->data);
}
void print_middle(struct tt *ptr)
{
    if (ptr->middle == NULL)
    {
        printf("\n no value to display empty this side");
        return;
    }
    else
        printf("%d\n", (ptr->middle)->data);
}
void print_right(struct tt *ptr)
{
    if (ptr->right == NULL)
    {
        printf("\n no value to display empty this side");
        return;
    }
    else
        printf("%d\n", (ptr->right)->data);
}