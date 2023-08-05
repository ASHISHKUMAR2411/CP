// in this we have the two links front and back which is used for linking in the list 
// uses of such type linked list is that here the list can be traverse at point and at  any direction which makes it easier for its execution .
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct dll
{

    int data;
    struct dll *front;
    struct dll *back;
};
struct dll *create()
{
    struct dll *temp=(struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data for the head : ");
    scanf("%d",&temp->data);
    temp->back=NULL;
    temp->front=NULL;
}
void insert_forward(struct dll *ptr)
{
    struct dll *pre=ptr;
    while(pre->front!=NULL)
    {
        pre=pre->front;
    }
    struct dll *temp=(struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data you want to store :");
    scanf("%d",&temp->data);
    temp->front=NULL;
    temp->back=pre;
    pre->front=temp;
}
void insert_backward(struct dll **ptr)
{
    struct dll *pre=*ptr;
    while(pre->back!=NULL)
    {
        pre=pre->back;
    }
    struct dll *temp=(struct dll *)malloc(sizeof(struct dll));
    printf("\n enter the data you want to store :");
    scanf("%d",&temp->data);
    temp->front=pre;
    temp->back=NULL;
    pre->back=temp;
    *ptr=pre->back;
}
void display_forward(struct dll *ptr)
{
    struct dll *pre=ptr;
    if(pre==NULL)
    {
        printf("\n there is no data to display : ");
        return;
    }
    while(pre!=NULL)
    {
        printf("%d ",pre->data);
        pre=pre->front;
    }
}void display_backward(struct dll *ptr)
{
    struct dll *pre=ptr;
    if(pre==NULL)
    {
        printf("\n there is no data to display : ");
        return;
    }
    while(pre->front!=NULL)
    {
        pre=pre->front;
    }
    while(pre!=NULL)
    {
        printf("%d ",pre->data);
        pre=pre->back;
    }
}
int main()
{
    int choice;
    char ch;
    struct dll *head;
    head=create();
    while(1)
    {
        printf("\n1.for Insert_forward");
        printf("\n2.for Insert_backward");
        printf("\n3.for Display_forward");
        printf("\n4.for Display_backward");
        printf("\n5.exit");
        label:
        printf("\n enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            insert_forward(head);
            break;
            case 2: 
            insert_backward(&head);
            break;
            case 3: 
            display_forward(head);
            break;
            case 4: 
            display_backward(head);
            break;
            case 5:
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