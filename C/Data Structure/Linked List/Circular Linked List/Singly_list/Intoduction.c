//  in this we will see how we can we can create the singly list nd make a circular linked lists
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
struct cl
{
    int data;
    struct cl *node;
};
struct cl *create()
{
    int data;
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    printf("\n enter the data ");
    scanf("%d",&data);
    temp->data=data;
    temp->node=temp;
    return temp;
}
struct cl *insert(struct cl *ptr)
{
    int data;
    struct cl *pre=ptr;
    while(pre->node!=ptr)
    {
        pre=pre->node;
    }
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    printf("\n enter the data you want to insert  : ");
    scanf("%d",&data);
    temp->data=data;
    pre->node=temp;
    temp->node=ptr;
    return ptr;
}
void display(struct cl *ptr)
{
    struct cl *ctr=ptr;
    printf("\n");
    if(ptr->node==ptr)
    {
        printf("%d ",ptr->data);
        return;
    }
    while(ctr->node!=ptr)
    {
        printf("%d ",ctr->data);
        ctr=ctr->node;
    }
    printf("%d ",ctr->data);
    return;
}
int main()
{
    int choice;
    char ch;
    struct cl *head;
    head=create();
    do
    {
        printf("\n1.for Insert");
        printf("\n2.for Display");
        printf("\n3.exit");
        label:
        printf("\n enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            head=insert(head);
            break;
            case 2: 
            display(head);
            break;
            case 3:
            free(head);
            exit(0);
            break;
            default: 
            printf("\n Wrong Choice ");
            printf("\n enter your choice again : ");
            goto label;
        }
        printf("\n Do you want to perform more options : ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    } while (ch=='y'||ch=='Y');
    return 0;
}
