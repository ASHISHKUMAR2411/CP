#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    // fibonacci series
    int A[100],n;
    printf("\n enter the no of term you want to see in the fibonaaci series  :");
    scanf("%d",&n);
    A[0]=1;
    A[1]=1;
    printf("\n%d\n%d",A[0],A[1]);
    for(int i=2;i<n;i++)
    {
        A[i]=A[i-1]+A[i-2];
        printf("\n %d",A[i]);
    }
    return 0;

}