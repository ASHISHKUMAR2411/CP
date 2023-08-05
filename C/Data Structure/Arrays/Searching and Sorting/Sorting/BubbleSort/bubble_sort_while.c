#include<stdio.h>
int main()
{
    // bubble sorting 1D array ascending order using while
    int A[20], n;
    printf("\nenter the number of elemnts in  array  ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\n enter the %d element of the array  \t  ",i+1);
        scanf("%d",&A[i]); 
    }
    int temp=0,flag=1;
    while(flag==1)
    {
        flag=0;
        for(int j=0;j<n-1;j++)
        { 
           if(A[j]>A[j+1])
           {
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
               flag=1;
           }
        }
    }   
   
   printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
   return 0;
}