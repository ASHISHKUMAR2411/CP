#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[100],i,count1=0,count2=0;
    printf("\n enter the set of number from where you want to take out negative numbers ");
    printf("\n enter 0 to stop entering the number ");
    for(i=0;i<100;i++)
    {
        printf("\n enter the %d number\t",i+1);
        scanf("%d",&A[i]);
        if(A[i]==0)
        break;
            
        else if(A[i]<0)
        {
            printf("\n %d",A[i]);
            count1++;
        }
        else
        {
            count2++;
        }
    }
    printf("\n the no of positive number is\t%d\n the no of negative numbers is\t%d",count2,count1);
    return 0;
}