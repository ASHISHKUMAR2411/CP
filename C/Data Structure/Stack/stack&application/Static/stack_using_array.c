#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct STACK
{
    int top;
    unsigned capacity;
    int *array;
};
struct STACK *CREATESTACK(unsigned capacity)
{
    struct STACK *s=(struct STACK *)malloc(sizeof(struct STACK));
    s->capacity=capacity;
    s->top=-1;
    s->array=(int *)malloc(s->capacity*sizeof(int));
    return s;
}
int FULL(struct STACK *s)
{
    return s->top == s->capacity-1;
}
int EMPTY(struct STACK *s)
{
    return s->top == -1 ;
}
void PUSH(struct STACK *s,int element)
{
    if(FULL(s))
    {
        printf("\n stack overflow , cannot add ");
        return;
    }
    s->array[++s->top]=element;
    printf(" %d element is pushed into the stack ",element);
}
void POP(struct STACK *s)
{
    if(EMPTY(s))
    {
        printf("\n no more element to pop : ");
        return ;
    }
    printf("\n %d is poped from the stack  ",s->array[s->top]);
    s->top -= 1;
}
void PEEK(struct STACK *s)
{
    if(EMPTY(s))
    {
        printf("\n no element found ");
        return ;
    }
    printf("\n the top element is : %d",s->array[s->top]);

}
int main()
{
    struct STACK *s;
    int n,i=0,ele;
    char ch;
    scanf("%d",&n);
    s=CREATESTACK(n);
    do
    {
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. EXIt");
        choice:
        printf("\n enter your choice : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            printf("\n enter the elemenet to push : ");
            scanf("%d",&ele);
            PUSH(s,ele);
            break;
            case 2: POP(s);
            break;
            case 3: PEEK(s);
            break;
            case 4: exit(0);
            break;
            default: printf("\n you have entered the wrong choice : ");
            goto choice;
        }
        printf("\n do you want to perform more operaton : ");
        scanf("%c",&ch);
        scanf("%c",&ch);

    }while(ch=='y' || ch=='Y');
    
}