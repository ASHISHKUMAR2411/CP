#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
int main()
{
    int n;
    char ch[1];
    printf("\n enter  the number of integer  ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("\n the memory is not allocated : ");
        exit (0);
    }
    for(int i=0;i<n;i++)
    {
        printf("\n entee the integer : ");
        scanf("%d",ptr+i);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
    }
    ptr=(int *)realloc(ptr,2*n*sizeof(int));
    if(ptr==NULL)
    {
        printf("\n the memory is not allocated : ");
        exit (0);
    }
    for(int i=n;i<2*n;i++)
    {
        printf("\n enter the next integer : ");
        scanf("%d",ptr+i);
    }
    for(int i=0;i<2*n;i++)
    {
        printf("%d ",*(ptr+i));
    }
    free(ptr);
    ptr=NULL;
    return 0;

}
