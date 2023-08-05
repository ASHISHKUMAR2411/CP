//  in this we will lear the linked list using the double pointer 
#include<stdio.h>
#include<stdlib.h>
struct cl
{
    int data ;
    struct cl *front ;
    struct cl *back;
};
struct cl *create()
{
    int data ;
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    printf("\n enter the data :");
    scanf("%d",&data);
    temp->data=data;
    temp->front=temp;
    temp->back=temp;
    return temp;
}
struct cl *insert(struct cl *ptr)
{
    int data;
    struct cl *pre=ptr;
    while(pre->front!=ptr)
    {
        pre=pre->front;
    }
    struct cl *temp=(struct cl *)malloc(sizeof(struct cl));
    printf("\n enter the dta to insert : ");
    scanf("%d",&data);
    temp->data=data;
    pre->front=temp;
    temp->back=pre;
    temp->front=ptr;
    ptr->back=temp;
    return ptr;
}
void display(struct cl *ptr)
{
    printf("\n");
    struct cl *pre=ptr,*cre=ptr;
    while(pre->back!=ptr)
    {
        printf("%d ",pre->data);
        pre=pre->back;
        if(pre->back==ptr)
        {
            printf("%d ",pre->data);
        }
    }
    printf("\n");
    while(cre->front!=ptr)
    {
        printf("%d ",cre->data);
        cre=cre->front;
        if(cre->front==ptr)
        {
            printf("%d ",cre->data);
        }
    }
    if(ptr->front==ptr->back)
    {
        printf("%d ",ptr->data);
        return;
    }
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