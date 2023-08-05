#include<stdio.h>
#include<stdlib.h>
int main()
{
    //  reverse the array of integer using pointer 
    int A[10],n,*p;
    printf("\n enter the number of element in the array : ");
    scanf("%d",&n);
    printf("\n enter he array : ");
    for(int i=0;i<n;i++)
    {
        printf("\n enter the  %d element : ",i+1);
        scanf("%d",&A[i]);
    }
    p=&A[n-1];
    for( int i=0 ;i<n;i++)
    {
        printf("%d ",*p);
        p--;
    }
    return 0;
}