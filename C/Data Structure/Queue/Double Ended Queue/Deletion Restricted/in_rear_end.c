//Dequeue Implimentation 
//Deletion Restriction Through Rear End
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int deque_arr[MAX];
int front=-1;
int rear=-1;
void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_rearEnd();
void display();

int main()
{
  int choice,item;
  while(1)

  {

    printf("1.Insert at the front end\n");
    printf("2.Insert at the rear end\n");
    printf("3.Delete from rear end\n");
    printf("4.Display\n");
    printf("5.Quit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\nInput the element for adding in queue : ");    
                scanf("%d",&item);    
                insert_frontEnd(item);    
                break;
        case 2: printf("\nInput the element for adding in queue : ");    
                scanf("%d",&item);    
                insert_rearEnd(item);    
                break;
        case 3: printf("\nElement deleted from rear end is : %d\n",delete_rearEnd());
                break;
        case 4: display();
                break;
        case 5: exit(1);
                default:
                printf("\nWrong choice\n");
    }
  }
}

//Insertion in Front End
void insert_frontEnd(int item)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("\nQueue Overflow\n");
        return;
    }

    if( front==-1 )
    {
        front=0;
        rear=0;
    }
    
    else if(front==0)
    {
    front=MAX-1;
    }
    
    else
    {
    front=front-1;
    }

    deque_arr[front]=item ;

}

//Insertion in Rear End
void insert_rearEnd(int item)
{
  
  if((front==0 && rear==MAX-1) || (front==rear+1))
  {
    printf("\nQueue Overflow\n");
    return;
  }
  
  if(front==-1)
  {

    front=0;
    rear=0;
  }

  else if(rear==MAX-1)
  {
      rear=0;
  }

  else
  {
    rear=rear+1;
  }
  
  deque_arr[rear]=item ;

}

//Deletion from Rear End

int delete_rearEnd()
{

  int item;
  if(front == -1)
  {
    printf("\nQueue Underflow\n");
    exit(1);

  }

  item=deque_arr[rear];

  if(front==rear)
  {
    front=-1;
    rear=-1;
  }

  else if(rear==0)
  {
    rear=MAX-1;
  }

  else
  {
    rear=rear-1;
  }

  return item;

}


//Display of queue
void display()
{
  int i;
  if(front==-1)
  {
    printf("\nQueue is empty\n");
    return;
  }
  printf("\nQueue elements :\n");
  i=front;
  if( front<=rear )
  {
    while(i<=rear)
    printf("%d ",deque_arr[i++]);
  }
  else
  {
    while(i<=MAX-1)
    printf("%d ",deque_arr[i++]);
    i=0;
    while(i<=rear)
    printf("%d ",deque_arr[i++]);
  }
  printf("\n");
}
