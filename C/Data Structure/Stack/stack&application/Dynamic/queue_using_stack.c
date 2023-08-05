#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<process.h>
struct stack
{
    int info;
    struct stack *node;
};
struct stack *create(void);
void push(struct stack **p);
void pop(struct stack **p);
void peek(struct stack *p);
void show(struct stack *p);
int isEmpty(struct stack *p);
void queue(struct stack **p, struct stack **q);
int main()
{

}
struct stack *create(void)
{
    int data ;
    struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
    printf("\n enter data to store : ");
    scanf("%d",&data);
    temp->info=data;
    temp->node=NULL;
    return temp;
}
void push(struct stack **p)
{
    int data;
    printf("\n enter the data to push ");
    scanf("%d",&data);
    struct stack *temp=create();
    temp->node=*p;
    *p=temp;
}
void pop(struct stack **p);
void peek(struct stack *p);
void show(struct stack *p);
int isEmpty(struct stack *p);
void queue(struct stack **p, struct stack **q);
