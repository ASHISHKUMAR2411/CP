#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
int add(int a, int b )
{
    int c;
    c=a+b;
    printf(" \n the addition of two number is %d  ",c);
    return (0);
}
int sub(int a , int b)
{
    int c ;
    if(b>a)
    c=b-a;
    else 
    c=a-b;
    printf(" \n the subtraction of two numbar is %d ",c);
    return(0);
}
int main()
{
    int a, b;
    printf("\nenter the two numbers  ");
    scanf("%d %d",&a,&b);
    add(a,b);
    add(b,a);
    sub(a,b);
    sub(b,a);
    return 0;

}