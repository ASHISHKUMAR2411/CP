#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 10
int A[max];
int rear=-1,front=-1;
void insert(void)
{
    int data;
    if((front==0 && rear==max-1)||(front==rear+1))
    {
        printf("\n overflow");
        return ;
    }
    else if(rear==max-1)
    {
        rear=0;
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear++;
    }
    printf("\n enter the data you want to insert ");
    scanf("%d",&data);
    A[rear]=data;
}
void delete(void)
{
    int temp=0;
    if(front==-1)
    {
        printf("\n underflow ");
        return ;
    }
    else if(front ==rear)
    {
        temp=front;
        front=rear=-1;
    }
    else
    {
        temp=front;
        front++;
    }
    printf("\n the %d is deleted ",A[temp]);
}
void display(void)
{
    if(front==-1)
    {
        printf("\n underflow");
        return ;
    }
    else if(front<=rear)
    {
         printf("\n");
        for(int i=front ; i<=rear;i++)
        {
            printf(" %d ",A[i]);
        }
    }
    else
    {
        printf("\n");
        for(int i=front ;i<max;i++)
        {
            printf("%d ",A[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf(" %d",A[i]);
        }
    }
}
void FRONT(void)
{
    if(front==-1)
    {
        printf("\n underflow");
        return ;
    }
    printf("\n %d is the front value",A[front]);
    
}
void REAR(void)
{
    if(rear==-1 )
    {
        printf("\n underflow");
        return ;
    }
    else
    {
        printf("\n %d is the rear ",A[rear]);
    }

}
int main()
{
    char ch;
    int n;
    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.FRONT");
        printf("\n5.REAR");
        printf("\n6.exit");
        printf("\n");
        label:
        printf("\n enter the choose : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            FRONT();
            break;
            case 5:
            REAR();
            break;
            case 6:
            exit(0);
            break;
            default :
            printf("\n wrong choice :");
            printf("\n enter again :");
            goto label;
            break;
        }
        printf("\n do you want to perform more operation the enter y or Y : ");
        scanf("%c",&ch);
        scanf("%c",&ch);   

    } while (ch=='y'||ch=='Y');
    
}