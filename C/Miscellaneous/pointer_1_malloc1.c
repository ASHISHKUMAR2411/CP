#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int main()
{
    int i,n;
    printf("\n enter the value of n i.e how many values you want to store  : ");
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("\n unablr to point to the memory ");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        printf("\n enter the interger we want to store ");
        scanf("%d",ptr+i);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
    }
    free(ptr);
    ptr=NULL;
    return 0;
}