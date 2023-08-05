#include <stdio.h>
// one problem is that we can;t operate once traverse is called
#include <stdlib.h>
#include <string.h>
#include <process.h>
struct stack
{
    int data;
    struct stack *next;
} *top=NULL;
void push(void);
void pop(void);
void traverse(void);
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
    struct stack *p;
    p=(struct stack *)malloc(sizeof(struct stack));
    printf("\n enter the value you want to insert : ");
    scanf("%d",&p->data);
    p->next=top;
    top=p;
}
void pop(void)
{
    struct stack *q;
    int item;
    q=top;
    if(top==NULL)
    {
        printf("\nempty stack");
    }
    else
    {
       item=q->data;
       top=top->next; 
       printf("\n the value deleted is %d ",item);
       free(q);
    }
}
void traverse(void)
{
    struct stack *r;
    r=top;
    
        while(r!=NULL)
        {
            printf("\n data : %d ",r->data);
            r=r->next;
        }
        printf("\n data : %d",r->data);
}

