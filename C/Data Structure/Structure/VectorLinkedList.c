// add two vector 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct vectors
{
    int A[10];
}a,b,*c;
struct vectors *add(struct vectors a,struct vectors b,int n);
int main()
{
    int n,p,q,r,t;
    printf("\n enter the length of the vector ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\n enter the vector %d element : ",i+1);
        scanf("%d",&a.A[i]);
    }
    // printf("\n enter the next length of the vector ");
    // scanf("%d",&p);
    for(int i=0;i<n;i++)
    {
        printf("\n enter the vector %d element : ",i+1);
        scanf("%d",&b.A[i]);
    }
    printf("\n the vector is \n");
    for(int i=0;i<n;i++)
    {
        printf("%2d,",a.A[i]);
    }
    printf("\n the vector is \n");
    for(int i=0;i<n;i++)
    {
        printf("%2d,",b.A[i]);
    }
    // printf("\n enter which position element you want to change ");
    // scanf("%d",&p);
    // printf("\n enter the value you want to replace with %d position ",p);
    // scanf("%d",&q);
    // s.A[p-1]=q;
    // for(int i=0;i<n;i++)
    // {
    //     printf("%2d,",s.A[i]);
    // }
    // printf("\n enter the position you want to multiply with the value  : ");
    // scanf("%d",&r);
    // printf("\n enter the value you want to multiply with %d position  ",r);
    // scanf("%d",&t);
    // s.A[r-1] *= t;
    // for(int i=0;i<n;i++)
    // {
    //     printf("%2d,",s.A[i]);
    // }
    c=add(a,b,n);
    printf("\n the added vector is \n");
    for(int i=0;i<n;i++)
    {
        printf("%2d,",*c->A[i]);
    }
    return 0;
}
struct vectors *add(struct vectors a,struct vectors b,int n)
{
    struct vectors *p;
    for(int i=0;i<n;i++)
    {
        *p->A[i] =a.A[i]+ b.A[i];
    }
    return p;
}