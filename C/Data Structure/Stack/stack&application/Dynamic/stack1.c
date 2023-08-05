// we are using array in stack ,
// generally stack are the data type where we are generally using it like array but the difference is that we have to follow execution from one side of the stack
// that is FILO i.e first in last out  LIFO i.e last in first  out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
void push(void);
void pop(void);
void traverse(void);
int stack[10], p;
int top = -1;
//this is our stack where we have to take care of the size
int main()
{
    int n;
    char ch;

    do
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. TRAVERSE");
        printf("\n4. EXIT");
        printf("\nenter your choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;
        }

    } while (n != 4);
}
void push(void)
{
    int item;
    if (top == 9)
    {
        printf("\n stack overflow ");
    }
    else
    {
        printf("\n enter the item you want to push/insert :");
        top += 1;
        scanf("%d", &item);
        stack[top] = item;
    }
}
void pop(void)
{
    int item;
    if (top >= 0)
    {
        item = stack[top];
        top -= 1;
        printf("%d deleted from the stack :", item);
    }
    else
    {
        printf("\n Stack underflow/empty");
    }
}
void traverse(void)
{
    if (top >= 0)
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
    else
    {
        printf("\n stack empty ");
    }
}
