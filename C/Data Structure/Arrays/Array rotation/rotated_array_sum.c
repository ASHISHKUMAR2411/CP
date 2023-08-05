// this is another method for finding the sum of a[i]*i max 
// this is using pivot . here we are finding the pivot point and pivot point can only be found at the sorted or rotated array .
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],n,j,k,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[(i+1)%n])
        {
              j=i;
              break;
        }
    }
    k=n-1-j; // this is to find the difference of the pivot with the last element index
    for(int i=0;i<n;i++)
    {
         sum += ((i+k)%n)*a[i];
    }
    printf("\n maximum sum is : %d",sum);

} 