#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
int *fun(int n);
int main()
{
    int n;
    printf("\n enter the element you want in the memory : ");
    scanf("%d",&n);
    int *ptr=fun(n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
    }
    printf("\n%d",ptr);
    free(ptr);
    ptr=NULL;
    printf("\n%d",ptr);
    return 0;
}
int *fun(int n)
{
    int *ptr=(int *)malloc(n*sizeof(int));
    printf("\n enter the %d element : ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
    }
    return ptr;
    // after return we have no access to the function 
    printf("\n %d",n);
    free(ptr);
    ptr=NULL;
    printf("\n%d",ptr);
}