// 2020KUCP1008
// Ashish Kumar
// Implementing Deletion from Front end and Restricted from Rear End 
// Double Ended Queue using array
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Queue
{
    int front,rear,size;
    unsigned max;
    int *arr;
};
struct Queue *create(unsigned max);
int isFULL(struct Queue *p );
int isEmpty(struct Queue *p);
void insert_rear(struct Queue *p);
void insert_front(struct Queue *p);
void delete_front(struct Queue *p);
void front(struct Queue *p);
void rear(struct Queue *p);
void display(struct Queue *p);
int main()
{
    unsigned d;
    int choice;
    char ch;
    printf("\n enter the size of the queue you want : ");
    scanf("%d",&d);
    struct Queue *p=create(d);
    do{
        printf("\n1. for Insert_Front ");
        printf("\n2. for Insert_Rear ");
        printf("\n3. for Delete_Front ");
        printf("\n4. for Front_Value ");
        printf("\n5. for Rear_Value ");
        printf("\n6. for Display ");
        printf("\n7. for Exit ");
        label:
        printf("\n enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            insert_front(p);
            break;
            case 2: 
            insert_rear(p);
            break;
            case 3:
            delete_front(p);
            break;
            case 4: 
            front(p);
            break;
            case 5:
            rear(p);
            break;
            case 6:
            display(p);
            break;
            case 7:
            exit(0);
            break;
            default:
            printf("\n you have entered the wrong choice ");
            printf("\n please try again : ");
            goto label;
            break;
        }
        printf("\n\n you want to perform more operation \nthen enter y or Y  ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    return 0;
}
// creating array
struct Queue *create(unsigned max)
{
    struct Queue *que=(struct Queue *)malloc(sizeof(struct Queue));
    que->max=max;
    que->front=-1;
    que->size=0;
    que->rear=-1;
    que->arr=(int *)malloc((que->max)*sizeof(int));
    return que;
}
// checking array full condition
int isFULL(struct Queue *p )
{
    return (p->size==p->max);
}
// checking empty condition
int isEmpty(struct Queue *p)
{
    return (p->size==0);
}
// inserting element at rear end
void insert_rear(struct Queue *p)
{
    if(p->front==-1)
    {
        p->front=0;
        p->rear=0;
    }
    else if(p->rear==(p->max-1))
    {
        if(isFULL(p))
        {
            printf("\n cannot insert as it is overflow ");
            return;
        }
        printf("\n insertion cannot be done ");
        return;
    }
    else
    {
        p->rear=p->rear+1;
    }
    
    int data;
    
    printf("\n enter the data you want to insert : ");
    scanf("%d",&data);
    p->arr[p->rear]=data;
    p->size=p->size+1;
    printf("%d inserted ",data);
}

// inserting element at front end
void insert_front(struct Queue *p)
{
    if(p->rear==(p->max-1) && p->front==0)
    {
        printf("\n No more element can be inserted \n Overflow!!! ");
        return;
    }
    if(p->front==-1)
    {
        p->front=0;
        p->rear=0;
    }
    else if(p->front==0 && p->rear<(p->max-1))
    {
        int temp=p->rear;
        while(temp>=0)
        {
            p->arr[temp+1]=p->arr[temp];
            temp=temp-1;   
        }
        p->rear=p->rear+1;
        p->front=0;
    }
    else if(p->front!=0)
    {
        p->front=p->front-1;
    }
    int data;
    printf("\n enter data you want to insert : ");
    scanf("%d",&data);
    p->arr[p->front]=data;
    p->size=p->size+1;
    printf("%d inserted at the front ",data);

}
// deleting element from front 
void delete_front(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n underflow ");
        return ;
    }
    if(p->front==-1)
    {
        printf("\n no element to delete :");
        return ;
    }
    else if(p->front==(p->max))
    {
        p->rear=-1;
        p->front=-1;
        p->size=0;
        printf("\n no more element to delete");
        return;
    }
    int item = p->arr[p->front];
    p->front=p->front+1;
    p->size=p->size-1;
    printf("\n %d is removed ",item);
}
// checking front element and displaying
void front(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n underflow");
        return;
    }
    if(p->front==-1)
    {
        printf("\n no element in the front ");
        return;
    }
    printf("%d value is front  ",p->arr[p->front]);
}
// checking rear end and displaying 
void rear(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n underflow ");
        return ;
    }
    printf("%d value is at rear ",p->arr[p->rear]);
}
// displaying whole array
void display(struct Queue *p)
{
    if(isEmpty(p))
    {
        printf("\n nothing to display ");
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
