// 1/1+1/2+1/3+1/4.......1/n
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n ,i;
    float sum=0.0,f;
    printf("\n enter the number of elements in the series given above \t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        f=(float)i;
        sum += 1/f;
    }
    printf("\n the sum is: %f",sum);
    return 0;
}