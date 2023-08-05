// to find the sum of the aray using ointer
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int A[20],m,sum=0,*p;
    printf("\n enter the number of element you want in the array :");
    scanf("%d",&m);
    printf("\n now enter the array");
    for(int i=0;i<m;i++)
    {
        printf("\n enter the  next element : ");
        scanf("%d",&A[i]);
    }
    printf("\n the array you entered is ");
    for(int i=0;i<m;i++)
    {
        printf("%d ",A[i]);
    }
    p=A;
    for(int i=0;i<m;i++)
    {
        sum+=*p++;
    }
    printf("\n the sum is %d",sum);
    return 0;
}