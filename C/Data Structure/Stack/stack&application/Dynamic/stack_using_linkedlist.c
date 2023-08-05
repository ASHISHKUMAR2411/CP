// stack implementation using linked list 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<process.h>
struct STACK
{
    int information;
    struct STACK *node;
};
struct STACK *Create(int data);
void push(struct STACK **p,int data);
void pop(struct STACK **p);
int IsEmpty(struct STACK *p);
void peek(struct STACK *p);
void Print(struct STACK *p);

int main()
{
    int data,choice;
    char ch;
    struct STACK *ptr=NULL;
    printf("\n enter data for the first node to create : ");
    scanf("%d",&data);
    ptr=Create(data);
    do
    {
        printf("\n 1 Push : ");
        printf("\n 2 Pop : ");
        printf("\n 3 Print : ");
        printf("\n 4 Peek : ");
        printf("\n 5 Exit : ");
        label:
        printf("\n Enter Your Choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("\n enter the data to push : ");
            scanf("%d",&data);
            push(&ptr,data);
            break;
            case 2: 
            pop(&ptr);
            break;
            case 3:
            Print(ptr);
            break;
            case 4:
            peek(ptr);
            break;
            case 5:
            exit(0);
            break;
            default: 
            printf("\n you have enetered Wrong Choice : ");
            goto label;
            break;
        }
        printf("\n Do you want to perform more operation : ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    return 0;
}
struct STACK *Create(int data)
{
   struct STACK *newNode=(struct STACK *)malloc(sizeof(struct STACK));
   newNode->information=data;
   newNode->node=NULL;
   return newNode;
}
void push(struct STACK **p,int data)
{
    struct STACK *temp=Create(data);
    temp->node=*p;
    *p=temp;
    printf("\n %d data is pushed",data);
}
void pop(struct STACK **p)
{
    int popped;
     if(IsEmpty(*p))
     {
         printf("\n no element to pop");
         return ;
     }
     struct STACK *temp=*p;
     *p=(*p)->node;
     popped=temp->information;
     printf("\n %d is poped ",popped);
}
int IsEmpty(struct STACK *p)
{
    return !p;
}    
void peek(struct STACK *p)
{
    if(IsEmpty(p))
    {
        printf("\n NO element left ");
        return;
    }
    printf("\n %d",p->information);
}
void Print(struct STACK *p)
{
    if(IsEmpty(p))
    {
        printf("\n No element to print ");
        return 0;
    }
    struct STACK *temp=p;
    while(temp!=NULL)
    {
        printf("%d ",temp->information);
        temp=temp->node;
    }
}