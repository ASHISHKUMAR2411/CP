#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void exchange(int *p,int *q);
int main()
{
    //exchange two values located at different memory 
    int a=5,b=10,*p,*q,*temp;
    exchange(&a,&b); 
    printf("\n %d %d ",a,b);
}
void exchange(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}