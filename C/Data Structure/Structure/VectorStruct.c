// to manipulate on vector a array with integer 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct vectors
{
    int A[10];
}s;
int main()
{
    int n,p,q,r,t;
    printf("\n enter the length of the vector ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\n enter the vector %d element : ",i+1);
        scanf("%d",&s.A[i]);
    }
    printf("\n the vector is \n");
    for(int i=0;i<n;i++)
    {
        printf("%2d,",s.A[i]);
    }
    printf("\n enter which position element you want to change ");
    scanf("%d",&p);
    printf("\n enter the value you want to replace with %d position ",p);
    scanf("%d",&q);
    s.A[p-1]=q;
    for(int i=0;i<n;i++)
    {
        printf("%2d,",s.A[i]);
    }
    printf("\n enter the position you want to multiply with the value  : ");
    scanf("%d",&r);
    printf("\n enter the value you want to multiply with %d position  ",r);
    scanf("%d",&t);
    s.A[r-1] *= t;
    for(int i=0;i<n;i++)
    {
        printf("%2d,",s.A[i]);
    }
    return 0;
}