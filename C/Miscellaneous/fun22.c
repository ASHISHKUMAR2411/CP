#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    // finding prime or not
    int n,count=0;
    printf("\n enter the number \t :");
    scanf("%d",&n);
    for(int i=n;i>=1;i--)
    { 
        if(n%i==0)
        {
            count++;
        }

    }
    if(count==2)
    {
        printf("\n %d number is prime ",n);
    }
    else
    {
        printf("\n %d number is not prime ",n);
    }
    return 0;

}