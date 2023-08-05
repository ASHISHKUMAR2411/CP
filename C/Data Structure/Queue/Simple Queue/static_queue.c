#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Queue
{
    int front,rear,size;
    unsigned max;
    int *arr;
};
struct Queue *create(unsigned max)
{
    struct Queue *que=(struct Queue *)malloc(sizeof(struct Queue));
    que->max=max;
    que->front=que->size=0;
    que->rear=que->max-1;
    que->arr=(int *)malloc(que->max*sizeof(int));
    return que;
}
int isFULL(struct Queue *p )
{
    return (p->size==p->max);
}
int isEmpty(struct Queue *p)
{
    return (p->size==0);
}
void insert(struct Queue *p)
{
    int data;
    if(isFULL(p))
    {
        printf("\n cannot insert as it is overflow ");
        return;
    }
    printf("\n enter the data you want to insert : ");
    scanf("%d",&data);
    p->rear=(p->rear+1)%p->max;
    p->arr[p->rear]=data;
    p->size=p->size+1;
    printf("%d inserted ",data);
}
void delete(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n underflow ");
        return ;
    }
    int item = p->arr[p->front];
    p->front=(p->front+1)%p->max;
    p->size=p->size-1;
    printf("\n %d is removed ",item);
}
void front(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n underflow");
        return;
    }
    printf("%d value is front  ",p->arr[p->front]);
}
void rear(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n underflow ");
        return ;
    }
    printf("%d value is at rear ",p->arr[p->rear]);
}
void display(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n nothing t display ");
        return ;
    }
    else
    {
        for(int i=p->front;i<=p->rear;i++)
        {
            printf("%d ",p->arr[i]);
        }
    }
}
int main()
{
    unsigned d;
    int choice;
    char ch;
    printf("\n enetr the size of the queue you want : ");
    scanf("%d",&d);
    struct Queue *p=create(d);
    do{
        printf("\n1. for Insert ");
        printf("\n2. for Delete ");
        printf("\n3. for Front ");
        printf("\n4. for Rear ");
        printf("\n5. for Display ");
        printf("\n6. for Exit ");
        label:
        printf("\n enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            insert(p);
            break;
            case 2:
            delete(p);
            break;
            case 3: 
            front(p);
            break;
            case 4:
            rear(p);
            break;
            case 5:
            display(p);
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("\n you have entered the wrong choice ");
            printf("\n please try again : ");
            goto label;
            break;
        }
        printf("\n you want to perform more operation then enter y or Y  ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}
