#include <stdio.h>
#include <stdlib.h>
#define A 50

int Array[A];
int front = -1;
int rear = -1;
void insertfrom_frontEnd(int x);
void insertfrom_rearEnd(int x);
int deletefrom_rearEnd();
void display();

int main()
{
  int choice, x;
  while (1)

  {

    printf("1.Insert at the front end\n");
    printf("2.Insert at the rear end\n");
    printf("3.Delete from rear end\n");
    printf("4.Display\n");
    printf("5.Quit\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\nInput the element for adding in queue at font end: ");
      scanf("%d", &x);
      insertfrom_frontEnd(x);
      break;
    case 2:
      printf("\nInput the element for adding in queue at rear end : ");
      scanf("%d", &x);
      insertfrom_rearEnd(x);
      break;
    case 3:
      printf("\nElement deleted from rear end is : %d\n", deletefrom_rearEnd());
      break;
    case 4:
      display();
      break;
    case 5:
      exit(1);
    default:
      printf("\nWrong choice\n");
    }
  }
}

//Adding an element from front side
void insertfrom_frontEnd(int x)
{
  if (front == 0 && rear == A - 1)
  {
    printf("\nQueue is full\n");
    return;
  }
  if(front==-1)
  {
    front = 0;
    rear = 0;
  }

  else if (front == 0 && rear<A-1)
  {
    int temp=rear;
    while(temp>=0)
    {
       Array[temp+1]=Array[temp];
       temp--;
    }
    rear=rear+1;
    front=0;
  }
  else if(front!=0)
  {
    front = front - 1;
  }
  Array[front] = x;
}

//Adding an element from rear end
void insertfrom_rearEnd(int x)
{

  if (front == 0 && rear == A - 1)
  {
    printf("\nQueue is full\n");
    return;
  }

  if (front == -1)
  {

    front = 0;
    rear = 0;
  }


  else
  {
    rear = rear + 1;
  }

  Array[rear] = x;
}

//Deletion from Rear End

int deletefrom_rearEnd()
{

  int x;
  if (front == -1)
  {
    printf("\nQueue is empty\n");
    exit(1);
  }

  x = Array[rear];

  if (front == rear)
  {
    front = -1;
    rear = -1;
  }



  else
  {
    rear = rear - 1;
  }

  return x;
}

//Display of queue
void display()
{
  int i;
  if (front == -1)
  {
    printf("\nQueue is empty\n");
    return;
  }
  printf("\nQueue elements :\n");
  i = front;
  if (front <= rear)
  {
    while (i <= rear)
      printf("%d ", Array[i++]);
  }
  else
  {
    while (i <= A - 1)
      printf("%d ", Array[i++]);
    i = 0;
    while (i <= rear)
      printf("%d ", Array[i++]);
  }
  printf("\n");
}