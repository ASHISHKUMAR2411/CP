#include<stdio.h>
#include<stdlib.h>
struct node
{
    int information;
    struct node *next;
};
void printflist(struct node *ptr);
void print(struct node *ptr);
void insertionFirst(struct node **ptr);
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    head->information=1;
    head->next=second;
    second->information=2;
    second->next=third;
    third->information=3;
    third->next=NULL;
    printflist(head);
    print(head);
    insertion(&head);
    printflist(head);
    print(head);
    return 0;
}
void printflist(struct node *ptr)//method 1
{
    do
    {
        printf("\n%d ",ptr->information);
        ptr=ptr->next;
    }while(ptr->next!=NULL);
    printf("\n%d ",ptr->information);
    
}
void print(struct node *ptr)//method 2
{
    while(ptr=NULL)
    {
        printf("\n%d ",ptr->information);
        ptr=ptr->next;    
    }
}
void insertionFirst(struct node **ptr)
{
    // at the beginning 
    struct node *insert=(struct node *)malloc(sizeof(struct node));
    printf("\n enter the element you want to insert ");
    insert->information=0;
    insert->next=*ptr;
    *ptr=insert;
}