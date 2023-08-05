#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
     // to print even number between 1 to 100;
     for(int i=1;i<100;i++)
     {
         if(i%2==0)
         {
             printf("\n%d",i);
         }
     }
     return 0;
}